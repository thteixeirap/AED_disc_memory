#include "disco.h"

void CarregarDisco(const int numberLines,const int numberColumns,bloco matrizDisco[numberLines][numberColumns]){
    
  	int i=0;
  	int j=0;
  	char *pt;
    char sep[7] = ", <> A";	
  	char c;
  	char texto[300]; 
  	int primeiro=0;
  	int aux;
  	
  	//printf("Linhas: %d\nColunas: %d\n",numberLines,numberColumns);

  	FILE *fp;
    fp = fopen ("C:\\Users\\Teixeira\\Desktop\\DiscoMemoria\\disco.txt","r");
  	 if ( fp == NULL ) {
        printf("Erro na abertura do arquivo");
    }
    printf("\n\tMATRIZ DISCO\n\n");	
    
	 for(i;i<=numberLines;i++){
   		primeiro=0;
     	printf("\nA%d ", i+1);
	 	fgets(texto,300,fp);
    	pt = strtok(texto,sep);
    	j=0;
    	while(pt){
    		if(primeiro == 0){
    			primeiro++;
    			pt = strtok(NULL, sep);
			}
    			aux = atoi(pt); 
    			matrizDisco[i][j].valor = aux;
    			matrizDisco[i][j].column = j;
      			printf("[%d] ", matrizDisco[i][j].valor);
				pt = strtok(NULL, sep);
        		j++;	
   		 	
    	}   
	printf ("\n");		
	}

	fclose(fp);
}

bool ReadDisco(const int numberLines,const int numberColumns,bloco matrizDisco[numberLines][numberColumns],int endereco,int valor){
  
    int j=0;  
    
    for(j;j<numberColumns;j++){
        if(matrizDisco[endereco][j].valor == valor)
        	return true;   	
    } 
    
    return false;
}

void ContarMatrizDisco(tam *t){
	
	char *pt;
    char sep[7] = ", <> A";	
    char texto[200]; 
    
    FILE *fp;
    fp = fopen ("C:\\Users\\Teixeira\\Desktop\\DiscoMemoria\\disco.txt","r");
    char c;
    int linha=0;
    int aux;
    int primeiro;
    int maiorColuna=0;
    int contaColuna=0;
    
    if ( fp == NULL ) {
        printf("Erro na abertura do arquivo");
    }
    while( (c =fgetc(fp))!= EOF ){
     //	if(c =='A')
     //		linha++;
     	
     	primeiro=0;
     	//printf("\nLinha %d\n", linha);
	 	fgets(texto,200,fp);
    	pt = strtok(texto,sep);
    	contaColuna=0;
    	while(pt){
    		if(primeiro == 0){
    			primeiro++;
    			pt = strtok(NULL, sep);
    			linha++;
			}else{
    			aux = atoi(pt);
      			//printf("token: %d\n", aux);
        		pt = strtok(NULL, sep);
        		contaColuna++;
   		 	}
    	}   	
    	if(contaColuna>maiorColuna) maiorColuna = contaColuna;
	}
    
    t->row = linha -1;
    t->column = maiorColuna - 1;
    
	fclose(fp);
}
