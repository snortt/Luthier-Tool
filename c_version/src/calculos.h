#ifndef CALCULOS_H_
#define CALCULOS_H_

/* Valores pré-definidos */
/* Constante para a regra do 18 (cálculo da escala) */
#define _CONSTANTE_ESCALA 17.817
/* Constante para calcular string space em guitarras (mm) */
#define _CONSTANTE_STRSPC_GUIT 5
/* Constante para calcular string space em baixos (mm) */
#define _CONSTANTE_STRSPC_BASS 3
/* Constante para limite entre cordas externas e fim lateral da escala (mm) */
#define _CONSTANTE_CAIR_DA_ESCALA 3.5

/* Escalas mais comuns (polegadas) */
#define _GIBSON_ANTIGO 24.625
#define _GIBSON_NOVO 24.75
#define _PRS 25.0
#define _FENDER 25.5

/* Constante para conversão entre Radiano e Grau */
#define GRAURAD 180.0/M_PI

/* Protótipos das funções de cálculos */
void calcularEscala (float, int );
void calcularAnguloBraco (float, float, float );
void listarEscalas (void);
void calcularEspacoCordas (float, float);
void calcularLarguraEscala(float, float, float, float, float);

#endif
