/*
#########################################################################
#					UFC - Quixadá - Novembro 2019						#
#				ESTRUTURA DE DADOS										#
#	Atividade 5 - Trabalho 3 											#
#																		#
#	Equipe: Henricky de Lima Monteiro (475075) - HenrickyL1@gmail.com 	#
#			Elibe Soares Santos (470820) 								#
#	 																	#
#	Professor: Atílio Gomes												#
#				::Tempo dos Algoritmos de Ordenação::					#
#########################################################################
*/
#ifndef ORD_VEC_H
#define ORD_VEC_H


void printVec(int *v,int n);
//Bubble
	//interative
void bubbleSort_interative(int A[], int n);
double TimeBubbleInterative(int *v, int n);
	//Recursive
void auxBbSR(int v[], int fim, int index);
void bubbleSort_recursive(int v[],int n);
double TimeBubbleRecursive(int *v, int n);

//Insertion
	//interativo
void insertionsort_Interative(int A[], int n);
double TimeInsertionInterative(int *v, int n);
	//recursivo
void auxInsertion(int *v, int i);
void insertionSort_Recursive(int *v,int n, int index);
double TimeInsertionRecursive(int *v, int n);

//SelectionSort
void selectionsort_Interative(int v[], int n);
double TimeSelectionInterative(int *v, int n);
int IndexMin(int *v,int i, int j);
void selectionsort_Recursive(int *v,int n,int index);
double TimeSelectionRecursive(int *v, int n);


//Quick
	//Recursivo
int particiona(int *v, int ini, int fim);
void quickSortRecursivo(int *v, int ini, int fim);
double TimeQuickRecursive(int *v, int n);

//Heap
	//interativo
void constroi_heap (int A[], int n);
void peneira (int *A, int n);
void heapsortInterative(int  *A, int n);
double TimeHeapInterative(int *v, int n);
	//recursivo
void heapsortRecursive(int  *A, int n, bool e);
double TimeHeapRecursive(int *v, int n);

//Merge
void intercala(int *A, int p ,int q, int r);
	//interativo
void mergeSortInterative(int *A, int n);
double TimeMergeInterative(int *v, int n);
	//recursivo
void mergeSortRecursive(int *A, int p,int r);
double TimeMergeRecursive(int *v, int n);
#endif