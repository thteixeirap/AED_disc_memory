#ifndef MEMORIA_H
#define MEMORIA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef struct	tamMemoria{
	int row;
}tamMemoria;


typedef struct blocoMemoria{
    int valor;
    int endereco;
    int enderecoDisco;
}blocoMemoria;


void CarregarMemoria(const int numberLines,const int numberColumns,blocoMemoria matrizMemoria[numberLines][numberColumns]);
bool ReadMemoria(const int numberLines,const int numberColumns,blocoMemoria  matrizMemoria[numberLines][numberColumns],int linha,int valor);
void ContarMatrizProcesso(tamMemoria *t);
void ImprimeMemoria(const int numberLines,const int numberColumns,blocoMemoria matrizMemoria[numberLines][numberColumns]);

#endif


