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
#include <chrono> //tempo
#include "List/QX_List.cpp"
#include <string>
#include "OrdenarVetor.h"
#include "OrdenarLista.h"
#include <cstdlib> // aleatorio
#include <fstream> //arquivos
using namespace std;
//Global
const int tam[] = {1000,5000,10000,50000,100000,500000,1000000};
int TOTAL_N = sizeof(tam)/sizeof(tam[0]); 

//função que gera um vetor aleatório apartir de um inteiro N

//printVec(v,n);

int main(){
	/*
	srand(time(NULL));
	int n;
	std::cin>>n;
	int v[n];
	for(int i=0;i<n;i++){ // for para gerar os valores
		v[i] = rand();
	}
	//int n = sizeof(v)/sizeof(int);

	//TimeBubbleInterative(v,n);
	//TimeInsertionInterative(v, n);
	//TimeSelectionInterative(v, n);
	std::cout<<"Digite 1,2,3 (B,I,S)";
	int op;
	std::cin>>op;
	auto ini = std::chrono::high_resolution_clock::now();

	
	switch(op){
		case(1):
			std::cout<<"\n::BUBBLE_SORT::\n";
			TimeBubbleRecursive(v,n);
			break;
		case(2):
			std::cout<<"\n::Insertion_SORT::\n";
			TimeInsertionRecursive(v,n);
			break;
		case(3):
			std::cout<<"\n::Selection_SORT::\n";
			TimeSelectionRecursive(v,n);
			break;

	}

	//TimeBubbleRecursive(v,n);
	//TimeInsertionRecursive(v,n);
	//TimeSelectionRecursive(v,n);

	auto fim = std::chrono::high_resolution_clock::now();
	auto d = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
	std::cout<<"\n>>>Time to "<< n<<": "<<(double) d/1000000<<" seg\n";
	std::cout<<"end";

/*
	std::cout<<"----------\n::INSERTION SORT::\n";
	TimeInsertionInterative(v, n);
	TimeInsertionRecursive(v,n);



	std::cout<<"----------\n::SELECTION SORT::\n";
//interativo
	TimeSelectionInterative(v, n);
//recursivo
	TimeSelectionRecursive(v,n);
*/
	/*
	std::cout<<"----------\n::SELECTION SORT::\n";


	
//List
*/





	QX_List *l = new QX_List();
	l->push_back(4);
	l->push_back(3);
	l->push_back(7);
	l->push_back(5);
	l->push_back(1);
	l->print();
	//TimeSelectionList(l);
	//selectionSortList(l);
	//heapsort(l);
	l->print();
	//swapList(l->getHead()->next,l->getHead()->back);
	//heapsort(l);
	//TimeBubbleList(l);
	merge_sort(l);
	 
	
	




	return 0;
	
}
