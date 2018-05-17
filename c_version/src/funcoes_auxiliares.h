/*
 * funcoes_auxiliares.h
 *
 *  Created on: 30/08/2012
 *      Author: gabriel
 */

#ifndef FUNCOES_AUXILIARES_H_
#define FUNCOES_AUXILIARES_H_

const char ** splitString(char *, const char *);
char * initCharBuffer(const char *);
void inicializarGuitarra(GuitarraPtr);
void liberarGuitarra(GuitarraPtr);
void mensagem( const char* , ... );
void mensagem_erro( const char*, ... );
int executarProcessoFilho(const char *cmd, const char *cmd_completo[]);

/* Para as funções que utilizarem debug e níveis diferentes */
int verbose_flag;
int verbose_level;

#endif /* FUNCOES_AUXILIARES_H_ */
