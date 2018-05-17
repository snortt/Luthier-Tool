#include "includes.h"

/* "Textos com as Dicas do Luthier */

/* Constante para cálculo dos trastes */
char *constante17817[] = {
	"A constante 17.817",
	"\n"
	"	Quando uma corda é pressionada contra o traste, ",
	"	seu comprimento vibratório é reduzido a um valor ",
	"	preciso, pré-determinado.",
	"\n"
	"	Para cada traste a frequência de vibração da corda ",
	"	aumenta em um semitom. Como uma oitava é dividida ",
	"	em 12 semitons, o tom de uma corda pressionada ",
	"	no 12° é o dobro do mesmo com a corda solta.",
	"	Para calcular a medida que uma corda precisa ser ",
	"	encurtada para aumentar seu tom em um semitom, o ",
	"	comprimento total da corda deve ser dividido pela ",
	"	raiz doze de 2. Com a constante de traste então ",
	"	determinada, é possível calcular quanto cada corda ",
	"	deve ser encurtada.",
	"\n"
	"	Dividindo o comprimento total da escala por 17.817",
	"	tem-se o comprimento pelo qual uma corda precisa",
	"	ser encurtada para que seu tom aumente em um semitom",
	"	(um exemplo é a distância entre o nut e o primeiro traste).",
	"	Essa constante garante uma distribuição bem temperada",
	"	entre os trastes e as três casas decimais são mais",
	"	do que suficientes.\n",
	NULL
};

/* Como calcular a distância dos trastes */
char *calculoTrastes[] = {
	"Cálculo da distância dos trastes",
	"\n"
	"	Dividindo qualquer comprimento de escala pela constante 17,817, ",
	"	tem-se a distância da parte interna do nut até o primeiro traste.",
	"	Veja um exemplo: uma escala de 24,75\" (628,65 mm), quando dividida ",
	"	por 17,817, resulta em 1,389122748\" (35,283718 mm), que pode ser ",
	"	arredondado para 1,389\" (35,28 mm) - 3 casas decimais bastam para ",
	"	medidas imperiais e 2 para medidas métricas. Isso significa que ",
	"	o primeiro traste fica a 35,28 mm de distância do nut. ",
	"\n"
	"	Para calcular a distância do segundo traste, pega-se o comprimento ",
	"	da escala menos a distância do primeiro traste (já calculada) e ",
	"	faz-se uma nova divisão por 17,817. Assim:",
	"		628,65 - 35,28 = 593,37 (Escala sem o primeiro traste)",
	"		593,37 / 17.817 = 33,30 (Distância do primeiro ao segundo traste)",
	"\n"
	"	Todas as distâncias de trastes devem ser calculadas a partir do nut ",
	"	ou traste zero, se houver um, o que evita erro cumulativo. Assim:",
	"	Primeiro traste -> 35,28 mm do nut",
	"	Segundo traste -> 35,28 + 33,30 = 64,58 mm do nut ",
	"	Os demais trastes seguem a mesma lógica. Observe que o cálculo para ",
	"	o 12° traste deverá resultar no valor exato da metada do comprimento ",
	"	total da escala escolhida.\n",
	NULL
};

char *layoutGuitarra[] = {
	"Layout da Guitarra",
	"	Se possível faça um rascunho de como será sua guitarra.",
	"	Lembre-se de que as dimensões da escala sempre serão determinadas ",
	"	por três fatores: comprimento da escala (I), espaço entre as cordas ",
	"	no nut (II) e espaço entre as cordas na ponte (III).",
	"	Assim, é aconselhado ter todas as partes em mãos, antes de cortar, ",
	"	furar, marcar, etc. Meça duas vezes, corte uma! =)\n",
	NULL
};

char *dimensoesBraco[] = {
	"Dimensões do braço",
	"	As dimensões do braço devem ser escolhidas individualmente, pois ",
	"	são um fator muito importante para a tocabilidade de uma guitarra.",
	"\n",
	"	As dimensões da escala são determinadas por três fatores:",
	"		I   - Espaçamento entre as cordas externas no nut.",
	"		II  - Distância das cordas externas até o limite da escala (igual por toda a escala)",
	"		III - Espaçamento entre as cordas externas na ponte\n",
	NULL
};

char *espacoCordas[] = {
	"Espaçamento das cordas",
	"	Caso não tenha nenhuma medida para o espaçamento das cordas, fique com ",
	"	35 mm para guitarras e 32 mm para baixos de quatro cordas, no NUT.",
	"	Para evitar que as cordas externas \"caiam\" para fora do braço, ",
	"	uma distância mínima de 3,5 mm deve ser considerada em cada extremidade do Nut.",
	"	\n",
	"	Na ponte, o valor é pré-definido pelo fabricante, mas deve ficar ",
	"	em torno de 54 mm ou 53.2 mm para guitarras e 57.2 mm para baixos.",
	"	Esses valores representam o espaço entre as cordas externas ",
	"	(E - e, em guitarras) e (E - g, em baixos de quatro cordas).",
	"	Uma vez marcada a distância entre as cordas externas no NUT e na PONTE, ",
	"	a distância entre cada corda pode ser calculada dividindo-se as medidas ",
	"	nut e ponte por 5. Para as dimensões sugeridas acima, tem-se:",
	"\n",
	"		Nut: 35 / 5 = 7 (cada corda fica a 7 mm da outra, no NUT)",
	"		Ponte: 54 / 5 = 10,8 (cada corda fica a 10,8 mm da outra, na PONTE)\n",
	NULL
};

char **lista_de_dicas[] = {
    constante17817,     /* 0 */
    calculoTrastes,     /* 1 */
    layoutGuitarra,     /* 2 */
    dimensoesBraco,     /* 3 */
    espacoCordas,       /* 4 */
    NULL                /* FIM da lista */
    };

/* Conta o total de dicas, para exibir posteriormente. */
static int total_dicas = 0;

/* Funções para manipular as dicas */
/* contar as dicas disponíveis */
void contarDicas (void) {

    while (lista_de_dicas[total_dicas] != NULL) {
        total_dicas++;
    }
}

/* Listar as dicas disponíveis */
void listarDicas (void) {

    int i;
    contarDicas();
    for ( i = 0; i < total_dicas; i++ )
        mensagem("Dica %d: %s", i+1, *lista_de_dicas[i]);
}

/* Escolhe qual dica imprimir */
void dicasLuthier (int dica) {

    contarDicas();
    if ( dica > total_dicas || dica <= 0)
        mensagem_erro("Dica inválida");
    else
        /* Lembre-se de que a dica 0 aparece como dica 1 para o usuário */
        imprimirDica(lista_de_dicas[dica-1]);
}

/* Imprime a dica escolhida */
void imprimirDica(char **dica) {

	unsigned short int indice_dicas = 0;

	do {
		if ( dica[indice_dicas] == NULL )
			break;

        fflush(stdout);
		mensagem("%s ", dica[indice_dicas]);
	} while ( dica[indice_dicas++] );
}

