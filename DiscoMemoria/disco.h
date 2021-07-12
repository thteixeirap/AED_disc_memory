#ifndef DISCO_H
#define DISCO_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct bloco{
    int valor;
    int column;
}bloco;

typedef struct tam{
	int row;
	int column;
}tam;

void CarregarDisco(const int numberLines,const int numberColumns,bloco matrizDisco[numberLines][numberColumns]);
bool ReadDisco(const int numberLines,const int numberColumns,bloco  matrizDisco[numberLines][numberColumns],int linha,int valor);
void ContarMatrizDisco(tam *t);

#endif
