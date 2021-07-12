#include "processo.h"


int main(){

 	tam tamanho;
 	ContarMatrizDisco(&tamanho); 
	bloco matrizDisco[tamanho.row][tamanho.column];
	CarregarDisco(tamanho.row,tamanho.column,matrizDisco);// Cria a matrizDisco e carrega com as informações do disco.txt
	IniciaProcesso(tamanho.row,tamanho.column,matrizDisco);

exit(0);    
}



