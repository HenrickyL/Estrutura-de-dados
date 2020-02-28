# Estrutura de Dados

[PT-BR]

Implementa�0�4�0�0o C++:


## Lista Sequ��ncial Redimensionavel
'''cpp
//---construtor
	QX_SeqList(int n);
	//---Destrutor
	~QX_SeqList();
	//size
	int size();
	//verificar se est�� cheia
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
	//Adicionar valor key ap��s o ultimo n�� da lista;
	void push_back(int key);
	//printa os valores da lista
	void print();
	//remove o ultmo n�� da lista e printa seu valor;
	int pop_back();
	//deleta os n��s da lista e a torna uma lista vazia;
	void clear();
	//cria um novo n�� com valor key ap��s o n�� de indice k;
	void insertAfter(int key,int k);
	//remove o n�� com valor igual a key;
	void remove(int key);
	// remove todos os n��s com a ocorrencia do valor key;
	void removeAll(int key);
	//remove um n�� apontado pelo ponteiro p;
	void removeNode(Node *p);
	//remove o n�� na "posi�0�4�0�0o" k;
	int removeNodeAt(int k);
	//imprime os valores da lista de forma invertida;
	void printReverse();
	// retorna se a lista est�� ou n�0�0o vazia;
	bool isEmpty();
	//retorna a quantidade de n��s da lista;
	int size();
	//Concatena duas listas, limpando a lista passada;
	void concat(QX_List *lst);
	//retorna uma'nova lista que �� c��pia dalista que chama;
	QX_List *copy();
	// recebe um array e seu tamanho e os insere na lista;
	void copyArray(int *arr,int n);
	//retorna se uma lista �� ou n�0�0o igual a lista passada;
	bool equal(QX_List *lst);
	//separa uma lista apartir da primeira ocorrencia do valor n,
//retorna uma lista que �� uma nova lista formada com os elementos restantes;
	QX_List *separate(int n);
	//retorna uma lista que �� a intercala�0�4�0�0o da lista que chama e 
//a lista passada;	
	void merge_lists(QX_List *list2);

'''


