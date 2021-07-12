Projeto feito com o DevC++ 5.11 / Windowns 7 64x

Trabalho de simulação dos processos realizados em Memória/Disco.
Informações relevantes:
TOKENIZAÇÃO disco.txt: Foi usado seguindo o modelo passado, usando os char( , <> A) no separador passado no strtok(), 
	               Problemas Encontrados: sempre na ultima fila, aparece um token a mais no final, não encontrei o motivo, porem para minha aplicação era ignorado;
            	         	

 
TOKENIZAÇÃO processo.txt:  Usando o modelo passado, porem sem o '>' no ultimo bloco de informação usando os char(A,<> P) no separador.
                           Problemas Encontrados: usando o '>' no ultimo bloco de informação aparecia erros nos tokens, nao encontrei o motivo, porém sem ele o erro desaparecia, portanto optei por usar sem


Leitura dos arquivos: Usado a função fgets() para ler as strings do arquivo, usado o tamanho de '500' char para ler o arquivo.txt e '300' char para ler cada string do disco.txt
		      O caminho para os arquivos esta com o endereço da minha máquina, quando for realizar testes realizar também o caminho dos aquivos .txt


O programa foi testado apenas com os arquivos de exemplos, portanto nao ocorreu um tratamento específico em relação a algum problema que possa ocorrer mediante a alteração desses arquivos.
O código foi programado para aceitar somente 10 colunas de processo, e aceitar qualquer valor para as linhas desse arquivo processo, tendo a 'matrizMemoria' aceitando apenas 5 valores por linha, e os excedentes adicioados a uma matrizSwap.

1)O programa se inicia com a contagem de linhas do disco.txt para logo criar a matriz para armazenar esses valores. A matriz Disco foi feita usando struct, armazendo nele o valor e qual posição da coluna esse valor se encontra.

2)Logo apos o carregamento do disco, inicia-se o processo da abertura do processo.txt, tokenizando e lendo na MatrizMemoria se este valor se encontra, nao encontrando le esse valor em Disco, sendo true essa informação, contatenando o valor de Disco para Memoria. A matriz memoria foi feita com struct, tendo variaveis para armazenar o valor, a linha e a coluna desse valor em disco;

3)A linha que exceder as 5 posições da Memoria, ira armazenar esse excedente em uma matriz semelhante a da Memoria, a Swap.

4)Apos o preenchimento da matriz Memoria e Swap, ocorre a leitura da matriz Swap, localizando os possiveis blocos em espera.

5)Caso havendo valores na Swap, ocorre uma devolução a disco dos valores presentes no bloco de requisição mais antiga,chama-se a função que reorganiza essa linha da memoria, passando os valores para frente adicionando o valor de Swap na ultima posição dessa linha, logo apos é chamada uma função que verifica a matriz Swap, retirando esse valor que foi adicionado na Memoria e passando para frente possiveis outros blocos dessa linha na Swap;

6)Na busca em Disco ao adicionar os valores na matriz, e na busca dos valores presentes na Swap em disco e posteriormente alocando ele na memoria, tem uma variavel para cada linha desse processos, contando a quantidade de busca em disco realizada.

Na intenção de diminuir essa falha na busca da Memoria no seu preenchimento inicial, é viável a utilização de um construtor no inicio do processo, sendo assim, ao iniciar o programa ja sabendo que a Memória esta vazia, realiza-se a busca direta em disco e armazena na memoria sem necessitar de ler e fallhar a busca em memoria
