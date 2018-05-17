CC=gcc
CC_FLAGS=-Wall 

ajuda: ajuda.c ajuda.h
	$(CC) $(CC_FLAGS) -c ajuda.c -o ajuda.o

calculos: calculos.c calculos.h guitarra.h
	$(CC) $(CC_FLAGS) -c calculos.c -o calculos.o

dicas: dicas.txt dicas_luthier.c dicas_luthier.h
	$(CC) $(CC_FLAGS) -c dicas_luthier.c -o dicas_luthier.o

aux: funcoes_auxiliares.c funcoes_auxiliares.h guitarra.h
	$(CC) $(CC_FLAGS) -c funcoes_auxiliares.c -o funcoes_auxiliares.o

mcgls: mcgls.c
	$(CC) $(CC_FLAGS) -c mcgls.c -o mcgls.o

all: ajuda calculos dicas aux mcgls 
	$(CC) $(CC_FLAGS) -lm ajuda.o calculos.o dicas_luthier.o funcoes_auxiliares.o mcgls.o -o mcgls

clean:
	@-rm *.o mcgls

