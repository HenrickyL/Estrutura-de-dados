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
#ifndef QXTREE_H
#define QXTREE_H
#include <queue>

struct NoArv;
	/*            //nos de arvore
	int chave;
	noArv* esq;
	noArv* dir;
	*/

NoArv* arv_CriaVazia(); //cria arvore vazia
NoArv* arv_Cria(int key, NoArv* esq, NoArv* dir); //cria um nó de valor key de filhos esq e dir;
void arv_imprime(NoArv* no); // imprime os elementos da arvore
bool arv_vazia(NoArv* no); // retora se a arvore está vazia
NoArv* arv_libera(NoArv* no);//Libera todos os nós alocados na arvore
bool arv_pertence(NoArv* no,int chave); // verifica se uma chave está na arvore
int arv_num_nos(NoArv* no); // retorna o número de nó da arvore
/*            ::TRABALHO::        */
//funções relativas ao trabalho
int maiorElem(int *V,int n, int aux); //auxiliar: retorna o maior elemento de um vetor
std::queue<NoArv*> createLeaf(int *v, int n);// auxiliar: cria uma fila de ponteiros de noArv para as folhas da arvore (cheeia com coringa)
NoArv* arv_OrdenaCria(std::queue<NoArv*> leafs);//auxiiar: cria uma arvore apartir de uma fila de nós (folhas)
std::queue<int> arv_OrdenaVec(NoArv* raiz); //auxiliar:  retorna uma fila com os elementos do vetor ordenado
NoArv* propaga(NoArv* no); // auxiliar: retorna a raiz após a operação de rePopular arvore com a alteração do menor elemento (raiz->value)
std::queue<int> arv_Ordena(int *v,int n); // função que utiliza das auxiliares para agrupar o passo a passo.


// :: Desenho da arvore ::      ignorar
// função obtida na internet para auxiliar na visualização da arvore criada.
void draw_arvore_hor(NoArv *arvore); // desenha, de forma horizontal, a arvore;
void desenha_arvore_horiz(NoArv *arvore, int depth, char *path, int direita); // auxiliar
//referência: https://pt.stackoverflow.com/questions/207358/como-imprimir-%C3%A1rvores-bin%C3%A1rias-gen%C3%A9ricas-usando-c  
#endif