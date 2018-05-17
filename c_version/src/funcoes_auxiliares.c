/*
 * funcoes_auxiliares.c
 *
 *  Created on: 30/08/2012
 *      Author: gabriel
 */

#include "includes.h"

/*
 * Quebra uma string em um vetor de strings.
 * Adiciona o 0 no final do vetor de strings, ou seja, ela adiciona um elemento
 * ao vetor de saída.
 */
const char ** splitString(char *str, const char *delimitador) {

	/* Vamos contar o total de palavras de str */
	const char *ptr;
	int total = 0;
	for ( ptr=str; ; ptr++ ) {
		if ( *ptr == ' ')
			++total;
		else if ( *ptr == '\0') {
			++total;
			break;
		}
	}
	/*
	 * Até aqui foi o total de palavras de str.
	 * Agora vamos adicionar mais um espaço, para o 0 terminador.
	 */
	total++;

	/* Agora podemos começar a trabalhar */
	int c=0;		/* Índice dentro do vetor de strings */
	char *cmd;		/* Cada uma das strings do vetor */

	/*
	 * Agora vamos alocar memória para tudo isso
	 * Temos: (total de palavras, incluindo o terminador) x tamanho de um char *.
	 */
	const char **args = malloc ( total * sizeof(char *) );
	if ( args == NULL ) {
		mensagem_erro("Erro alocando memória!");
		_exit(-1);
	}

	/* Ok, vamos pegar a parimeira parte de str, a cabeça. */
	cmd=strtok(str,delimitador);
	/* Enquanto houver partes, vamos separá-las em novas strings no vetor */
	while (cmd != NULL) {
		/* Alocamos memória para a string */
		args[c] = (const char *) malloc (strlen(cmd));
		/* Copiamos a parte encontrada para a nova string alocada */
		strcpy((char *)args[c],cmd);
		/* Para cada nova string, avançamos o índice */
		c++;
		/* E verificamos se ainda há alguma coisa */
		cmd = strtok(NULL,delimitador);
	}

	/*
	 * Aproveitando que agora o índice parou depois da última parte, vamos
	 * adicionar o NULL para finalizar a cadeia de strings
	 */
	args[c] = 0;

	/* E devolver o vetor para o feliz usuário */
	return (args);
}


/*
 * Alocar membros.
 * Esta função aloca memória para os membros de uma estrutura
 */
char * initCharBuffer(const char *_buffer) {

	char *retorno;
	retorno = (char *) malloc (strlen(_buffer));
	if ( retorno == NULL )
		mensagem_erro("Não foi possível alocar memória.");

	return retorno;

}

void inicializarGuitarra(GuitarraPtr guit) {
    guit->numeroTrastes = 0;                        /* Número de trastes da escala */
    guit->alturaPonte = 0;                          /* Altura da ponte */
    guit->alturaEscala = 0;                         /* Altura da escala na junta braço x corpo */
    guit->compEscala = 0;                           /* Comprimento da escala usada */
    guit->distEscalaPonte = 0;                      /* Distância do final da escala até à ponte (saddles) */
    guit->espacoNut = 0;                            /* Espaço entre as cordas externas, no nut */
    guit->espacoPonte = 0;                          /* Espaço entre as cordas externas, na ponte */
    guit->limiteQueda = _CONSTANTE_CAIR_DA_ESCALA;  /* Limite para que as cordas não caiam da escala */
    guit->nutFimEscala = 0;                         /* Distância do nut ao fim da escala */
}

/*
 * Liberar memória.
 * Esta função libera a memória alocada para as estruturas *_info
 */
void liberarGuitarra(GuitarraPtr guit) {
    free(guit);
}

/*
 * Esta função executa um processo usando execvp().
 * Ela recebe um comando e um vetor de strings contendo o comando e seus argumentos.
 * A função splitString() prepara esse vetor para você.
 */
int executarProcessoFilho(const char *cmd, const char **cmd_completo) {
	int retorno = 0;

	pid_t filho;
	int estado_filho;

	filho = fork();
	switch (filho) {
	case -1:
		mensagem_erro("Fork falhou.");
		exit (1);

	case 0:
		execvp(cmd, (char * const *)cmd_completo);
		break;

	default:
		filho = wait(&estado_filho);
		if (WIFEXITED(estado_filho)) {
			mensagem("OK\n");
			retorno = 0;
		}
		else {
			mensagem_erro("Erro executando programa filho.");
			retorno = -1;
		}
		break; // Não chegará aqui! Boas práticas ;-)
	}

	return (retorno);
}

void mensagem( const char* format, ... ) {
    va_list args;
    va_start( args, format );
    vfprintf( stdout, format, args );
    va_end( args );
    fprintf( stdout, "\n" );
}

void mensagem_erro( const char* format, ... ) {
	extern int verbose_flag;
	extern int verbose_level;
    va_list args;

    if ( verbose_flag == 1 )
    	switch (verbose_level) {
    	case 0:
    		fprintf(stderr, "%s", format);
    		break;

    	case 1:
    		fprintf( stderr, "Debug Level: %d\n", verbose_level);
    		fprintf( stderr, "[%s:%i]\nErro: " ,__FILE__, __LINE__);
    		break;
    	}

    va_start( args, format );
    vfprintf( stderr, format, args );
    va_end( args );
    fprintf( stderr, "\n" );
}


