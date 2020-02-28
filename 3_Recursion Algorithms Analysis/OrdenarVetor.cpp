/*
#########################################################################
#					UFC - Quixadá - Novembro 2019						#
#				ESTRUTURA DE DADOS										#
#	Atividade 5 - Trabalho 3 											#
#																		#
#	Equipe: Henricky de Lima Monteiro (475075) - HenrickyL1@gmail.com 	#
#			Elibe Soares Santos (470820) 								#
#										 								#
#	Professor: Atílio Gomes												#
#				::Tempo dos Algoritmos de Ordenação::					#
#########################################################################
*/
#include <iostream>
#include <chrono>
#include "OrdenarVetor.h"

void printVec(int *v,int n){
	std::cout<<"\t";
	for(int i =0; i<n;i++){
		std::cout<<v[i]<<" ";
	}std::cout<<"\n";
}


// ::BUBBLE_SORT::

	// *Interativo##########################################3
void bubbleSort_interative(int *A, int n) {
	for (int i = n-1; i >= 0; i--)
		for (int j = 0; j<i; j++)
			if (A[j] > A[j+1])
				std::swap(A[j],A[j+1]);
}
double TimeBubbleInterative(int *v, int n){
	std::cout<<"\tBUBBLE_Interative:\n";
	int vec[n];
	for(int i=0;i<n;i++){
		vec[i]=v[i];
	}
	//usar a copia no vetor e retornar o tempo
	auto ini = std::chrono::high_resolution_clock::now();
	
	//metodo
	bubbleSort_interative(vec,n);

	auto fim = std::chrono::high_resolution_clock::now();
	auto d = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
	std::cout<<"\n\ttime: "<<(double) d/1000000<<" seg\n";
	//printVec(vec, n);
	return (double)d;
}
//###########################################################
//RECURSIVO ***************************************

/*
	*função auxiliar que percorre de n até um i trocando os valores
*/
void auxBbSR(int v[], int n, int i = 0){ //auxiliar Bubble
	if(i < n){
		if(v[i] > v[i+1])
			std::swap(v[i],v[i+1]);
		auxBbSR(v,n,i+1);
	}
}
void bubbleSort_recursive(int v[],int n){
	if(n>0){
		auxBbSR(v,n-1);
		bubbleSort_recursive(v,n-1);
	}
}

double TimeBubbleRecursive(int *v, int n){
	std::cout<<"\tBUBBLE_Recursive:\n";
	int vec[n];
	for(int i=0;i<n;i++){
		vec[i]=v[i];
	}
	auto ini = std::chrono::high_resolution_clock::now();
	
	bubbleSort_recursive(vec,n);

	auto fim = std::chrono::high_resolution_clock::now();
	auto d = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
	std::cout<<"\n\ttime: "<<(double) d/1000000<<" seg\n";
	return (double)d;
}


//************************************************
//::INSERTION::
void insertionsort_Interative(int A[], int n) {
	int i, j, key;
	for (j = 1; j < n; j++) {
		key = A[j];
		i = j-1;
		while (i >= 0 && A[i] > key) {
			A[i+1] = A[i];
			i--;
		}
		A[i+1] = key;
	}
}
double TimeInsertionInterative(int *v, int n){
	std::cout<<"\tINSERTION_Interative:\n";
	int vec[n];
	for(int i=0;i<n;i++){
		vec[i]=v[i];
	}
	//usar a copia no vetor e retornar o tempo
	auto ini = std::chrono::high_resolution_clock::now();
	
	//metodo
	insertionsort_Interative(vec,n);

	auto fim = std::chrono::high_resolution_clock::now();
	auto d = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
	std::cout<<"\n\ttime: "<<(double) d/1000000<<" seg\n";
	//printVec(vec, n);
	return (double)d;
}
// Recursivo


// função que percorre do index ao zero trocando os menores
void auxInsertion(int *v, int i){
	if(i>=1){
		if(v[i]<v[i-1]){
			std::swap(v[i],v[i-1]);
		}
		auxInsertion(v,i-1);

	}
}
void insertionSort_Recursive(int *v,int n, int index = 0){
	if(index < n-1){
		if(v[index]>v[index+1]){
			auxInsertion(v,index+1); 
		}
		insertionSort_Recursive(v,n,index+1);
	}
}
double TimeInsertionRecursive(int *v, int n){
	std::cout<<"\tINSERTION_Recursive:\n";
	int vec[n];
	for(int i=0;i<n;i++){
		vec[i]=v[i];
	}
	//usar a copia no vetor e retornar o tempo
	auto ini = std::chrono::high_resolution_clock::now();
	
	//metodo
	insertionSort_Recursive(vec,n);

	auto fim = std::chrono::high_resolution_clock::now();
	auto d = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
	std::cout<<"\n\ttime: "<<(double) d/1000000<<" seg\n";
	//printVec(vec, n);
	return (double)d;
}

// SELECTION_SORT --------------------------------------------
	// Interative

void selectionsort_Interative(int v[], int n) {
	for (int i = 0; i < n-1; i++) {
		int min = i;
		for (int j = i+1; j < n; j++)
			if(v[j] < v[min])
			min = j;
			std:: swap(v[i],v[min]);
	}
}

double TimeSelectionInterative(int *v, int n){
	std::cout<<"\tSELECTION_Interative:\n";
	int vec[n];
	for(int i=0;i<n;i++){
		vec[i]=v[i];
	}
	//usar a copia no vetor e retornar o tempo
	auto ini = std::chrono::high_resolution_clock::now();
	
	//metodo
	selectionsort_Interative(vec, n);

	auto fim = std::chrono::high_resolution_clock::now();
	auto d = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
	std::cout<<"\n\ttime: "<<(double) d/1000000<<" seg\n";
	//printVec(vec, n);
	return (double)d;
}

	//Recursive-------------------------

int IndexMin(int *v,int i, int j){
	if(i == j) return i;
	else{
		int k = IndexMin(v,i+1,j);
		return (v[i]<v[k] ? i : k);
	}
}

void selectionsort_Recursive(int *v,int n, int index = 0){
	if(index < n){
		int min = IndexMin(v,index,n-1); //procurar o menor
		if(v[index]>v[min]) std::swap(v[index],v[min]);
		selectionsort_Recursive(v,n, index + 1);
	}
}
double TimeSelectionRecursive(int *v, int n){
	std::cout<<"\tSELECTION_Recursive:\n";
	int vec[n];
	for(int i=0;i<n;i++){
		vec[i]=v[i];
	}
	//usar a copia no vetor e retornar o tempo
	auto ini = std::chrono::high_resolution_clock::now();
	
	//metodo
	selectionsort_Recursive(vec, n);

	auto fim = std::chrono::high_resolution_clock::now();
	auto d = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
	std::cout<<"\n\ttime: "<<(double) d/1000000<<" seg\n";
	//printVec(vec, n);
	return (double)d;
}

//-------------------------------------------------------------

//MergeSort
	//Recursivo
void intercala(int *A, int p ,int q, int r){
		int *vetor_aux = new int [r-p+1];
		int j = p;
		int k =0;
		int i = q+1;
		while(j<=q && i<=r){
				if(A[j]>=A[i]) vetor_aux[k++]=A[i++];
				else vetor_aux[k++]=A[j++]; 
 		}
 		while(i<=r) vetor_aux[k++]=A[i++];
 		while(j<=q) vetor_aux[k++]=A[j++];
 		for(int s =p;s<=r;s++){
				A[s]=vetor_aux[s-p];
		}
		delete []vetor_aux;
}
void mergeSortRecursive(int *A, int p,int r){
	if (p < r) {
		int q = (p + r) / 2;
		mergeSortRecursive(A, p, q);
		mergeSortRecursive(A, q + 1, r);
		intercala(A, p, q, r);
	}
}
double TimeMergeRecursive(int *v, int n){
	std::cout<<"\tMerge_Recursive:\n";
	int vec[n];
	for(int i=0;i<n;i++){
		vec[i]=v[i];
	}
	//usar a copia no vetor e retornar o tempo
	auto ini = std::chrono::high_resolution_clock::now();
	
	//metodo
	mergeSortRecursive(vec, 0,n-1); 

	auto fim = std::chrono::high_resolution_clock::now();
	auto d = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
	std::cout<<"\n\ttime: "<<(double) d/1000000<<" seg\n";
	//printVec(vec, n);
	return (double)d;
}
	//interativo

void mergeSortInterative(int *A, int n){
	int ini=0,fim;
  	int jump=1;
	while(jump<n){
	    while(ini+jump<n){
	      fim = ini+ 2*jump-1;
	      if(fim>=n) fim = n-1;
	      intercala(A, ini, ini+jump, fim);
	      ini = ini+2*jump;
	    }
	    jump*=2; 
	}
}
double TimeMergeInterative(int *v, int n){
	std::cout<<"\tMerge_Interative:\n";
	int vec[n];
	for(int i=0;i<n;i++){
		vec[i]=v[i];
	}
	//usar a copia no vetor e retornar o tempo
	auto ini = std::chrono::high_resolution_clock::now();
	
	//metodo
	mergeSortInterative(vec, n); 

	auto fim = std::chrono::high_resolution_clock::now();
	auto d = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
	std::cout<<"\n\ttime: "<<(double) d/1000000<<" seg\n";
	//printVec(vec, n);
	return (double)d;
}

//HeapSort
	//interativo
void constroi_heap(int *A, int n){
  for(int i=1;i<=n;i++){
    int  f =i+1;
    while(f>1 && A[(f/2)-1]<A[f-1]){
        std::swap(A[(f/2)-1],A[f-1]);
        f/=2;
    }
  }
}
void peneira(int *A,int n){
  int f=1;
  while(f<n){
    if(f<n-1 && A[f]<A[f+1]) f++;
    if(f%2==0){
		if(A[(f/2)-1]>= A[f]) break;
		std::swap(A[(f/2)-1],A[f]);
		f*=2;  
      }
      else{
			if(A[(f/2)]>= A[f]) break;
			int aux = A[(f/2)];
			A[f/2] = A[f];
			A[f] = aux; 
			f*=2;
		}
	}
}
void heapsortInterative(int *A, int n){
  constroi_heap(A,n);
  for(int i=n;i>1;i--){
	std::swap(A[0],A[i-1]);
	peneira(A,i-1);
 }
}
double TimeHeapInterative(int *v, int n){
	std::cout<<"\tHEAP_Interative:\n";
	int vec[n];
	for(int i=0;i<n;i++){
		vec[i]=v[i];
	}
	//usar a copia no vetor e retornar o tempo
	auto ini = std::chrono::high_resolution_clock::now();
	
	//metodo
	heapsortInterative(vec, n); 

	auto fim = std::chrono::high_resolution_clock::now();
	auto d = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
	std::cout<<"\n\ttime: "<<(double) d/1000000<<" seg\n";
	//printVec(vec, n);
	return (double)d;
}
	//Recursive
void heapsortRecursive(int  *A, int n, bool e = true){
	if(n<1)return;
		if(e==true){
			constroi_heap(A,n);
		}
		std::swap(A[0],A[n-1]);
		peneira(A, n-1);
		heapsortRecursive(A,n-1,false);
}
double TimeHeapRecursive(int *v, int n){
	std::cout<<"\tHEAP_Recursive:\n";
	int vec[n];
	for(int i=0;i<n;i++){
		vec[i]=v[i];
	}
	//usar a copia no vetor e retornar o tempo
	auto ini = std::chrono::high_resolution_clock::now();
	
	//metodo
	heapsortRecursive(vec,n); 

	auto fim = std::chrono::high_resolution_clock::now();
	auto d = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
	std::cout<<"\n\ttime: "<<(double) d/1000000<<" seg\n";
	//printVec(vec, n);
	return (double)d;
}


//QuickSort

 
	//Interativo
//sem pesquisar ou copiar códigos externos não consegui fazer;
	//Recursivo
////

int particiona (int *A, int p, int r) {
	int c = A[r];
	int j = p;
	for (int k = p; k < r; k++) {
		if (A[k] <= c) {
			std :: swap(A[k], A[j]);
			j++;
		}
	}
	A[r] = A[j];
	A[j] = c;
	return j;
}
void quickSortRecursivo(int *A, int p, int r) {
	if (p < r) {
		int i = particiona(A, p, r);
		quickSortRecursivo(A, p, i-1);
		quickSortRecursivo(A, i+1, r);
	}
}
////
/*
int particiona(int *v, int ini, int fim) { 
    int pivo, esq,dir;
    esq= ini;
    dir = fim;
    pivo = v[ini];
    while(dir>esq){
    	//ver esquerda
    	while(v[dir]>pivo) dir--;
    	//ver direita
    	while(v[esq]<=pivo) esq++;
    	//processo de troca de lados
    	if(dir>esq){
    		std::swap(v[esq],v[dir]);
    	}
    }
    v[ini] = v[dir];
    v[dir] = pivo;
    return dir;	
} 
void quickSortRecursivo(int *v, int ini, int fim){ 
    if (ini< fim) { 
       //particiona
        int pivo = particiona(v, ini, fim); 
        quickSortRecursivo(v, ini, pivo - 1);//olhar direita 
        quickSortRecursivo(v, pivo + 1, fim); //olhar esquerda
    } 
} */
double TimeQuickRecursive(int *v, int n){
	std::cout<<"\tQUICK_Recursive:\n";
	int vec[n];
	for(int i=0;i<n;i++){
		vec[i]=v[i];
	}
	//usar a copia no vetor e retornar o tempo
	auto ini = std::chrono::high_resolution_clock::now();
	
	//metodo
	quickSortRecursivo(vec, 0, n-1); 

	auto fim = std::chrono::high_resolution_clock::now();
	auto d = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
	std::cout<<"\n\ttime: "<<(double) d/1000000<<" seg\n";
	//printVec(vec, n);
	return (double)d;
}
 


  




//Usar em todos
/*
double TimeSelectionInterative(int *v, int n){
	std::cout<<"Selection_Interative:\n";
	int vec[n];
	for(int i=0;i<n;i++){
		vec[i]=v[i]
	}
	//usar a copia no vetor e retornar o tempo
	auto ini = std::chrono::high_resolution_clock::now();
	
	//metodo
	selectionsort_Recursive(vec, n);

	auto fim = std::chrono::high_resolution_clock::now();
	auto d = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
	std::cout<<"\n\ttime: "<<(double) d/1000000<<" seg\n";
	void printVec(v,n)
	return (double)d;
}

*/
