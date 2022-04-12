#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
	char codOp[11];
} Arquivo;

int numMovi = 0;
int numComp = 0;

void printarArq(Arquivo *arq, int tamArq, FILE* file);
void printarArquivo(Arquivo *arq, int tamArq, FILE* file);
int numberOfLines(FILE *file);
void insertOnArquivo(Arquivo *mes, FILE *file, int tamFile);

void ordInsercaoDir(Arquivo *arq, int tamArq);
void ordInsercaoBin(Arquivo *arq, int tamArq);
void ordSelecao(Arquivo *arq, int tamArq);
void ordBubble(Arquivo *arq, int tamArq);

void ordMerge(Arquivo *arq, int tamArq);
void ordMerge_mpass_(Arquivo *arq, int tamArq, int p, Arquivo *c);
void ordMerge_merge_(Arquivo *arq, int L, int h, int R, Arquivo *c);

void ordHeap(Arquivo *arq, int tamArq);
void ordHeap_heapify_(Arquivo *arq, int L, int R);

void ordQuick(Arquivo *arq, int tamArq);
void ordQuick_qsort_(Arquivo *arq, int L, int R);

int buscaBinaria(Arquivo busca, Arquivo *arq, int tamArq);
int buscarNoArquivo(Arquivo busca, FILE* mesO, int mes);

int main()
{	
	int tamFile = 0;
	Arquivo *arquivo_mes;
	FILE *mes, *mes_organizado_todas_ord, *resultado;
	resultado = fopen("resultados.txt", "w");
	
	
	//MES 1
	fprintf(resultado, "Mes 1\n");
	
	mes = fopen("mes_1.txt", "r");
	mes_organizado_todas_ord = fopen("mesOrganizadoAllMethods_1.txt", "w");
	
	tamFile = numberOfLines(mes);
	
	arquivo_mes = malloc(tamFile * sizeof(Arquivo));
	
	insertOnArquivo(arquivo_mes, mes, tamFile);



	//Ord Insercao Direta
	ordInsercaoDir(arquivo_mes, tamFile);
	fprintf(mes_organizado_todas_ord, "Ordenação por Inserção Direta: \n");
	printarArquivo(arquivo_mes, tamFile, mes_organizado_todas_ord);
	fprintf(mes_organizado_todas_ord, "\n\n\n");
	
	fprintf(resultado, "Ordenação por Inserção Direta: \n");
	fprintf(resultado, "\tNúmero de Movimentações: %d \t Número de Comparações: %d\n\n",
		numMovi, numComp);
	numMovi = 0;
	numComp = 0;
	insertOnArquivo(arquivo_mes, mes, tamFile); //reset situação do arquivo
	


	//Ord Insercao Binaria
	ordInsercaoBin(arquivo_mes, tamFile);
	fprintf(mes_organizado_todas_ord, "Ordenação por Inserção Binaria: \n");
	printarArquivo(arquivo_mes, tamFile, mes_organizado_todas_ord);
	fprintf(mes_organizado_todas_ord, "\n\n\n");
	
	fprintf(resultado, "Ordenação por Inserção Binaria: \n");
	fprintf(resultado, "\tNúmero de Movimentações: %d \t Número de Comparações: %d\n\n",
		numMovi, numComp);
	numMovi = 0;
	numComp = 0;
	insertOnArquivo(arquivo_mes, mes, tamFile); //reset situação do arquivo	
	
	
	//Ord Selecao
	ordSelecao(arquivo_mes, tamFile);
	fprintf(mes_organizado_todas_ord, "Ordenação por Seleção: \n");
	printarArquivo(arquivo_mes, tamFile, mes_organizado_todas_ord);
	fprintf(mes_organizado_todas_ord, "\n\n\n");
	
	fprintf(resultado, "Ordenação por Seleção: \n");
	fprintf(resultado, "\tNúmero de Movimentações: %d \t Número de Comparações: %d\n\n",
		numMovi, numComp);
	numMovi = 0;
	numComp = 0;
	insertOnArquivo(arquivo_mes, mes, tamFile); //reset situação do arquivo	
	
	
	//Ord BubbleSort
	ordBubble(arquivo_mes, tamFile);
	fprintf(mes_organizado_todas_ord, "Ordenação por Bubble Sort: \n");
	printarArquivo(arquivo_mes, tamFile, mes_organizado_todas_ord);
	fprintf(mes_organizado_todas_ord, "\n\n\n");
	
	fprintf(resultado, "Ordenação por Bubble Sort: \n");
	fprintf(resultado, "\tNúmero de Movimentações: %d \t Número de Comparações: %d\n\n",
	    numMovi, numComp);
	numMovi = 0;
	numComp = 0;
	insertOnArquivo(arquivo_mes, mes, tamFile); //reset situação do arquivo
	
	
	
	//Ord Heap
	ordHeap(arquivo_mes, tamFile);
	fprintf(mes_organizado_todas_ord, "Ordenação por Heap Sort: \n");
	printarArquivo(arquivo_mes, tamFile, mes_organizado_todas_ord);
	fprintf(mes_organizado_todas_ord, "\n\n\n");
	
	fprintf(resultado, "Ordenação por Heap Sort: \n");
	fprintf(resultado, "\tNúmero de Movimentações: %d \t Número de Comparações: %d\n\n",
	    numMovi, numComp);
	numMovi = 0;
	numComp = 0;
	insertOnArquivo(arquivo_mes, mes, tamFile); //reset situação do arquivo
	
	
	
	//Ord Fusao
	ordMerge(arquivo_mes, tamFile);
	fprintf(mes_organizado_todas_ord, "Ordenação por Fusão Direta: \n");
	printarArquivo(arquivo_mes, tamFile, mes_organizado_todas_ord);
	fprintf(mes_organizado_todas_ord, "\n\n\n");
	
	fprintf(resultado, "Ordenação por Fusão Direta: \n");
	fprintf(resultado, "\tNúmero de Movimentações: %d \t Número de Comparações: %d\n\n",
	    numMovi, numComp);
	numMovi = 0;
	numComp = 0;
	insertOnArquivo(arquivo_mes, mes, tamFile); //reset situação do arquivo
	
	
	
	//Ord Quick
	ordQuick(arquivo_mes, tamFile);
	fprintf(mes_organizado_todas_ord, "Ordenação por Quick Sort: \n");
	printarArquivo(arquivo_mes, tamFile, mes_organizado_todas_ord);
	fprintf(mes_organizado_todas_ord, "\n\n\n");
	
	fprintf(resultado, "Ordenação por Quick Sort: \n");
	fprintf(resultado, "\tNúmero de Movimentações: %d \t Número de Comparações: %d\n\n",
	    numMovi, numComp);
	numMovi = 0;
	numComp = 0;
	insertOnArquivo(arquivo_mes, mes, tamFile); //reset situação do arquivo
	
	

	fprintf(resultado, "\n\n");
	fclose(mes);	
	fclose(mes_organizado_todas_ord);
	free(arquivo_mes);
	
	
	
	//MES 2
	fprintf(resultado, "Mes 2\n");
	
	mes = fopen("mes_2.txt", "r");
	mes_organizado_todas_ord = fopen("mesOrganizadoAllMethods_2.txt", "w");
	
	tamFile = numberOfLines(mes);
	
	arquivo_mes = malloc(tamFile * sizeof(Arquivo));
	
	insertOnArquivo(arquivo_mes, mes, tamFile);



	//Ord Insercao Direta
	ordInsercaoDir(arquivo_mes, tamFile);
	fprintf(mes_organizado_todas_ord, "Ordenação por Inserção Direta: \n");
	printarArquivo(arquivo_mes, tamFile, mes_organizado_todas_ord);
	fprintf(mes_organizado_todas_ord, "\n\n\n");
	
	fprintf(resultado, "Ordenação por Inserção Direta: \n");
	fprintf(resultado, "\tNúmero de Movimentações: %d \t Número de Comparações: %d\n\n",
		numMovi, numComp);
	numMovi = 0;
	numComp = 0;
	insertOnArquivo(arquivo_mes, mes, tamFile); //reset situação do arquivo
	


	//Ord Insercao Binaria
	ordInsercaoBin(arquivo_mes, tamFile);
	fprintf(mes_organizado_todas_ord, "Ordenação por Inserção Binaria: \n");
	printarArquivo(arquivo_mes, tamFile, mes_organizado_todas_ord);
	fprintf(mes_organizado_todas_ord, "\n\n\n");
	
	fprintf(resultado, "Ordenação por Inserção Binaria: \n");
	fprintf(resultado, "\tNúmero de Movimentações: %d \t Número de Comparações: %d\n\n",
		numMovi, numComp);
	numMovi = 0;
	numComp = 0;	
	insertOnArquivo(arquivo_mes, mes, tamFile); //reset situação do arquivo
	
	
	//Ord Selecao
	ordSelecao(arquivo_mes, tamFile);
	fprintf(mes_organizado_todas_ord, "Ordenação por Seleção: \n");
	printarArquivo(arquivo_mes, tamFile, mes_organizado_todas_ord);
	fprintf(mes_organizado_todas_ord, "\n\n\n");
	
	fprintf(resultado, "Ordenação por Seleção: \n");
	fprintf(resultado, "\tNúmero de Movimentações: %d \t Número de Comparações: %d\n\n",
		numMovi, numComp);
	numMovi = 0;
	numComp = 0;
	insertOnArquivo(arquivo_mes, mes, tamFile); //reset situação do arquivo
	
	
	//Ord BubbleSort
	ordBubble(arquivo_mes, tamFile);
	fprintf(mes_organizado_todas_ord, "Ordenação por Bubble Sort: \n");
	printarArquivo(arquivo_mes, tamFile, mes_organizado_todas_ord);
	fprintf(mes_organizado_todas_ord, "\n\n\n");
	
	fprintf(resultado, "Ordenação por Bubble Sort: \n");
	fprintf(resultado, "\tNúmero de Movimentações: %d \t Número de Comparações: %d\n\n",
	    numMovi, numComp);
	numMovi = 0;
	numComp = 0;
	insertOnArquivo(arquivo_mes, mes, tamFile); //reset situação do arquivo
	
	
	//Ord Heap
	ordHeap(arquivo_mes, tamFile);
	fprintf(mes_organizado_todas_ord, "Ordenação por Heap Sort: \n");
	printarArquivo(arquivo_mes, tamFile, mes_organizado_todas_ord);
	fprintf(mes_organizado_todas_ord, "\n\n\n");
	
	fprintf(resultado, "Ordenação por Heap Sort: \n");
	fprintf(resultado, "\tNúmero de Movimentações: %d \t Número de Comparações: %d\n\n",
	    numMovi, numComp);
	numMovi = 0;
	numComp = 0;
	insertOnArquivo(arquivo_mes, mes, tamFile); //reset situação do arquivo
	
	
	//Ord Fusao
	ordMerge(arquivo_mes, tamFile);
	fprintf(mes_organizado_todas_ord, "Ordenação por Fusão Direta: \n");
	printarArquivo(arquivo_mes, tamFile, mes_organizado_todas_ord);
	fprintf(mes_organizado_todas_ord, "\n\n\n");
	
	fprintf(resultado, "Ordenação por Fusão Direta: \n");
	fprintf(resultado, "\tNúmero de Movimentações: %d \t Número de Comparações: %d\n\n",
	    numMovi, numComp);
	numMovi = 0;
	numComp = 0;
	insertOnArquivo(arquivo_mes, mes, tamFile); //reset situação do arquivo
	
	
	//Ord Quick
	ordQuick(arquivo_mes, tamFile);
	fprintf(mes_organizado_todas_ord, "Ordenação por Quick Sort: \n");
	printarArquivo(arquivo_mes, tamFile, mes_organizado_todas_ord);
	fprintf(mes_organizado_todas_ord, "\n\n\n");
	
	fprintf(resultado, "Ordenação por Quick Sort: \n");
	fprintf(resultado, "\tNúmero de Movimentações: %d \t Número de Comparações: %d\n\n",
	    numMovi, numComp);
	numMovi = 0;
	numComp = 0;

	fprintf(resultado, "\n\n");
	fclose(mes);	
	fclose(mes_organizado_todas_ord);
	free(arquivo_mes);	
	insertOnArquivo(arquivo_mes, mes, tamFile); //reset situação do arquivo
	
	
	//MES 3
	fprintf(resultado, "Mes 3\n");
	
	mes = fopen("mes_3.txt", "r");
	mes_organizado_todas_ord = fopen("mesOrganizadoAllMethods_3.txt", "w");
	
	tamFile = numberOfLines(mes);
	
	arquivo_mes = malloc(tamFile * sizeof(Arquivo));
	
	insertOnArquivo(arquivo_mes, mes, tamFile);



	//Ord Insercao Direta
	ordInsercaoDir(arquivo_mes, tamFile);
	fprintf(mes_organizado_todas_ord, "Ordenação por Inserção Direta: \n");
	printarArquivo(arquivo_mes, tamFile, mes_organizado_todas_ord);
	fprintf(mes_organizado_todas_ord, "\n\n\n");
	
	fprintf(resultado, "Ordenação por Inserção Direta: \n");
	fprintf(resultado, "\tNúmero de Movimentações: %d \t Número de Comparações: %d\n\n",
		numMovi, numComp);
	numMovi = 0;
	numComp = 0;
	insertOnArquivo(arquivo_mes, mes, tamFile); //reset situação do arquivo


	//Ord Insercao Binaria
	ordInsercaoBin(arquivo_mes, tamFile);
	fprintf(mes_organizado_todas_ord, "Ordenação por Inserção Binaria: \n");
	printarArquivo(arquivo_mes, tamFile, mes_organizado_todas_ord);
	fprintf(mes_organizado_todas_ord, "\n\n\n");
	
	fprintf(resultado, "Ordenação por Inserção Binaria: \n");
	fprintf(resultado, "\tNúmero de Movimentações: %d \t Número de Comparações: %d\n\n",
		numMovi, numComp);
	numMovi = 0;
	numComp = 0;	
	insertOnArquivo(arquivo_mes, mes, tamFile); //reset situação do arquivo
	
	
	//Ord Selecao
	ordSelecao(arquivo_mes, tamFile);
	fprintf(mes_organizado_todas_ord, "Ordenação por Seleção: \n");
	printarArquivo(arquivo_mes, tamFile, mes_organizado_todas_ord);
	fprintf(mes_organizado_todas_ord, "\n\n\n");
	
	fprintf(resultado, "Ordenação por Seleção: \n");
	fprintf(resultado, "\tNúmero de Movimentações: %d \t Número de Comparações: %d\n\n",
		numMovi, numComp);
	numMovi = 0;
	numComp = 0;
	insertOnArquivo(arquivo_mes, mes, tamFile); //reset situação do arquivo
	
	
	//Ord BubbleSort
	ordBubble(arquivo_mes, tamFile);
	fprintf(mes_organizado_todas_ord, "Ordenação por Bubble Sort: \n");
	printarArquivo(arquivo_mes, tamFile, mes_organizado_todas_ord);
	fprintf(mes_organizado_todas_ord, "\n\n\n");
	
	fprintf(resultado, "Ordenação por Bubble Sort: \n");
	fprintf(resultado, "\tNúmero de Movimentações: %d \t Número de Comparações: %d\n\n",
	    numMovi, numComp);
	numMovi = 0;
	numComp = 0;
	insertOnArquivo(arquivo_mes, mes, tamFile); //reset situação do arquivo
	
	
	//Ord Heap
	ordHeap(arquivo_mes, tamFile);
	fprintf(mes_organizado_todas_ord, "Ordenação por Heap Sort: \n");
	printarArquivo(arquivo_mes, tamFile, mes_organizado_todas_ord);
	fprintf(mes_organizado_todas_ord, "\n\n\n");
	
	fprintf(resultado, "Ordenação por Heap Sort: \n");
	fprintf(resultado, "\tNúmero de Movimentações: %d \t Número de Comparações: %d\n\n",
	    numMovi, numComp);
	numMovi = 0;
	numComp = 0;
	insertOnArquivo(arquivo_mes, mes, tamFile); //reset situação do arquivo
	
	
	//Ord Fusao
	ordMerge(arquivo_mes, tamFile);
	fprintf(mes_organizado_todas_ord, "Ordenação por Fusão Direta: \n");
	printarArquivo(arquivo_mes, tamFile, mes_organizado_todas_ord);
	fprintf(mes_organizado_todas_ord, "\n\n\n");
	
	fprintf(resultado, "Ordenação por Fusão Direta: \n");
	fprintf(resultado, "\tNúmero de Movimentações: %d \t Número de Comparações: %d\n\n",
	    numMovi, numComp);
	numMovi = 0;
	numComp = 0;
	insertOnArquivo(arquivo_mes, mes, tamFile); //reset situação do arquivo
	
	
	//Ord Quick
	ordQuick(arquivo_mes, tamFile);
	fprintf(mes_organizado_todas_ord, "Ordenação por Quick Sort: \n");
	printarArquivo(arquivo_mes, tamFile, mes_organizado_todas_ord);
	fprintf(mes_organizado_todas_ord, "\n\n\n");
	
	fprintf(resultado, "Ordenação por Quick Sort: \n");
	fprintf(resultado, "\tNúmero de Movimentações: %d \t Número de Comparações: %d\n\n",
	    numMovi, numComp);
	numMovi = 0;
	numComp = 0;

	fprintf(resultado, "\n\n");
	fclose(mes);	
	fclose(mes_organizado_todas_ord);
	free(arquivo_mes);	
	insertOnArquivo(arquivo_mes, mes, tamFile); //reset situação do arquivo
	
	
	//MES 4
	fprintf(resultado, "Mes 4\n");
	
	mes = fopen("mes_4.txt", "r");
	mes_organizado_todas_ord = fopen("mesOrganizadoAllMethods_4.txt", "w");
	
	tamFile = numberOfLines(mes);
	
	arquivo_mes = malloc(tamFile * sizeof(Arquivo));
	
	insertOnArquivo(arquivo_mes, mes, tamFile);



	//Ord Insercao Direta
	ordInsercaoDir(arquivo_mes, tamFile);
	fprintf(mes_organizado_todas_ord, "Ordenação por Inserção Direta: \n");
	printarArquivo(arquivo_mes, tamFile, mes_organizado_todas_ord);
	fprintf(mes_organizado_todas_ord, "\n\n\n");
	
	fprintf(resultado, "Ordenação por Inserção Direta: \n");
	fprintf(resultado, "\tNúmero de Movimentações: %d \t Número de Comparações: %d\n\n",
		numMovi, numComp);
	numMovi = 0;
	numComp = 0;
	insertOnArquivo(arquivo_mes, mes, tamFile); //reset situação do arquivo


	//Ord Insercao Binaria
	ordInsercaoBin(arquivo_mes, tamFile);
	fprintf(mes_organizado_todas_ord, "Ordenação por Inserção Binaria: \n");
	printarArquivo(arquivo_mes, tamFile, mes_organizado_todas_ord);
	fprintf(mes_organizado_todas_ord, "\n\n\n");
	
	fprintf(resultado, "Ordenação por Inserção Binaria: \n");
	fprintf(resultado, "\tNúmero de Movimentações: %d \t Número de Comparações: %d\n\n",
		numMovi, numComp);
	numMovi = 0;
	numComp = 0;	
	insertOnArquivo(arquivo_mes, mes, tamFile); //reset situação do arquivo
	
	
	//Ord Selecao
	ordSelecao(arquivo_mes, tamFile);
	fprintf(mes_organizado_todas_ord, "Ordenação por Seleção: \n");
	printarArquivo(arquivo_mes, tamFile, mes_organizado_todas_ord);
	fprintf(mes_organizado_todas_ord, "\n\n\n");
	
	fprintf(resultado, "Ordenação por Seleção: \n");
	fprintf(resultado, "\tNúmero de Movimentações: %d \t Número de Comparações: %d\n\n",
		numMovi, numComp);
	numMovi = 0;
	numComp = 0;
	insertOnArquivo(arquivo_mes, mes, tamFile); //reset situação do arquivo
	
	
	//Ord BubbleSort
	ordBubble(arquivo_mes, tamFile);
	fprintf(mes_organizado_todas_ord, "Ordenação por Bubble Sort: \n");
	printarArquivo(arquivo_mes, tamFile, mes_organizado_todas_ord);
	fprintf(mes_organizado_todas_ord, "\n\n\n");
	
	fprintf(resultado, "Ordenação por Bubble Sort: \n");
	fprintf(resultado, "\tNúmero de Movimentações: %d \t Número de Comparações: %d\n\n",
	    numMovi, numComp);
	numMovi = 0;
	numComp = 0;
	insertOnArquivo(arquivo_mes, mes, tamFile); //reset situação do arquivo
	
	
	//Ord Heap
	ordHeap(arquivo_mes, tamFile);
	fprintf(mes_organizado_todas_ord, "Ordenação por Heap Sort: \n");
	printarArquivo(arquivo_mes, tamFile, mes_organizado_todas_ord);
	fprintf(mes_organizado_todas_ord, "\n\n\n");
	
	fprintf(resultado, "Ordenação por Heap Sort: \n");
	fprintf(resultado, "\tNúmero de Movimentações: %d \t Número de Comparações: %d\n\n",
	    numMovi, numComp);
	numMovi = 0;
	numComp = 0;
	insertOnArquivo(arquivo_mes, mes, tamFile); //reset situação do arquivo
	
	
	//Ord Fusao
	ordMerge(arquivo_mes, tamFile);
	fprintf(mes_organizado_todas_ord, "Ordenação por Fusão Direta: \n");
	printarArquivo(arquivo_mes, tamFile, mes_organizado_todas_ord);
	fprintf(mes_organizado_todas_ord, "\n\n\n");
	
	fprintf(resultado, "Ordenação por Fusão Direta: \n");
	fprintf(resultado, "\tNúmero de Movimentações: %d \t Número de Comparações: %d\n\n",
	    numMovi, numComp);
	numMovi = 0;
	numComp = 0;
	insertOnArquivo(arquivo_mes, mes, tamFile); //reset situação do arquivo
	
	
	//Ord Quick
	ordQuick(arquivo_mes, tamFile);
	fprintf(mes_organizado_todas_ord, "Ordenação por Quick Sort: \n");
	printarArquivo(arquivo_mes, tamFile, mes_organizado_todas_ord);
	fprintf(mes_organizado_todas_ord, "\n\n\n");
	
	fprintf(resultado, "Ordenação por Quick Sort: \n");
	fprintf(resultado, "\tNúmero de Movimentações: %d \t Número de Comparações: %d\n\n",
	    numMovi, numComp);
	numMovi = 0;
	numComp = 0;
	insertOnArquivo(arquivo_mes, mes, tamFile); //reset situação do arquivo
	
	
	
	fprintf(resultado, "\n\n");
	fclose(mes);	
	fclose(mes_organizado_todas_ord);
	free(arquivo_mes);	
	
	
	
	//MES 5
	fprintf(resultado, "Mes 5\n");
	
	mes = fopen("mes_5.txt", "r");
	mes_organizado_todas_ord = fopen("mesOrganizadoAllMethods_5.txt", "w");
	
	tamFile = numberOfLines(mes);
	
	arquivo_mes = malloc(tamFile * sizeof(Arquivo));
	
	insertOnArquivo(arquivo_mes, mes, tamFile);



	//Ord Insercao Direta
	ordInsercaoDir(arquivo_mes, tamFile);
	fprintf(mes_organizado_todas_ord, "Ordenação por Inserção Direta: \n");
	printarArquivo(arquivo_mes, tamFile, mes_organizado_todas_ord);
	fprintf(mes_organizado_todas_ord, "\n\n\n");
	
	fprintf(resultado, "Ordenação por Inserção Direta: \n");
	fprintf(resultado, "\tNúmero de Movimentações: %d \t Número de Comparações: %d\n\n",
		numMovi, numComp);
	numMovi = 0;
	numComp = 0;
	insertOnArquivo(arquivo_mes, mes, tamFile); //reset situação do arquivo
	
	

	//Ord Insercao Binaria
	ordInsercaoBin(arquivo_mes, tamFile);
	fprintf(mes_organizado_todas_ord, "Ordenação por Inserção Binaria: \n");
	printarArquivo(arquivo_mes, tamFile, mes_organizado_todas_ord);
	fprintf(mes_organizado_todas_ord, "\n\n\n");
	
	fprintf(resultado, "Ordenação por Inserção Binaria: \n");
	fprintf(resultado, "\tNúmero de Movimentações: %d \t Número de Comparações: %d\n\n",
		numMovi, numComp);
	numMovi = 0;
	numComp = 0;	
	insertOnArquivo(arquivo_mes, mes, tamFile); //reset situação do arquivo
	
	
	
	//Ord Selecao
	ordSelecao(arquivo_mes, tamFile);
	fprintf(mes_organizado_todas_ord, "Ordenação por Seleção: \n");
	printarArquivo(arquivo_mes, tamFile, mes_organizado_todas_ord);
	fprintf(mes_organizado_todas_ord, "\n\n\n");
	
	fprintf(resultado, "Ordenação por Seleção: \n");
	fprintf(resultado, "\tNúmero de Movimentações: %d \t Número de Comparações: %d\n\n",
		numMovi, numComp);
	numMovi = 0;
	numComp = 0;
	insertOnArquivo(arquivo_mes, mes, tamFile); //reset situação do arquivo
	
	
	
	//Ord BubbleSort
	ordBubble(arquivo_mes, tamFile);
	fprintf(mes_organizado_todas_ord, "Ordenação por Bubble Sort: \n");
	printarArquivo(arquivo_mes, tamFile, mes_organizado_todas_ord);
	fprintf(mes_organizado_todas_ord, "\n\n\n");
	
	fprintf(resultado, "Ordenação por Bubble Sort: \n");
	fprintf(resultado, "\tNúmero de Movimentações: %d \t Número de Comparações: %d\n\n",
	    numMovi, numComp);
	numMovi = 0;
	numComp = 0;
	insertOnArquivo(arquivo_mes, mes, tamFile); //reset situação do arquivo
	
	
	
	//Ord Heap
	ordHeap(arquivo_mes, tamFile);
	fprintf(mes_organizado_todas_ord, "Ordenação por Heap Sort: \n");
	printarArquivo(arquivo_mes, tamFile, mes_organizado_todas_ord);
	fprintf(mes_organizado_todas_ord, "\n\n\n");
	
	fprintf(resultado, "Ordenação por Heap Sort: \n");
	fprintf(resultado, "\tNúmero de Movimentações: %d \t Número de Comparações: %d\n\n",
	    numMovi, numComp);
	numMovi = 0;
	numComp = 0;
	insertOnArquivo(arquivo_mes, mes, tamFile); //reset situação do arquivo
	
	
	
	//Ord Fusao
	ordMerge(arquivo_mes, tamFile);
	fprintf(mes_organizado_todas_ord, "Ordenação por Fusão Direta: \n");
	printarArquivo(arquivo_mes, tamFile, mes_organizado_todas_ord);
	fprintf(mes_organizado_todas_ord, "\n\n\n");
	
	fprintf(resultado, "Ordenação por Fusão Direta: \n");
	fprintf(resultado, "\tNúmero de Movimentações: %d \t Número de Comparações: %d\n\n",
	    numMovi, numComp);
	numMovi = 0;
	numComp = 0;
	insertOnArquivo(arquivo_mes, mes, tamFile); //reset situação do arquivo
	
	
	
	//Ord Quick
	ordQuick(arquivo_mes, tamFile);
	fprintf(mes_organizado_todas_ord, "Ordenação por Quick Sort: \n");
	printarArquivo(arquivo_mes, tamFile, mes_organizado_todas_ord);
	fprintf(mes_organizado_todas_ord, "\n\n\n");
	
	fprintf(resultado, "Ordenação por Quick Sort: \n");
	fprintf(resultado, "\tNúmero de Movimentações: %d \t Número de Comparações: %d\n\n",
	    numMovi, numComp);
	numMovi = 0;
	numComp = 0;
	insertOnArquivo(arquivo_mes, mes, tamFile); //reset situação do arquivo
	
	
	
	fprintf(resultado, "\n\n");
	fclose(mes);	
	fclose(mes_organizado_todas_ord);
	free(arquivo_mes);	


	fclose(resultado);
	
	
	//PARTE 2 - BUSCA
	
	int quer = 0, exit = 0, aux = 0;
	Arquivo busca;
	FILE* mesOrganizado;

	//MES 1
	mes = fopen("mes_1.txt", "r");
	mesOrganizado = fopen("mes_organizado_1.txt", "w");
	
	tamFile = numberOfLines(mes);
	
	arquivo_mes = malloc(tamFile * sizeof(Arquivo));
	
	insertOnArquivo(arquivo_mes, mes, tamFile);
	
	ordQuick(arquivo_mes, tamFile);
	printarArq(arquivo_mes, tamFile, mesOrganizado);
	
	fclose(mes);	
	fclose(mesOrganizado);
	free(arquivo_mes);
	
	//MES 2
	mes = fopen("mes_2.txt", "r");
	mesOrganizado = fopen("mes_organizado_2.txt", "w");
	
	tamFile = numberOfLines(mes);
	
	arquivo_mes = malloc(tamFile * sizeof(Arquivo));
	
	insertOnArquivo(arquivo_mes, mes, tamFile);
	
	ordQuick(arquivo_mes, tamFile);
	printarArq(arquivo_mes, tamFile, mesOrganizado);
	
	fclose(mes);	
	fclose(mesOrganizado);
	free(arquivo_mes);
	
	//MES 3
	mes = fopen("mes_3.txt", "r");
	mesOrganizado = fopen("mes_organizado_3.txt", "w");
	
	tamFile = numberOfLines(mes);
	
	arquivo_mes = malloc(tamFile * sizeof(Arquivo));
	
	insertOnArquivo(arquivo_mes, mes, tamFile);
	
	ordQuick(arquivo_mes, tamFile);
	printarArq(arquivo_mes, tamFile, mesOrganizado);
	
	fclose(mes);	
	fclose(mesOrganizado);
	free(arquivo_mes);
	
	//MES 4
	mes = fopen("mes_4.txt", "r");
	mesOrganizado = fopen("mes_organizado_4.txt", "w");
	
	tamFile = numberOfLines(mes);
	
	arquivo_mes = malloc(tamFile * sizeof(Arquivo));
	
	insertOnArquivo(arquivo_mes, mes, tamFile);
	
	ordQuick(arquivo_mes, tamFile);
	printarArq(arquivo_mes, tamFile, mesOrganizado);
	
	fclose(mes);	
	fclose(mesOrganizado);
	free(arquivo_mes);
	
	//MES 5
	mes = fopen("mes_5.txt", "r");
	mesOrganizado = fopen("mes_organizado_5.txt", "w");
	
	tamFile = numberOfLines(mes);
	
	arquivo_mes = malloc(tamFile * sizeof(Arquivo));
	
	insertOnArquivo(arquivo_mes, mes, tamFile);
	
	ordQuick(arquivo_mes, tamFile);
	printarArq(arquivo_mes, tamFile, mesOrganizado);
	
	fclose(mes);	
	fclose(mesOrganizado);
	free(arquivo_mes);
	
	while(exit == 0)
	{
			printf("(1) - Buscar Codigo\n");
			printf("(X) - Sair\n");
			scanf("%d", &quer);
			printf("\n");
			
		switch(quer)
		{			
			case 1:
				
				printf("Codigo a ser buscado: \n");
				scanf("%s", &busca.codOp);
				busca.codOp[10] = '\0';
				printf("\n");
				
				mesOrganizado = fopen("mes_organizado_1.txt", "r");
				aux = buscarNoArquivo(busca, mesOrganizado, 1);
				
				mesOrganizado = fopen("mes_organizado_2.txt", "r");
				aux = buscarNoArquivo(busca, mesOrganizado, 2);
				
				mesOrganizado = fopen("mes_organizado_3.txt", "r");
				aux = buscarNoArquivo(busca, mesOrganizado, 3);
				
				mesOrganizado = fopen("mes_organizado_4.txt", "r");
				aux = buscarNoArquivo(busca, mesOrganizado, 4);
				
				mesOrganizado = fopen("mes_organizado_5.txt", "r");
				aux = buscarNoArquivo(busca, mesOrganizado, 5);
				
				break;
				
			default:
				exit = 1;
				break;
		}
	}
	
	
	
}

void printarArq(Arquivo *arq, int tamArq, FILE* file)
{
	for(int i = 1; i < tamArq; i++)
	{
		fprintf(file, "%s\n", arq[i].codOp);
	}
}

void printarArquivo(Arquivo *arq, int tamArq, FILE* file)
{
	for(int i = 1; i < tamArq; i++)
	{
		fprintf(file,"%3d - %s\n", i, arq[i].codOp);
	}
}

void insertOnArquivo(Arquivo *mes, FILE *file, int tamFile)
{
	int i = 1;
	char aux[11];
	char lixo[1];
	rewind(file);
	while(fread(aux, sizeof(char), 10, file) == 10)
	{
		aux[10] = '\0';
		strcpy(mes[i].codOp, aux);
		fread(lixo, sizeof(char), 1, file);
		i++;
	}
}

int numberOfLines(FILE *file)
{
	int counter = 0;
	char lixo[11];
	char lixo2[1];
	while(fread(lixo, sizeof(char), 10, file) == 10)
	{
		lixo[10] = '\0';
		fread(lixo2, sizeof(char), 1, file); //le o \n
		counter++;
	}
	return counter + 1;
}

void ordInsercaoDir(Arquivo *arq, int tamArq)
{
	int j = 0;
	Arquivo x;
	for(int i = 2; i < tamArq; i++)
	{
		numMovi += 2;
		x = arq[i];
		arq[0] = x;
		j = i;
		while(strcmp(arq[j-1].codOp, x.codOp) > 0)
		{
			numComp++;
			numMovi++;
			arq[j] = arq[j-1];
			j--;
		}
		numComp++;
		arq[j] = x;
	}
}

void ordInsercaoBin(Arquivo *arq, int tamArq)
{
	int L, R, j, m;
	Arquivo x;
	
	for(int i = 2; i < tamArq; i++)
	{
		numMovi++;
		x = arq[i];
		L = 1;
		R = i;
		
		while(L < R)
		{
			m = (L + R) / 2;
			
			if(strcmp(arq[m].codOp, x.codOp) < 0 || strcmp(arq[m].codOp, x.codOp) == 0)
			{
				numComp++;
				L = m + 1;
			}
			else
			{
				numComp++;
				R = m;
			}
		}
		j = i;
		while(j > R)
		{
			numMovi++;
			arq[j] = arq[j-1];
			j--;
		}
		numMovi++;
		arq[R] = x;
	}
}

void ordSelecao(Arquivo *arq, int tamArq)
{
	int menor;
	Arquivo x;
	
	for(int i = 1; i < tamArq - 1; i++) {
		menor = i;
		for(int j = (i + 1); j < tamArq; j++) {
			if(strcmp(arq[menor].codOp, arq[j].codOp) > 0)
			{
				numComp++;
				menor = j;
			}
			numComp++;
		}
		numMovi += 3;
		x = arq[i];
		arq[i] = arq[menor];
		arq[menor] = x;
	}		
}

void ordBubble(Arquivo *arq, int tamArq){
	
	Arquivo x;
	
	for(int i = 1; i < tamArq ; i++){
		for(int j = (tamArq - 1); j > i; j--){
			if(strcmp(arq[j-1].codOp, arq[j].codOp) > 0)
			{
				numMovi += 3;
				numComp++;
				x = arq[j-1];
				arq[j-1] = arq[j];
				arq[j] = x;
			}
			numComp++;
		}
	}
}

void ordMerge(Arquivo *arq, int tamArq){
	
	Arquivo *c;
    int p = 1;
	
	c = (Arquivo*)malloc(tamArq * sizeof(Arquivo));
    
    while(p < tamArq - 1){
        ordMerge_mpass_(arq, tamArq - 1, p, c);
        p = p*2;
        ordMerge_mpass_(c, tamArq - 1, p, arq);
        p = p*2;
    }   
}

void ordMerge_mpass_(Arquivo *arq, int tamArq, int p, Arquivo *c){
	
	int i = 1;

    while(i<=tamArq-2*p+1){
        ordMerge_merge_(arq, i, i+p-1, i+2*p-1 , c);
        i = i+2*p;
    }
    if (i+p-1 < tamArq){
        ordMerge_merge_(arq, i, i+p-1, tamArq, c);
    }
    else{
        for(int j = i; j <= tamArq; j++){
			numMovi++;
            c[j] = arq[j];
        }
    }
}

void ordMerge_merge_(Arquivo *arq, int L, int h, int R, Arquivo *c){
	
	int i = L;
    int j = h+1;
    int k = L-1;
    while(i <= h && j <= R){
        k++;
        if (strcmp(arq[i].codOp , arq[j].codOp) < 0){
			numComp++;
			numMovi++;
        	c[k] = arq[i];
            i++;
        }
        else{
			numComp++;
			numMovi++;
            c[k] = arq[j];
            j++;
        }
    }
    while(i <= h){
        k++;
		numMovi++;
        c[k] = arq[i];
        i++;
    }
    while(j <= R){
        k++;
		numMovi++;
        c[k] = arq[j];
        j++;
    }
}

void ordHeap_heapify_(Arquivo *arq, int L, int R){
	
	int i = L;
	int j = 2 * L;
	Arquivo x = arq[L];
	numMovi++;
	if((j < R) && (strcmp(arq[j].codOp, arq[j+1].codOp) < 0))
	{
		numComp++;
		j++;
	}
	numComp++;
	
	while((j <= R)&&(strcmp(x.codOp, arq[j].codOp) < 0)){
		numComp++;
		numMovi++;
		arq[i] = arq[j];
		i = j;
		j = 2 * j;
		if((j < R) && (strcmp(arq[j].codOp, arq[j+1].codOp) < 0))
		{
			numComp++;
			j++;
		}
		numComp++;
	}
	numComp++;
	numMovi++;
	arq[i] = x;
}

void ordHeap(Arquivo *arq, int tamArq){
	Arquivo x;
	for(int L = ((tamArq - 1)/2); L >= 1; L--)
	{
		ordHeap_heapify_(arq, L, (tamArq - 1));
	}
	for(int R = (tamArq - 1); R >= 2; R--)
	{
		numMovi += 3;
		x = arq[1];
		arq[1] = arq[R];
		arq[R] = x;
		ordHeap_heapify_(arq, 1, R-1);
	}
}

void ordQuick(Arquivo *arq, int tamArq){
	ordQuick_qsort_(arq, 1, tamArq - 1);
}

void ordQuick_qsort_(Arquivo *arq, int L, int R){
	int i = L;
	int j = R;
	Arquivo x = arq[(L + R)/2];
	Arquivo w;
	
	do{
		
		while(strcmp(arq[i].codOp, x.codOp) < 0)
		{
			numComp++;
			i++;
		}
		numComp++;
		
		while(strcmp(x.codOp, arq[j].codOp) < 0)
		{
			numComp++;
			j--;
		}
		numComp++;
		
			if(i <= j){
				numMovi += 3;
				w = arq[i];
				arq[i] = arq[j];
				arq[j] = w;
				i++;
				j--;
			}
	}while( i <= j);
	
	if(L < j)
		ordQuick_qsort_(arq, L, j);
	if (i < R)
		ordQuick_qsort_(arq, i ,R);
}

int buscaBinaria(Arquivo busca, Arquivo *arq, int tamArq)
{
	int L = 1, R = (tamArq - 1), m;
	
	while(L < R)
	{
		m = floor((R + L)/2);
		if(strcmp(busca.codOp, arq[m].codOp) > 0)
		{
			L = m + 1;
		}
		
		else
		{
			R = m;
		}
	}
	
	if(!strcmp(arq[R].codOp, busca.codOp))
	{
		return R;
	}
	else
	{
		return -1;
	}
}

int buscarNoArquivo(Arquivo busca, FILE* mesO, int mes)
{
	int tamArq;
	int aux;
	Arquivo *arq;
	tamArq = numberOfLines(mesO);
	arq = malloc(tamArq * sizeof(Arquivo));
	insertOnArquivo(arq, mesO, tamArq);
	aux = buscaBinaria(busca, arq, tamArq);
	
	if(aux == -1)
		printf("Codigo nao encontrado no mes %d\n\n", mes);
	else
		printf("Codigo encontrado: \nMes: %d\tIndices: ", mes);
		for(int i = aux; !strcmp(arq[i].codOp, busca.codOp); i++)
			printf("%d,", i);
		printf("\n\n");
}