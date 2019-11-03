
/*
#########################################################################
#					UFC - Quixadá - Outubro 2019						#
#				ESTRUTURA DE DADOS										#
#	Atividade 4 - Trabalho 2 											#
#																		#
#	Equipe: Henricky de Lima Monteiro (475075) - HenrickyL1@gmail.com 	#
#			Elibe Soares Santos (470820) 								#
#	Agradecimento: Pedro Henrique Spinossa 								#
#	Professor: Atílio Gomes												#
#				::Ordenação por Arvore Binária::						#
#########################################################################
*/
#include <iostream>
#include "QX_Tree.h"
#include <queue>
#include <string>
#include <fstream>
using namespace std;
int main(){
	
	int n; //guardar o tamanho do vetor
 	//objetos de entrada e saída pelos arquivo
 	ifstream arqIn;
 	ofstream arqOut;

 	string linha; // string que vai armazenar as linhas do arquivo
 	string aux =""; // string auxiliar para trabalhar com numero >9
 	

 	//definindo o arquivo no diretório
 	arqIn.open("vetores.txt"); //leitura
 	arqOut.open("Ordenados.txt",ios::out); //escrita

 	//repetição para percorrer o arquivo
	while(getline(arqIn,linha)){ // enquanto Houver linhas no arquivo
		
		for(int i=0; linha[i]!= '\0';i++) // percorre a primeira linha recebendo o n (salvou no aux)
 			aux+=linha[i];  //concatenacao
 		n = stoi(aux); //converte a string para int (converte a string concatenada na para int )

 		arqOut<<n<<endl; //add um o N no arquivo de saida e da um \n para escrever na proxima linha
 		
 		int V[n]; //crio um vetor

 		//leio a linha e salvo na string "linha"
 		getline(arqIn,linha);

 		int j=0; //variável para iterar o vetor V (não pode usar o i)
 		aux = "";// resetando a variavel auxiliar para usar novamente

 		for(int i =0 ; linha[i]!='\0';i++){ // for que percorre a linha equiv. ao vetor
 			aux += linha[i]; //concatenação
 			if(linha[i+1] == ' ' || linha[i+1] == '\0' ){ //condição para salvar no vetor
	 			V[j] = stoi(aux);//-48;
 				aux = "";
 				j++;
 			}else continue;
 		}
 		cout<<"Vetor criado!\n";



		// Usando a função criada!
 		queue<int> ordenado = arv_Ordena(V,n);
 		
 		cout<<"\nordenou!\n >";
 		
 		cout<< ordenado.size()<<"\n";

 		while(!ordenado.empty()){ //while para salvar os valores da fila no arquivo de saida e print na tela
			arqOut << ordenado.front(); //recebe o 1º da fila e add ao arquivo
			arqOut << " "; //add "espaço" ao arquivo

			cout<<ordenado.front()<< " " ;//printando os elementos
			
			ordenado.pop();//retira da fila
		}
		arqOut <<endl;// pula uma linha no arquivo
 		cout<<endl; //pula uma linha no print
 	}
 	//fechada os arquivos!
 	arqOut.close(); 
 	arqIn.close();



	return 0;
}