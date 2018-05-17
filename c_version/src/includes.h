/*
 * Arquivo com a lista de todos os 'includes' necessários para o programa
 *
 * Gabriel Marques
 * snortt@gmail.com
 */

#ifndef INCLUDES_H_
#define INCLUDES_H_

/* Bibliotecas do sistema */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include <time.h>

/* Processos e subprocessos */
#include <sys/types.h>
#include <sys/wait.h>

/* Usado por funções variádicas */
#include <stdarg.h>

/* Usado por getopt_long() */
#define _GNU_SOURCE
#include <unistd.h>
#include <getopt.h>

/* Bibliotecas do programa */
#include "guitarra.h"
#include "funcoes_auxiliares.h"
#include "ajuda.h"
#include "calculos.h"
#include "dicas_luthier.h"

#endif
