#include "includes.h"

/* Função para calcular a posição dos trastes na escala */
/* Esta função recebe o comprimento da escala e o número de trastes */
void calcularEscala(float escala, int nTrastes) {

	extern int useCentimetros;

	float distancia;			/* Distância do traste ao NUT */
	float localizacao;			/* Localização parcial */
	float fator_escala;			/* Relação entre localização parcial e constante da regra do 18 */
	unsigned short int traste;	/* Traste procurado */

	fator_escala = 0;
	distancia = 0;

	mensagem("\n");
	mensagem("Medidas para uma escala de %0.3f mm (%0.2f cm) com %d trastes", escala, escala/10, nTrastes);
	mensagem("Traste | Longe do NUT");
	mensagem("---------------------");

	for (traste = 1; traste <= nTrastes; traste++)
	{
	    localizacao = escala - distancia;
	    fator_escala = localizacao / _CONSTANTE_ESCALA;
	    distancia += fator_escala;
	    if ( useCentimetros == 1 )
		    mensagem("  %02d     %.2f cm", traste, distancia/10);
	    else
			mensagem("  %02d     %.3f mm", traste, distancia);
	}

	return;
}

/* Função para calcular o ângulo do braço em relação ao corpo */
/* Argumentos recebidos:
 * alturaPonte     - Altura da ponte em seu nível mais baixo, incluindo base (postes, suporte, etc.)
 * distEscalaPonte - Distância do final da escala até à ponte (saddles)
 * alturaEscala    - Altura no meio da escala (por causa do raio), incluindo o traste, a partir da base da guitarra (corpo).
 */
void calcularAnguloBraco(float alturaPonte, float alturaEscala, float distEscalaPonte) {

	char plural[3] = {'.',' ','\0'};
	float angulo = 0;
	float angulo_graus = 0;
	float relacaoAlturas = 0;	/* Diferença entre alturaPonte e alturaEscala */

	if (alturaPonte <= 0 || alturaEscala <= 0 || distEscalaPonte <= 0) {
        mensagem("Nenhum valor pode ser ZERO");
		abort();
	}

	relacaoAlturas = alturaPonte - alturaEscala;

	angulo = asinf(relacaoAlturas/distEscalaPonte);
	angulo_graus = angulo * GRAURAD;

	/* Precisamos corrigir o português */
	if (angulo_graus > 1)
		strcpy(plural,"s.");

	mensagem ("O ângulo do braço deve ser de %0.2f grau%s", angulo_graus, plural);
}

/* Função para listar os tamanhos mais comuns de escalas */
void listarEscalas (void) {
	mensagem ("Tamanhos mais comuns para escalas");
	mensagem ("---------------------------------");
	mensagem ("Padrão      | In     | cm    | mm");
	mensagem ("--------------------------------------");
	mensagem ("Gibson J-45 | %0.3f | %0.2f | %0.3f", _GIBSON_ANTIGO, _GIBSON_ANTIGO * 2.54, _GIBSON_ANTIGO * 25.4);
	mensagem ("Gibson LP   | %0.2f  | %0.2f | %0.3f", _GIBSON_NOVO, _GIBSON_NOVO * 2.54, _GIBSON_NOVO * 25.4);
	mensagem ("PRS         | %0.1f   | %0.2f | %0.3f", _PRS, _PRS * 2.54, _PRS * 25.4);
	mensagem ("Fender      | %0.1f   | %0.2f | %0.3f", _FENDER, _FENDER * 2.54, _FENDER * 25.4);
	mensagem ("\n");
}

/* Função para calcular o espaçamento entre as cordas */
/* Essa função faz o mesmo que a régua "string spacing rule", da Stew Mac */
void calcularEspacoCordas (float espacoNut, float espacoPonte) {
	mensagem ("O espaço entre as cordas na ponte é pré-definido pelo fabricante.");
	mensagem ("Use o valor da ponte, calculado abaixo, apenas para conferir as medidas.");
	mensagem ("Espaço entre as cordas externas, no nut: %0.3f mm", espacoNut);
	mensagem ("Espaço entre as cordas externas, na ponte: %0.3f mm", espacoPonte);
	mensagem ("Distância entre as cordas, no nut: %0.3f mm", espacoNut/_CONSTANTE_STRSPC_GUIT);
	mensagem ("Distância entre as cordas, na ponte: %0.3f mm", espacoPonte/_CONSTANTE_STRSPC_GUIT);

}

/* Função para calcular a largura da escala, no fim do braço */
/* Essa função faz o mesmo que a régua "string spacing rule", da Stew Mac */
void calcularLarguraEscala(float espacoNut, float espacoPonte, float limiteQueda, float nutFimEscala, float compEscala) {
	float larguraEscala = 0;

	larguraEscala = espacoNut + (2 * limiteQueda) + (nutFimEscala * (espacoPonte - espacoNut) / compEscala );
    if ( useCentimetros == 1 )
        mensagem ("A largura do final da escala é %0.2f cm", larguraEscala/10);
    else
        mensagem ("A largura do final da escala é %0.3f mm", larguraEscala);
}

