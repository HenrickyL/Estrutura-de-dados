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

#include <iostream>
#include <chrono>
#include "List/QX_List.h"
#include "OrdenarLista.h"



/* 
	*Lista duplamente encadeada

*/

//troca nós
void swapList(Node *A,Node *B){
	Node* Aback = A->back;
	Node* Anext = A->next;
	Node* Bback = B->back;
	Node* Bnext = B->next;
	//caso do B depois de A
	if(A->next == B){
		Bnext = B->next;
		Aback = A->back;
		B->next = A;
		A->back = B;
		A->next = Bnext;
		B->back = Aback;
		//ajuste
		Aback->next = B;
		Anext->back = A;
	//Cado do A depois de B
	}else if(B->next == A ){
		Anext = A->next;
		Bback = B->back;
		A->next = B;
		B->back = A;
		A->back = Bback;
		B->next = Anext;
		//ajuste
		Aback->next = A;
		Anext->back = B;
	//outros
	}else{	
		Aback = A->back;
		Anext = A->next;
		Bback = B->back;
		Bnext = B->next;
		//troca
		B->next = Anext;
		B->back = Aback;
		A->next = Bnext;
		A->back = Bback;
		//ajustes
		Aback->next = B; // anterior tem que apontar para ele
		Anext->back = B;
		Bnext->back = A; 
		Bback->next = A;
	}
}



//BubbleSort

void BubbleSortList(QX_List *l){
	Node* head = l->getHead();
	Node* aux= head;
	
	while(aux->next->next != head){
		Node* atual = head;
		Node* prox = atual->next;
		while(atual->next != head){
			if(atual->value > prox->value){
				int k = atual->value;
				atual->value = prox->value;
				prox->value = k;
			}
			atual = atual->next;
			prox = prox->next;



		}aux = aux->next;
	}
}
double TimeBubbleList(QX_List *lista){
	std::cout<<"\tBUBBLE_LIST:\n";
	QX_List *l = lista->copy();
	
	//usar a copia no vetor e retornar o tempo
	auto ini = std::chrono::high_resolution_clock::now();
	
	//metodo
	BubbleSortList(l);

	auto fim = std::chrono::high_resolution_clock::now();
	auto d = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
	std::cout<<"\n\ttime: "<<(double) d/1000000<<" seg\n";
	return (double)d;
}

//InsertionSort
void inserction_sort(QX_List *l){
	Node *aux= l->getHead();
	for(aux= aux->next->next; aux!=l->getHead() ; aux=aux->next){
			int x=aux->value;
			Node *ant;
			for(ant= aux->back;  ant!=l->getHead()  && ant->value>x ;ant = ant->back){	
						ant->next->value = ant->value;
				}
				ant->next->value = x; 
			}
}
double TimeInsertionList(QX_List *lista){
	std::cout<<"\tINSERTION_LIST:\n";
	QX_List *l = lista->copy();
	
	//usar a copia no vetor e retornar o tempo
	auto ini = std::chrono::high_resolution_clock::now();
	
	//metodo
	inserction_sort(l);

	auto fim = std::chrono::high_resolution_clock::now();
	auto d = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
	std::cout<<"\n\ttime: "<<(double) d/1000000<<" seg\n";
	return (double)d;
}

//SelectionSort
Node** cria_vector(QX_List *l){
	Node* aux = l->getHead()->next;	
	Node* *v= new Node *[l->size()];
	int i=0;
	while(aux != l->getHead()){
		v[i] = aux;
		i++;
		aux = aux->next;
	}
	return v;
}
void selectionSortList(QX_List *l){
	int min,n = l->size();
	Node** v = cria_vector(l);
	for(int i=0;i<n-1;i++){
		min = i;
		for(int j =i+1;j<n;j++){
			if(v[j]->value < v[min]->value) {				
				min = j;
			}
		}
		swapList(v[i],v[min]);		
		Node* u = v[i];
		v[i] = v[min];
		v[min] = u;
	}
	delete v;
}
double TimeSelectionList(QX_List *lista){
	std::cout<<"\tSELECTION_LIST:\n";
	QX_List *l = lista->copy();
	
	//usar a copia no vetor e retornar o tempo
	auto ini = std::chrono::high_resolution_clock::now();
	
	//metodo
	selectionSortList(lista);

	auto fim = std::chrono::high_resolution_clock::now();
	auto d = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
	std::cout<<"\n\ttime: "<<(double) d/1000000<<" seg\n";
	
	return (double)d;
}

//MergeSort
	//Recursivo

void intercala(Node **A, int p ,int q, int r){
		Node **vetor_aux = new Node *[r-p+1];
		int j = p;
		int k =0;
		int i = q+1;
		while(j<=q && i<=r){
				if(A[j]->value >=A[i]->value) {
					vetor_aux[k++]=A[i++];
				}
				else vetor_aux[k++]=A[j++]; 
 		}
 		while(i<=r) vetor_aux[k++]=A[i++];
 		while(j<=q) vetor_aux[k++]=A[j++];
 		int vetor[r-p+1];
 		for(int r=p ;r<=r;r++){
				vetor[r]=vetor_aux[r-p]->value;
		}
 		for(int s =p;s<=r;s++){
				A[s]->value=vetor[s-p];
		}
		delete *vetor_aux;
}
void merge_sortaux(Node **lista , int p,int r){
	if (p < r) {
		int q = (p + r) / 2;
		  merge_sortaux(lista, p, q);
		  merge_sortaux(lista, q + 1, r);
		  intercala(lista, p, q, r);
    }
}
void merge_sort(QX_List *lista){
	Node *aux = lista->getHead();
	Node **vetor = new Node*[lista->size()];
	aux = aux->next;
	int i =0;
	while(aux!=lista->getHead()){
			vetor[i]= aux;
			i++;
	}
	merge_sortaux(vetor,0,lista->size()-1);
}
double TimeMergeList(QX_List *lista){
	std::cout<<"\tMerge_LIST:\n";
	QX_List *l = lista->copy();
	
	//usar a copia no vetor e retornar o tempo
	auto ini = std::chrono::high_resolution_clock::now();
	
	//metodo
	merge_sort(lista);

	auto fim = std::chrono::high_resolution_clock::now();
	auto d = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
	std::cout<<"\n\ttime: "<<(double) d/1000000<<" seg\n";
	
	return (double)d;
}

//HeapSort
void swapList(Node **A, int a, int b){
	if(A[a+1]==A[b]){
		Node *aux = A[a];
		Node *aux2 = A[b];
		aux->back->next = A[b];
		aux2->next->back = A[a];
		aux = A[a]->back;
		aux2 = A[b]->next;
		A[b]->back = aux;
		A[a]->next = aux2;
		A[b]->next = A[a];
		A[a]->back= A[b];
		Node *aux3 = A[a];
		A[a] = A[b];
		A[b] = aux3; 
		}
		//Verificação se Sãpo COnsecutivos no vetor ou não;
		Node *aux = A[b];
		Node *aux2 = A[a];
		aux->next->back = A[a];
		aux2->back->next = A[b];
		A[a]->back = A[b]->back;
		A[b]->next = A[a]->next;
		A[a]->next = aux->next;
		A[b]->back = aux2->back;
		Node *aux3 = A[a];
		A[a] = A[b];
		A[b] = aux3;
}
void constroiHeap(Node **A, int n){
		for(int i=1;i<=n;i++){
				int f =i+1;
				while(f>1 && A[(f/2)-1]->value < A[f-1]->value){
						swapList(A,(f/2)-1,f-1);
				}
		}
}
void peneira(Node **A , int n){
	int f=1;
	while(f<n){
    if(f < n-1 && A[f]->value <A[f+1]->value ) f++;
    if(f%2==0){
      if(A[(f/2)-1]->value >= A[f]->value) break;
      swapList(A,(f/2)-1,f);
      f*=2;  
      }else{
        if(A[(f/2)]->value >= A[f]->value) break;
        swapList(A,f/2,f);
		f*=2;
    }
  }
}
void heapsort_aux(Node **A, int n){
		constroiHeap(A,n);
		for(int i=n;i>1;i--){
				swapList(A,0,i-1);
				peneira(A,i-1);
		}
}
void heapsort(QX_List *lista){
		Node *aux= lista->getHead()->next;
		Node **A = new Node*[lista->size()];
		int i=0;
		while(aux!=lista->getHead()){
			A[i] = aux;
			i++;
		}
		heapsort_aux(A,lista->size());
}

double TimeHeapList(QX_List *lista){
	std::cout<<"\tHeap_LIST:\n";
	QX_List *l = lista->copy();
	
	//usar a copia no vetor e retornar o tempo
	auto ini = std::chrono::high_resolution_clock::now();
	
	//metodo
	heapsort(lista);

	auto fim = std::chrono::high_resolution_clock::now();
	auto d = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
	std::cout<<"\n\ttime: "<<(double) d/1000000<<" seg\n";
	
	return (double)d;
}

//QuickSort

int particiona(Node **v, int ini, int fim) { 
    int esq,dir;
    Node* pivo;
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
    		swapList(v[esq],v[dir]);
    	}
    }
    v[ini] = v[dir];
    v[dir] = pivo;
    return dir;	
} 
void AuxQuickSortList(Node **v, int ini, int fim){ 
    if (ini< fim) { 
       //particiona
        int pivo = particiona(v, ini, fim); 
        AuxQuickSortList(v, ini, pivo - 1);//olhar direita 
        AuxQuickSortList(v, pivo + 1, fim); //olhar esquerda
    }
} 
void QuickSortList(QX_List *l){
	int n = l->size();
	Node** v = cria_vector(l);
	AuxQuickSortList(v, 0,n-1 );
}
double TimeQuickList(QX_List *lista){
	std::cout<<"\tQUICK_LIST:\n";
	QX_List *l = lista->copy();
	
	//usar a copia no vetor e retornar o tempo
	auto ini = std::chrono::high_resolution_clock::now();
	
	//metodo
	QuickSortList(lista);

	auto fim = std::chrono::high_resolution_clock::now();
	auto d = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
	std::cout<<"\n\ttime: "<<(double) d/1000000<<" seg\n";
	
	return (double)d;
}
