# Estrutura de Dados

[PT-BR]

Implementação C++:


## Lista Sequêncial Redimensionavel
'''cpp
//---construtor
	QX_SeqList(int n);
	//---Destrutor
	~QX_SeqList();
	//size
	int size();
	//verificar se está cheia
	bool isFull();
	//limpar a lista
	void clear();
	//printa a lista
	void print();
	//procura um elemento na lista
	int search(int x);
	// retorna o index-esimo elemento da lista
	int at(int index);
	// adiciona o valor x ao final da lista, observando se vai 
	//estourar a capacidade da mesma, se estourar dobra a capacidade; 
	void push_back(int x);
	//printa os valores de forma invertida
	void printReverse();
	//remove o elemento x da lista
	void remove(int x);
	//remove todas as ocorrencias de x da lista
	void removeAll(int x);
	//remove o elemento do final da lista e retorna ele
	int pop_back();
'''


## Lista Circular Duplamente Encadeada

'''cpp
	//construtor;
	QX_List();
	//Destrutor;
	~QX_List();
	//Adicionar valor key após o ultimo nó da lista;
	void push_back(int key);
	//printa os valores da lista
	void print();
	//remove o ultmo nó da lista e printa seu valor;
	int pop_back();
	//deleta os nós da lista e a torna uma lista vazia;
	void clear();
	//cria um novo nó com valor key após o nó de indice k;
	void insertAfter(int key,int k);
	//remove o nó com valor igual a key;
	void remove(int key);
	// remove todos os nós com a ocorrencia do valor key;
	void removeAll(int key);
	//remove um nó apontado pelo ponteiro p;
	void removeNode(Node *p);
	//remove o nó na "posição" k;
	int removeNodeAt(int k);
	//imprime os valores da lista de forma invertida;
	void printReverse();
	// retorna se a lista está ou não vazia;
	bool isEmpty();
	//retorna a quantidade de nós da lista;
	int size();
	//Concatena duas listas, limpando a lista passada;
	void concat(QX_List *lst);
	//retorna uma'nova lista que é cópia dalista que chama;
	QX_List *copy();
	// recebe um array e seu tamanho e os insere na lista;
	void copyArray(int *arr,int n);
	//retorna se uma lista é ou não igual a lista passada;
	bool equal(QX_List *lst);
	//separa uma lista apartir da primeira ocorrencia do valor n,
//retorna uma lista que é uma nova lista formada com os elementos restantes;
	QX_List *separate(int n);
	//retorna uma lista que é a intercalação da lista que chama e 
//a lista passada;	
	void merge_lists(QX_List *list2);

'''


