#ifndef GUITARRA_H_
#define GUITARRA_H_

/*
 * Gabriel Marques
 * snortt@gmail.com
 */

/* Uma guitarra */
struct _guitarra {
	unsigned int numeroTrastes;  	/* Número de trastes da escala */
	float alturaPonte;				/* Altura da ponte */
	float alturaEscala;				/* Altura da escala na junta braço x corpo */
	float compEscala;				/* Comprimento da escala usada (fretboard) */
	float distEscalaPonte;			/* Distância do final da escala até à ponte (saddles) */
	float espacoNut;				/* Espaço entre as cordas externas, no nut */
	float espacoPonte;				/* Espaço entre as cordas externas, na ponte */
	float limiteQueda;              /* Limite para que as cordas não caiam da escala */
	float nutFimEscala;				/* Distância do nut ao fim da escala */
};

typedef struct _guitarra Guitarra;
typedef Guitarra * GuitarraPtr;

/* Use centímetros nas medidas */
int useCentimetros;

#endif // GUITARRA_H_
