#ifndef QXSEQLIST_H
#define QXSEQLIST_H


class QX_SeqList{
private:
	int *vec = NULL;
	int size_vec = 0;
	int capacity_vec = 0; 
public:
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
};



#endif