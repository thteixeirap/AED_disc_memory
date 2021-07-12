#include "memoria.h"

bool ReadMemoria(const int numberLines,const int numberColumns,blocoMemoria  matrizMemoria[numberLines][numberColumns],int linha,int valor){
	int i=0;

	for(i=0; i<5;i++){
 		if(matrizMemoria[linha][i].valor == valor)
 			return true;
	}
	return false; 
 }
 
 void ContarMatrizProcesso(tamMemoria *t){
	
    
    FILE *fp;
    fp = fopen ("C:\\Users\\Teixeira\\Desktop\\DiscoMemoria\\processo.txt","r");
    char c;
	int cont=0;

    if ( fp == NULL ) {
        printf("Erro na abertura do arquivo");
    }
    while( (c =fgetc(fp))!= EOF ){
    	if(c =='P')
    		cont++;
	}
    
    t->row = cont;
    
	fclose(fp);
}

void CarregarMemoria(const int numberLines,const int numberColumns,blocoMemoria matrizMemoria[numberLines][numberColumns]){
	int i,j;
	
	for(i=0;i<numberLines;i++){
		for(j=0;j<5;j++){
			matrizMemoria[i][j].valor = -1;
			matrizMemoria[i][j].endereco = -1;
			matrizMemoria[i][j].enderecoDisco = -1;
		}
	}
}

void CarregarSwap(const int numberLines,const int numberColumns,blocoMemoria swap[numberLines][numberColumns]){
	int i,j;
	
	for(i=0;i<numberLines;i++){
		for(j=0;j<5;j++){
			swap[i][j].valor = -1;
			swap[i][j].endereco = -1;
			swap[i][j].enderecoDisco = -1;
		}
	}
}

void ImprimeSwap(const int numberLines,const int numberColumns,blocoMemoria swap[numberLines][numberColumns]){
	
	int i=0,j=0;
	
	printf("\n\tMATRIZ SWAP\n\n");
	
	for(i=0;i<numberLines;i++){
		for (j=0;j<5;j++){
			printf("[%d,%d] ", swap[i][j].endereco, swap[i][j].valor);
		}
	printf("\n");	
	}
	printf("\n\n");
}


void ImprimeMemoria(const int numberLines,const int numberColumns,blocoMemoria matrizMemoria[numberLines][numberColumns]){
	
	int i=0,j=0;
	printf("\n\tMATRIZ MEMORIA\n\n");
	for(i=0;i<numberLines;i++){
		for (j=0;j<5;j++){
			printf("[%d,%d] ", matrizMemoria[i][j].endereco, matrizMemoria[i][j].valor);
		}
	printf("\n");	
	}
}
