/* Funções auxiliares do programa */

#include "includes.h"

/* Função de ajuda */
void ajuda(const char *arg) {
	mensagem("Calculadora de Guitarras %s",_VERSAO);
	mensagem ("    %s(%s)",_AUTHOR,_EMAIL);
	mensagem ("    %s - %s",_CORP,_ANO);

	mensagem("\n");
	mensagem("Uso: %s [opções]",arg);
	mensagem("\t   --ajuda                       Ajuda com a sintaxe do comando.");
	mensagem("\t   --centimetros                 Imprime resultados em centímetros.");
	mensagem("\t   --dicas[=n]                  Imprime dicas do lutier. Use 0 para listar todas.");
	mensagem("\t   --limite-queda <mm>            Limite para as cordas não \"caírem\" da escala. Padrão: 3.5 mm.");
	mensagem("\t   --nut-fim-escala <mm>          Distância do nut ao final da escala.");
	mensagem("\t   --verbose [=level]            Imprime mensagens mais detalhadas (level:0-2).");
	mensagem("\t   --versao                      Versão do programa.");
	mensagem("\t-c|--comprimento-escala <mm>     Comprimento da escala usada.");
	mensagem("\t-d|--distancia-escala-ponte <mm> Distância do final da escala até à ponte (saddles).");
	mensagem("\t-e|--altura-escala <mm>          Altura da escala no final do braço (do corpo à ponta do traste).");
	mensagem("\t-l|--listar-escalas              Lista os tamanhos mais comuns de escalas.");
	mensagem("\t-n|--total-trastes <n>           Número de trastes da escala.");
	mensagem("\t-N|--espaco-nut <mm>             Espaço entre as cordas externas (E e), no nut.");
	mensagem("\t-P|--espaco-ponte <mm>           Espaço entre as cordas externas (E e), na ponte.");
	mensagem("\t-p|--altura-ponte <mm>           Altura da ponte (base do corpo ao topo do saddle).");
	/*mensagem("\t-t|--traste-uniao <n>          Traste onde o braço se une ao corpo.");*/

	mensagem ("\n");
	mensagem("* Os valores <mm> devem estar em milímetros.");
	mensagem("* Use --listar-escalas para saber as medidas das escalas em milímetros ;-)");
	mensagem("* Dependências entre as opções:");
	mensagem("    -N -P -> Calcular o espaço entre as cordas.");
	mensagem("    -e -n -> Calcular a escala do instrumento.");
	mensagem("    -p -e -d -> Calcular o ângulo do braço.");
	mensagem("    -N -P -c --nut-fim-escala -> Calcular a largura total ao final da escala.");

	mensagem("\n");
}



