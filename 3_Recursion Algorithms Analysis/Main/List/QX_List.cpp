#include <iostream>
#include <climits> // INT_MIN
#include "QX_List.h"

/* Lista circular duplamente encadeada:
	-Uma lista encadeada que cada nó carrega um valor e dois ponteiros, um com o próximo nó
e outro com o nó anterior. E por causa disso, o ultimo e a cabeça tem que apontar para algum
canto, logo eles apontam um para o outro (fechando a lista circular).

*/


/*
struct Node{
	int value;
	Node *next;
	Node *back; 
};
*/


/*
	Cria-se a classe e define os valores padrões do nó cabeça.
*/
//Método construtor;
QX_List::QX_List(){
	head = new Node; // cria a cabeça
	head->value = 0; // atribui valor padrão;
	//padrão de lista vazia circular
	head->next = head;
	head->back = head;
	std::cout<<"<QX_List Criada!>\n";
}
//Método destrutor;
QX_List::~QX_List(){
	delete head; //deleta a lista
	std::cout<<"<QX_List Deletada!>\n";
}
//getter e setter
Node* QX_List::getHead(){
	return head;
}





//Método que cria e adiciona um nó com valor key;
void QX_List::push_back(int key){
	Node *newNode = new Node; //cria um ponteiro que aponta para um novo nó;
	//ponteiro auxiliar para nos ajudar a percorrer a lista
	Node *aux = head->back;
	if(head->next == head){ //caso de estar vazio
		newNode->value = key;
		//são necessárias quatro movimentos de ponteiros para adionar um elemento ao "fim";
		head->next = newNode;
		head->back = newNode;
		newNode->next = head;
		newNode->back = head;
		std::cout << "<Primeiro elemento Adicionado!>\n";
	}else{ //Adicionar depois do primeiro
		newNode->value = key;
		aux->next = newNode;
		newNode->back = aux;
		newNode->next = head;
		head->back = newNode;
		//std::cout << "<Elemento Adicionado!>\n";
	}
}
void QX_List::print(){
	if(head->next == head) std::cout<<"<Vazia!>\n";
	else{
		Node *aux = head;
		while(aux->next != head){
			aux= aux->next;
			std::cout<<aux->value<<" ";
			
		}std::cout<<"\n";
	}
}
/*
	*remove o ultimo nó;
	*engata o penultimo a cabeça e a cabeça ao penultimo;
*/
int QX_List::pop_back(){
	if(!isEmpty()){
		Node *aux = head->back; //aux = ultimo
		int save = aux->value; //salvo o valor pq vou deletar o aux
		head->back = aux->back;//mudo o ultimo para o penultimo
		(aux->back)->next = head; //o penultimo vai apontar para a cabeça
		delete aux;
		//std::cout<<"<Ultimo elemento removido!>\n";
		return save;
	} else return INT_MIN;
}

void QX_List::clear(){
	Node *aux = head->back; // aux é o ultimo
	while(aux->back != head->back){ //enquanto o anterior do ultimo !- de head
		head->back = aux->back;//mudo o ultimo para o penultimo
		(aux->back)->next = head; //o penultimo vai apontar para a cabeça
		aux = aux->back;
	}std::cout<<"<Clear QX_List!>\n";
} 
/*
	*percorre a lista com o auxiliar e se achar o k, cria um nó
atribui um valor a ele(key) e adiciona este nó após o nó k-esimo;
*/
void QX_List::insertAfter(int key,int k){
	int cont=0;
	Node *newNode = new Node;
	newNode->value = key;
	bool overFlow = true;
	Node *aux = head->next;
	while(aux != head ){
		if(cont == k){
			overFlow=false;
			newNode->back = aux;
			newNode->next = aux->next;
			(aux->next)->back = newNode;
			aux->next = newNode;
			break;
		}cont++;
		aux= aux->next;
	}if(overFlow) std::cout<<"<overflow!>\n"; 
	else std::cout<<"<Elemento Add! após indice: "<<k<<">\n";
}
/*
	* percorre a lista procurando o indice 
	* remove o nó
*/
void QX_List::remove(int key){
	Node *aux = head->next;
	bool naoEsta = false;
	while(aux->value != key){
		aux = aux->next;
		if(aux->next == head->next){ 
			naoEsta = true;
			break; //não ta la
		}
	}
	if(naoEsta == false){
		(aux->back)->next = aux->next;
		(aux->next)->back = aux->back;
		delete aux;
		std::cout<<"<Elemento "<< key <<" removido!>\n";
	}else std::cout<<"<"<<key<<" não existe em QX_List!>\n";
	
}

void QX_List::removeAll(int key){
	Node *aux = head->next;
	bool naoEsta = true;
	while(aux->next != head->next){
		if(aux->value == key){
			Node *apaga;
			naoEsta = false;
			(aux->back)->next = aux->next;
			(aux->next)->back = aux->back;
			apaga = aux;
			aux = aux->next;
			delete apaga;
		}else aux = aux->next;
	}
	if(naoEsta == false) std::cout<<"<Elementos "<< key <<" removidos!>\n";
	else std::cout<<"<Não existe nenhum "<<key<<" em QX_List!>\n";
}
/*
	* remove um nó
	*basta "desengatar" (pensando no diagrama da lista) e
	engatar o anterior no posterior
*/
void QX_List::removeNode(Node *p){
	(p->back)->next = p->next;
	(p->next)->back = p->back;
	delete p;
	std::cout<<"<Nó apagado!>\n";
}
/*
	* remove nó após o indice k
	* percorre a lista procurando o indice se achar coloca depois
	* se não retorna o menor inteiro 
*/
int QX_List::removeNodeAt(int k){
	int cont=0;
	Node *aux = head->next;
	while(aux != head){
		cont+=1;
		aux = aux->next;
		if(cont == k){
			int x = aux->value;
			this->removeNode(aux);
			return x;
		}
	}return INT_MIN;
}
/*
	*percorre a lista ao contrário printando seus valores;
*/
void QX_List::printReverse(){
	Node *aux = head->back;
	while(aux != head){
		std::cout<<aux->value<<" ";
		aux = aux->back;
	}std::cout<<"\n";
}
/*
	* verificar se a lista está vazia
*/
bool QX_List::isEmpty(){
	return head->next == head;
}
/*
	*percorre a lista contando a quatidade de elementos
*/
int QX_List::size(){
	int size=0;
	Node *aux = head->next;
	while(aux != head){
		size++;
		aux = aux->next;
	}return size;
}
/*
	*Analisando os casos os mais importantes são
		- as duas com elementos e a primeiras vazia e a segunda com elemento
	* onde "engatamos" as duas no primiro caso
	* e transferimos os elemento da segunda para a primeira
*/
void QX_List::concat(QX_List *lst){
	if(!isEmpty() && !lst->isEmpty()){
		head->back->next = lst->head->next;
		lst->head->next->back = head-> back;
		
		lst->head->next = lst-> head;
		head->back = lst->head->back;
		
		lst->head->back->next = head;
		lst->head->back = lst->head;

	}else if(isEmpty() && !lst->isEmpty()){
		//1º do 1º -> 1º do 2º 
		head->next = lst->head->next;
		lst->head->next = lst->head;
		//ultimo do 1º -> ultimo do 2º 
		head->back = lst->head->back;
		lst->head->back = lst->head;
		//volta do 1º elemento do 1º -> cabeça 1º
		lst->head->next->back = head;
	} // outros casos mantem
	
	std::cout<<"<Listas concatenadas!>\n";
}
/*
	*cria uma uma nova lista e um ponteiro que aponta para ela
	*adiciona os elementoda da lista a ser copiada na nova;
*/
QX_List* QX_List::copy(){
	QX_List *copia = new QX_List();
	Node *aux = head->next;
	while(aux != head){
		copia->push_back(aux->value);
		aux = aux->next;
	} return copia;
}
/*
	* recebe um ponteiro para um vetor e o seu tamanho;
	*bastou ir adicionando cada elemento a lista usando push_back
*/
void QX_List::copyArray(int *arr, int n){
	Node *aux = head->next;
	int cont = 0;
	while(cont  != n){
		push_back(arr[cont]);
		aux = aux->next;
		cont++;
		std::cout<<".";
	}std::cout<<"\n<Vetor adicioanado a lista!>\n";
}
/*
	* Verifica se os tamanhos são iguais
	* se sim, verifica elemento por elemento;
*/
bool QX_List::equal(QX_List *lst){
	Node *aux1 = head->next;
	Node *aux2 = lst->head->next;
	int cont=0;
	if(this->size() != lst->size()) return false;
	else{
		while(cont < this->size()){
			if(aux1->value != aux2->value) return false;
			aux1 = aux1->next;
			aux2 = aux2->next;
			cont++;
		} return true;
	}
}
/*
	* Criando uma nova lista e um aux para a original
	* percorre aux para verificar o "n", se achar quebra o loop
 e marca que é separavel. Se não,  não separa.
	* 

*/
QX_List* QX_List::separate(int n){
	QX_List *separ = new QX_List();
	Node *aux = head->next;
	bool separavel = false;
	while(aux != head){
		if(aux->value == n){
			separavel = true;
			std::cout<<">"<<aux->value<<"<\n";
			break;
		}aux = aux->next;
	}if(separavel){
		std::cout<<">>"<<aux->value<<"<\n";
		separ->head->next = aux->next;
		separ->head->back = head->back;
		aux->next->back = separ->head;
		head->back->next = separ->head;
		aux->next = head;
		head->back = aux;
		std::cout<<"\t.\n";
		return separ;
	}else return separ;
}

/*
	* cria um ponteiro apontando para a lista atual e dois aux para
cada head;
	* Seguindo dois casos: primeira vazia e as duas cheias
	* no caso das com elementos, temos 2 casos:
		* aux1 > aux2 e aux1 < aux2: 
*/

void QX_List::merge_lists(QX_List *list2){
	QX_List *lst = this;
	Node *aux1 = head->next;
	Node *aux2 = list2->head->next;
	int cont = 0;
	if(isEmpty() && !list2->isEmpty()){
		lst = list2->copy(); //se 1ª vazia copia a segunda para ela;
	}
	else if(!isEmpty() && !list2->isEmpty()){
		while(aux1 != head || aux2 != list2->head){
			if(cont%2==0  && aux1 != head && aux2 != list2->head){
		//apos os apresa add o elemento da aux2;
		// e incrementa		
				this->insertAfter(aux2->value,cont);
				aux2 = aux2->next;
				aux1 = aux1->next;
				
			}else if(aux1 == head && aux2 != list2->head){
				//se acabou os do aux1 continue usando os do aux2;
				this->push_back(aux2->value);
				aux2 = aux2->next;
			}else aux1 = aux1->next;
			cont++;
		}
	}list2->clear();
	std::cout<<"<QX_List merge>\n";
}


