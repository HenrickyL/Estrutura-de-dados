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
const int tam[] = {1000,5000,10000,50000,100000};//,500000,1000000};
int TOTAL_N = sizeof(tam)/sizeof(tam[0]); 

//função que gera um vetor aleatório apartir de um inteiro N

//printVec(v,n);

int main(){
	
	auto iniGeral = std::chrono::high_resolution_clock::now();
	//Arquivo:
	//////ifstream arqIn;
 	ofstream arqOut;

 	string linha; // string que vai armazenar as linhas do arquivo
 	string aux =""; // string auxiliar para trabalhar com numero >9
 	
 	//definindo o arquivo no diretório
 	//arqIn.open("vetores.txt"); //leitura
 	arqOut.open("dados_Insertion.txt",ios::out); //escrita

 	//quantidade de testes para a média
	int N_media= 5;
	for(int k: tam){ //for percorrendo os tamanhos
		int somaI = 0, SomaR =0;
		int mediaI=0,MediaR=0;
		aux = "";
		int n = k;
		auto ini = std::chrono::high_resolution_clock::now();
	
		for(int l =0;l<N_media;l++){ //for para fazer as médias
			std::cout<<"N: "<<n;
			int v[n];
			srand(time(NULL));

			for(int i=0;i<n;i++){ // for para gerar os valores
				v[i] = rand();
			}
			
			
			std::cout<<"-------------\n::INSERTION SORT::\n";
		//interativo
			somaI += TimeInsertionInterative(v, n);
		//recursivo
			SomaR += TimeInsertionRecursive(v,n);
			if(l == N_media-1){
				//rodou N vezes e tiro a média
				MediaR = SomaR/N_media;
				mediaI = somaI/N_media;
				//limpo
				SomaR=0;
				somaI=0;		
			}
		}
		//pego a média
		MediaR = MediaR/N_media;
		mediaI = mediaI/N_media;
		//salvo
		aux = to_string(n)+"\t"+to_string(mediaI)+"\t"+to_string(MediaR);
		arqOut << aux <<"\n";
		auto fim = std::chrono::high_resolution_clock::now();
		auto d = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
		std::cout<<"\n>>>Time to "<< k<<": "<<(double) d/1000000<<" seg\n";
	}
	arqOut.close(); 
	


//	verificações
	auto fimGeral = std::chrono::high_resolution_clock::now();
	auto final = std::chrono::duration_cast<std::chrono::microseconds>(fimGeral - iniGeral).count();
	double timeFinal = (double) final/1000000;
		if((double) timeFinal > 60*60){
		std::cout<<"\n\n\n::: GERAL TIME ::\n "<<timeFinal<<" h\n";
		timeFinal = timeFinal/(60*60);
		arqOut.open("Tempo totalInsertion.txt",ios::out);
		arqOut << timeFinal <<" h \n";
		arqOut.close(); 
	}else if((double)timeFinal > 60){
		timeFinal = timeFinal/60;
		std::cout<<"\n\n\n::: GERAL TIME ::\n "<<timeFinal<<" min\n";
		arqOut.open("Tempo totalInsertion.txt",ios::out);
		arqOut << timeFinal <<" min \n";
		arqOut.close(); 
	}else{
		std::cout<<"\n\n\n::: GERAL TIME ::\n "<<timeFinal<<" seg\n";
		arqOut.open("Tempo totalInsertion.txt",ios::out);
		arqOut << timeFinal <<" seg\n";
		arqOut.close(); 
	}





	/*
	std::cout<<"-------------\n::BUBBLE_SORT::\n";
		//interativo
			TimeBubbleInterative(v, n);
		//recursivo
			TimeBubbleRecursive(v, n);

	std::cout<<"----------\n::INSERTION SORT::\n";
	TimeInsertionInterative(v, n);
	TimeInsertionRecursive(v,n);

	std::cout<<"----------\n::SELECTION SORT::\n";
//interativo
	TimeSelectionInterative(v, n);
//recursivo
	TimeSelectionRecursive(v,n);
	std::cout<<"----------\n::SELECTION SORT::\n";
	
//List

	QX_List *l = new QX_List();
	l->push_back(7);
	l->push_back(5);
	l->push_back(6);
	l->push_back(3);
	l->push_back(1);
	l->print();
	TimeBubbleList(l);
	
	 */
	
	




	return 0;
}