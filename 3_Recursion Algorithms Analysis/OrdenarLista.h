
/*
#########################################################################
#					UFC - Quixadá - Novembro 2019						#
#				ESTRUTURA DE DADOS										#
#	Atividade 5 - Trabalho 3 											#
#																		#
#	Equipe: Henricky de Lima Monteiro (475075) - HenrickyL1@gmail.com 	#
#			Elibe Soares Santos (470820) 								#
#																		#
#	Professor: Atílio Gomes												#
#				::Tempo dos Algoritmos de Ordenação::					#
#########################################################################
*/
#ifndef ORD_LIST_H
#define ORD_LIST_H
#include "List/QX_List.h"


void swapList(Node *A,Node *B);
//BubbleSort
void BubbleSortList(QX_List *l);
double TimeBubbleList(QX_List *lista);
//InsertionSort
void inserction_sort(QX_List *l);
double TimeInsertionList(QX_List *lista);
//SelectionSort
Node** cria_vector(QX_List *l);
void selectionSortList(QX_List *l);
double TimeSelectionList(QX_List *lista);
//QuickSort
int particiona(Node **v, int ini, int fim);
void AuxQuickSortList(Node **v, int ini, int fim);
void QuickSortList(QX_List *l);
double TimeQuickList(QX_List *lista);
//MergeSorte
void intercala(Node **A, int p ,int q, int r);
void merge_sortaux(Node **lista , int p,int r);
void merge_sort(QX_List *lista);
double TimeMergeList(QX_List *lista);

//HeapSort
void constroi_heap(Node **A,int n);
void peneira(Node **A, int n);
void Auxheapsort(Node **A, int n);
void heapsort(QX_List *l);
double TimeHeapList(QX_List *lista);


#endif