#include "processo.h"

 void IniciaProcesso(const int numberLines,const int numberColumns,bloco  matrizDisco[numberLines][numberColumns]){
     
    tamMemoria tamanhoMatriz;   
    ContarMatrizProcesso(&tamanhoMatriz); //Conta as linhas do arquivo processo para criar a matrizMemoria	
	blocoMemoria matrizMemoria[tamanhoMatriz.row][5]; 
	blocoMemoria swap[tamanhoMatriz.row][5];
	CarregarMemoria(tamanhoMatriz.row,5,matrizMemoria);
	CarregarSwap(tamanhoMatriz.row,5,swap);

	FILE *fp;
    fp=fopen("C:\\Users\\Teixeira\\Desktop\\DiscoMemoria\\processo.txt","r");
     
	if ( fp == NULL ) {
        printf("Erro na abertura do arquivo");
    }
    
	char *pt;
    const char sep[7] = "A,<> P";	
  	char c;
  	char texto[500]; 
  	int primeiro=0,p=0;
  	int auxEndereco,auxValor,i=0;	
	int contProcesso,x=0;   
	int j=0;
	int pageMiss[tamanhoMatriz.row];
	
	for(p=0;p<tamanhoMatriz.row;p++){
		primeiro=0;
		contProcesso=0;
	 	fgets(texto,500,fp);
    	pt = strtok(texto,sep);
    	x=0;
    	while(pt){
    	
   			if(primeiro == 0){
   				primeiro++;
   				pt = strtok(NULL, sep);
			}else if(contProcesso<5){
				auxEndereco = atoi(pt) -1;
        		pt = strtok(NULL, sep);	
        		auxValor = atoi(pt);
        		
        		if(!ReadMemoria(tamanhoMatriz.row,5,matrizMemoria,p,auxValor)){ 
					if(ReadDisco(numberLines,numberColumns,matrizDisco,auxEndereco,auxValor)){
						comutaValores(numberLines,numberColumns,matrizDisco,tamanhoMatriz.row,5,matrizMemoria,auxEndereco,auxValor,p,contProcesso);
						pageMiss[p] = contProcesso+1;
					}
				}													
        		pt = strtok(NULL, sep);	
        		contProcesso++;	
			}else{
			 auxEndereco = atoi(pt);
			 swap[p][x].endereco = auxEndereco; 
        	 pt = strtok(NULL, sep);	
        	 auxValor = atoi(pt);
        	 swap[p][x].valor = auxValor;	
			 pt = strtok(NULL, sep);
			 x++;	
        	 contProcesso++;	
			}
    	} 
	}
		
	fclose(fp);	
	ImprimeMemoria(tamanhoMatriz.row,5,matrizMemoria);
	ImprimeSwap(tamanhoMatriz.row,5,swap);
	
	
	for(j=0;j<=tamanhoMatriz.row;j++){
		for(i=0;i<4;i++){
			if(swap[i][0].valor != -1){
				pageMiss[i] = pageMiss[i] +1;
				matrizDisco[matrizMemoria[i][0].endereco-1][matrizMemoria[i][0].enderecoDisco].valor = matrizMemoria[i][0].valor;//Retorna valor pra disco // 0 na coluna pq sempre vai ser a requisição mais antiga a sair
				printf("Volta pra disco: %d\n",matrizDisco[matrizMemoria[i][0].endereco-1][matrizMemoria[i][0].enderecoDisco].valor);
				printf("Volta pra disco: %d\n",matrizMemoria[i][0].enderecoDisco);
				InseriNaMemoria(tamanhoMatriz.row,5,matrizMemoria,i);//Tira o primeiro e abre o ultimo pra alocar
				matrizMemoria[i][4].valor = swap[i][0].valor; // Adiciona o valor da Swap na ultima posição
				matrizMemoria[i][4].endereco = swap[i][0].endereco;//Adiciona o endereco armazenado na swap
			
				printf("\n------------------------\n");
				ArrumaSwap(tamanhoMatriz.row,5,swap,i);
				ImprimeMemoria(tamanhoMatriz.row,5,matrizMemoria);	
				ImprimeSwap(tamanhoMatriz.row,5,swap);
			}	 
		}		
	}
	int auxCont=0;	
	for(auxCont=0;auxCont<tamanhoMatriz.row;auxCont++)
		printf("\n  Busca em disco P%d: %d",auxCont+1,pageMiss[auxCont]);
}

void comutaValores(const int numberLines,const numberColumns,bloco matrizDisco[numberLines][numberColumns],const int number,const int numberC,blocoMemoria matrizMemoria[number][numberC],int endereco,int valor,int linhaMemoria,int colunaMemoria){
	
	int i=0;
	for(i=0;i<numberColumns;i++){
		if(matrizDisco[endereco][i].valor == valor){
			matrizDisco[endereco][i].valor = -1;
			matrizMemoria[linhaMemoria][colunaMemoria].valor = valor;
			matrizMemoria[linhaMemoria][colunaMemoria].endereco = endereco+1;
			matrizMemoria[linhaMemoria][colunaMemoria].enderecoDisco = matrizDisco[endereco][i].column;
		}
	}
}


void InseriNaMemoria(const int numberLines, const int numberColumns,blocoMemoria matrizMemoria[numberLines][numberColumns],int linha){
	int i=0;
	for(i=0;i<5;i++){
		matrizMemoria[linha][i] = matrizMemoria[linha][i+1];
	}
}

void ArrumaSwap (const int numberLines, const int numberColumns,blocoMemoria swap[numberLines][numberColumns],int linha){
 	int i=0;
	for(i=0;i<4;i++){	
		if(swap[linha][i].valor != -1){
			for(i=0;i<4;i++)
				swap[linha][i] = swap[linha][i+1];
			
		swap[linha][4].valor = -1;
		swap[linha][4].endereco = -1;	
		}
	}
}

