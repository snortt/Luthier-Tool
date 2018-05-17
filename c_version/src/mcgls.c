/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * main.c
 * Copyright (C) Gabriel Marques 2012 <snortt@gmail.com>
 *
 */

#include "includes.h"

int main(int argc, char *argv[]) {

	/* Guarda o nome do aplicativo em uma variável */
	char *nomeExecutavel;
	nomeExecutavel = (char *)malloc(strlen(argv[0])+1);
	strcpy(nomeExecutavel,argv[0]);

    extern int useCentimetros;
    useCentimetros = 0;
    extern int verbose_flag;
    verbose_flag = 0;
    extern int verbose_level;
    verbose_level = 0;

	/* Coisas de getopt_long */
	extern char *optarg;
	extern int optind, opterr, optopt;

	/* Variável para tratar nossa linha de comandos */
 	unsigned int opt;

	/* Índice das opções */
	int indice_opcoes = 0;

	/* Opções curtas */
	const char * const opcoes_curtas = ":lc:d:e:n:N:o:p:P:t:";

	/* Opções longas */
	const struct option opcoes_longas[] = {
		/* Opções longas apenas */
		{"ajuda", 0, NULL, 0},
		{"centimetros", 0, &useCentimetros, 1},
		{"verbose", 2, &verbose_flag, 1},
		{"dicas", 2, NULL, 0},
		{"limite-queda", 1, NULL, 0},
		{"nut-fim-escala", 1, NULL, 0},
		{"versao", 0, NULL, 0},

		/* Opções longas e curtas */
		{"comprimento-escala", 1, NULL, 'c'},
		{"distancia-escala-ponte", 1, NULL, 'd'},
		{"altura-escala", 1, NULL, 'e'},
		{"listar-escalas", 0, NULL, 'l'},
		{"total-trastes", 1, NULL, 'n'},
		{"espaco-nut", 1, NULL, 'N'},
		{"altura-ponte", 1, NULL, 'p'},
		{"espaco-ponte", 1, NULL, 'P'},

		/* Fim da estrutura */
		{NULL,0,NULL,0}
	};

    /* Alocar uma guitarra na memória! ;-) */
    GuitarraPtr guit;
    guit = (GuitarraPtr) malloc (sizeof (Guitarra));

    if ( guit == NULL ) {
        mensagem_erro("Não foi possível alocar memória para uma guitarra! :-(");
        exit (EXIT_FAILURE);
    }

    inicializarGuitarra(guit);

	/* Precisamos de opcoes e argumentos */
	if (argc <= 1) {
		ajuda(nomeExecutavel);
		exit(EXIT_SUCCESS);
	}

	/* Aqui vamos tratar as opcoes da linha de comando */
	while ((opt=getopt_long(argc, argv, opcoes_curtas, opcoes_longas, &indice_opcoes)) != -1) {
		switch (opt) {

		/* Tratamento das opções longas que não usam opção curta - Todas retornam 0 */
		case 0:
    		if (strcmp( "ajuda", opcoes_longas[indice_opcoes].name ) == 0 ) {
        		ajuda(nomeExecutavel);
				exit(EXIT_SUCCESS);
    		}

			else if (strcmp( "centimetros", opcoes_longas[indice_opcoes].name ) == 0 ) {
				useCentimetros = 1;
			}

            else if (strcmp( "verbose", opcoes_longas[indice_opcoes].name ) == 0 ) {
				if (optarg)
                    verbose_level = atoi(optarg);
                    mensagem_erro("Ainda não implementado.");
			}

			else if (strcmp( "dicas", opcoes_longas[indice_opcoes].name ) == 0 ) {
				if (optarg == NULL)
					listarDicas();
				else
					dicasLuthier (atoi(optarg));

				exit(EXIT_SUCCESS);
			}

			else if (strcmp( "versao", opcoes_longas[indice_opcoes].name ) == 0 ) {
				mensagem("%s\n",_VERSAO);
				exit(EXIT_SUCCESS);
			}

			else if (strcmp( "limite-queda", opcoes_longas[indice_opcoes].name ) == 0 ) {
				guit->limiteQueda = atof(optarg);
			}

			else if (strcmp( "nut-fim-escala", opcoes_longas[indice_opcoes].name ) == 0 ) {
				guit->nutFimEscala = atof(optarg);
			}

		    break;



		/* Opções longas com suas variantes curtas */
		case 'c':
			guit->compEscala = atof(optarg);
			break;

		case 'd':
			guit->distEscalaPonte = atof(optarg);
			break;

		case 'e':
			guit->alturaEscala = atof(optarg);
			break;

		case 'l':
			listarEscalas();
			exit(EXIT_SUCCESS);
			break; /* Não chegaremos aqui, mas ... */

		case 'n':
			guit->numeroTrastes = atoi(optarg);
			break;

		case 'N':
			guit->espacoNut = atoi(optarg);
			break;

		case 'p':
			guit->alturaPonte = atof(optarg);
			break;

		case 'P':
			guit->espacoPonte = atof(optarg);
			break;

		//case 't':
		//	unionFret = atof(optarg);
		//	break;

		/* Opção que precisa de argumentos retorna ':', pois foi pedido isso em opcoes_curtas */
		case ':':
			mensagem_erro("Opção \"%c\" precisa de argumento.", optopt);
			exit(EXIT_FAILURE);
			break;  /* Não chega aqui. Apenas para a IDE parar de reclamar */

		/* Opções desconhecidas geram o caractere '?'*/
		case '?':
			mensagem_erro("Opção desconhecida: \"%c\"", optopt);
			exit(EXIT_FAILURE);
			break;  /* Não chega aqui. Apenas para a IDE parar de reclamar */

		}
	}

	/* Agora vamos processar os argumentos, gerando relatorio para cada um deles. */
	//for(; optind < argc; optind++) {
	//
	//}

	/* Só podemos calcular as coisas se os conjuntos de valores forem passados */
	if ( (guit->espacoNut > 0) && (guit->espacoPonte > 0) )
		calcularEspacoCordas(guit->espacoNut, guit->espacoPonte);
	else
		mensagem("Não calculando espaço entre cordas.");

	if ( (guit->compEscala > 0) && (guit->numeroTrastes > 0) )
		calcularEscala(guit->compEscala, guit->numeroTrastes);
	else
		mensagem("Não calculando escala.");

	if ( (guit->alturaPonte > 0) && (guit->alturaEscala > 0) && (guit->distEscalaPonte > 0) )
		calcularAnguloBraco (guit->alturaPonte, guit->alturaEscala, guit->distEscalaPonte);
	else
		mensagem("Não calculando ângulo do braço.");

	if ( (guit->espacoNut > 0) && (guit->espacoPonte > 0) && (guit->nutFimEscala > 0) && (guit->compEscala > 0))
		calcularLarguraEscala (guit->espacoNut, guit->espacoPonte, guit->limiteQueda, guit->nutFimEscala, guit->compEscala);
	else
		mensagem("Não calculando a largura do final da escala.");

	mensagem ("\n");

    /* Devolve a memória para o SO */
    //liberarGuitarra(guit);

	exit(EXIT_SUCCESS);
}
