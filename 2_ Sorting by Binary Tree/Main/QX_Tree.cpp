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
#include <limits.h> //INT_MIN
#include <queue>
#define espaco 5 //desenho da arvore  (ignorar)
//ponteiro para o maior elemento +1, coringa
int Eglobal;


using namespace std;

//Arvore criada de baixo para cima

struct NoArv{
	int value;
	NoArv *esq;
	NoArv*dir;
	//Node *pai;
};
//cria arvore vazia
NoArv* arv_CriaVazia(){ 
	return NULL;
}
//cria um nó com chave key e dilhos esq e dir
NoArv* arv_Cria(int key,NoArv* esq, NoArv* dir){
	NoArv* novo = new NoArv;
	novo->value = key;
	novo->esq = esq;
	novo->dir = dir;
	return novo;
}
//retorna se a arvore é vazia
bool arv_vazia(NoArv* no){
	return (no==NULL);
}
//imprime os elementos da arvore
void arv_imprime(NoArv* no){
	if(!arv_vazia(no)){
		std::cout<<no->value<<"\n";
		arv_imprime(no->esq);
		arv_imprime(no->dir);
	}//else cout<<"<Print_vazia!>\n";
}
// retorna se o elemento key pertence a arvore
bool arv_pertence(NoArv* no,int key){
	if(no == NULL)
		return false; //subarvore vazia
	else
		return no->value == key ||
		 arv_pertence(no->esq,key)||
		 arv_pertence(no->dir,key);
}
// libera a os nós da arvore
NoArv* arv_libera(NoArv* no){
	if(no != NULL){
		no->esq = arv_libera(no->esq);
		no->dir = arv_libera(no->dir);
		delete no;
	}
	//cout<< "<QX_Tree Liberada>\n";
	return NULL;
}
//retorna a quantidade de nós da arvore
int arv_num_nos(NoArv* no){
	if(!arv_vazia(no)){
		return 1+arv_num_nos(no->esq) + arv_num_nos(no->dir);
	}else return 0;
}

/* :::::::::::::::::::::::::::TRABALHO::::::::::::::::::::
funções pertinentes ao trabalho

*/

//auxiliar: retorna o maior elemento do vetor
int maiorElem(int *v,int n,int aux){
	int maior = v[n];
	if(!n){
		return maior;
	}else{
	int k = v[aux-n];

	maior = maiorElem(v,n-1,aux);
	return(k>maior)?k:maior;
	}
}
/*  Auxiliar
	* Retorna uma fila de ponteiros de nos, equivalente a as folhas da arvore
	* Preenche essa fila com nós de valores iguais aos elementos do vetor
	* considera o tamanho do vetor e a quantidade de nós da arvore cheia
	* 
*/
queue<NoArv*> createLeaf(int *v, int n){
	int k =2; // auxiliar na verificação da quantidade necessaria de folhas
	// salvando o coringa
	int E = maiorElem(v,n,n)+1; 
	Eglobal = E; // sal
	
	while(n>k) k*=2; // encontrar a quantidade de folhas

	std::queue<NoArv*> folhas; // fila de ponteiros de nós
	
	for(int i =0;i<k;i++){
		int valor = (i<n) ? v[i] : E; // verificando se salva o elemento do vetor ou o coringa
		// criando folha e adicionando
		NoArv* no = arv_Cria(valor, NULL, NULL); 
		folhas.push(no);
		
	}return folhas;

}

/*  Auxiliar
	* Recebe uma fila e retorna a arvore ja populada da forma pedida
	* usa da folhas para atribuir o menor de cada par de folhas ao seu pai e assim 
	atribuir a raiz o valor do menor elemento do vetor
	* interativa
*/
NoArv* arv_OrdenaCria(std::queue<NoArv*> leafs){
	if(leafs.empty()) return NULL;//return leafs;
	else{
		NoArv* aux1; // primento elemento do par de folhas 
		NoArv* aux2; // segundo elemento do par
		NoArv* menor; // nó que vai receber o menor do par
		NoArv* raiz = NULL; // raiz a ser retornada

		while(leafs.size() != 1){//!leafs.empty()){
			//atribuição e retirada da fila
			aux1 = leafs.front(); 
			leafs.pop();
			aux2 = leafs.front();
			leafs.pop();
			//verificação e criação do pai
			menor = ( aux1->value > aux2->value )? aux2 : aux1;
			raiz = arv_Cria(menor->value,aux1,aux2);
			leafs.push(raiz); //add novamente a fila
		} return raiz;
	}
}


/*	Auxiliar
	* Tem como entrada a raíz com folha modificada e retorna a raíz atualizada
	* Percorre a arvore até os filhos e vai reatribuindo o "menor nó" do par ao pai correspondente
	* Recursivo
*/	
NoArv* propaga(NoArv* no){
	if(no->dir == NULL && no->esq == NULL) return no; //até chegar a um pai de folhas
	else{
		//percorrer
		NoArv* esq = propaga(no->esq);
		NoArv* dir = propaga(no->dir);
		//condição: atribuir ao pai o menor filho
		no->value = (esq->value > dir->value)? dir->value : esq->value ;
		return no;
	}
}




/*	Auxiliar
	* recebe a raiz da arvore populada
	* Percorre e retornar uma fila com os elementos ordenados
	* iterativa
*/  

std::queue<int> arv_OrdenaVec(NoArv* raiz){
	
	/*
		recebe a "arvore da ordenação" e trabalha substituindo
	os menores pelo coringa (E - maior+1), salvando em um vetor ou fila
	e meio que repetindo o até a raiz = coringa ;
	*/
	int E = Eglobal;
	std::queue<int> ord;

	if(raiz == NULL ) return ord;
	 else{
		while(raiz->value != E){ // parar quando a raiz tiver o valor do coringa
			
			NoArv* aux = raiz; // ponteiro que percorre os nos da arvore
			NoArv *esq = aux->esq;
			NoArv *dir = aux->dir;

			while(aux->esq != NULL || aux->dir != NULL){ //laço para levar o aux ao nó de menor elemento
				//resetando parametros
				esq = aux->esq;
				dir = aux->dir;
				//condição de percurso
				if(esq->value == aux->value)
					aux = aux->esq;
				else if(dir->value == aux->value)
					aux = aux->dir;
			} 
			//adição dos elementos na fila e substituição pelo coringa
			ord.push(aux->value);
			aux->value = E;
			raiz=propaga(raiz); // atualiza o menor elemento as folhas na raíz
			//draw_arvore_hor(raiz);

		}
	}return ord;
	std::cout<<"sai\n";
}


/* FUNÇÃO PRINCIPAL DE ORDENAÇÃO
	* Recebe o vetor e o tamanho e retorna uma fila de inteiros com os elementos ordenados
	* Segue o passo a passo de resolução do problema para o usuário não precisar se preocupar
	com detalhes de implementação
	* desalocações

*/
std::queue<int> arv_Ordena(int *v,int n){
	
	std::queue<NoArv*> qLeafs = createLeaf(v,n);
	NoArv* raiz = arv_OrdenaCria(qLeafs);
	std::queue<int> ordenado = arv_OrdenaVec(raiz);
	// desalocações
	arv_libera(raiz);

	
	return ordenado;
}





/*  ::::::::::::Desenhar::::::::::::::               (IGNORAR) */ 
void desenha_arvore_horiz(NoArv *arvore, int depth, char *path, int direita){
    // stopping condition
    if (arvore== NULL)
        return;

    // increase spacing
    depth++;

    // start with direita no
    desenha_arvore_horiz(arvore->dir, depth, path, 1);

    // set | draw map
    path[depth-2] = 0;

    if(direita)
        path[depth-2] = 1;

    if(arvore->esq)
        path[depth-1] = 1;

    // print root after spacing
    printf("\n");

    for(int i=0; i<depth-1; i++)
    {
      if(i == depth-2)
          printf("+");
      else if(path[i])
          printf("|");
      else
          printf(" ");

      for(int j=1; j<espaco; j++)
      if(i < depth-2)
          printf(" ");
      else
          printf("-");
    }

    printf("%d\n", arvore->value);

    // vertical espacors below
    for(int i=0; i<depth; i++)
    {
      if(path[i])
          printf("|");
      else
          printf(" ");

      for(int j=1; j<espaco; j++)
          printf(" ");
    }

    // go to esquerda no
    desenha_arvore_horiz(arvore->esq, depth, path, 0);
}

//primary fuction
void draw_arvore_hor(NoArv *arvore){
    // should check if we don't exceed this somehow..
    char path[255] = {};

    //initial depth is 0
    desenha_arvore_horiz(arvore, 0, path, 0);
}

