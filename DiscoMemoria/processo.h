#ifndef PROCESSO_H
#define PROCESSO_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include "memoria.c"
#include "disco.c"
#include "processo.c"



void IniciaProcesso(const int numberLines,const int numberColumns,bloco  matrizDisco[numberLines][numberColumns]);
void comutaValores(const int numberLines,const numberColumns,bloco matrizDisco[numberLines][numberColumns],const int number,const int numberC,blocoMemoria matrizMemoria[number][numberC],int endereco,int valor,int linhaMemoria,int colunaMemoria);
void InseriNaMemoria(const int numberLines, const int numberColumns,blocoMemoria matrizMemoria[numberLines][numberColumns],int linha);
void ArrumaSwap (const int numberLines, const int numberColumns,blocoMemoria swap[numberLines][numberColumns],int linha);


#endif

