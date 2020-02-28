#include <iostream>
#include <climits>
#include "QX_SeqList.h"
//construtor
QX_SeqList::QX_SeqList(int n){
	if(n>0){
		vec = new int[n];
		size_vec = 0;
		capacity_vec = n;
	}
}
//destrutor
QX_SeqList::~QX_SeqList(){
	if(vec != NULL){ 
		delete[] vec;
		std::cout<<"<QX_SeqList destruido!>\n";
	}
}
//size
int QX_SeqList::size(){
	return this->size_vec;
}
bool QX_SeqList::isFull(){
	return this->size_vec == this->capacity_vec;
}
void QX_SeqList::clear(){
	this->size_vec =0;
}
void QX_SeqList::print(){
	for(int i=0;i<this->size_vec;i++){
		std::cout<< this->vec[i] << " ";		
	}std::cout<<"\n";
}
int QX_SeqList::search(int x){
	for(int i = 0;i< this->size_vec;i++){
		if(x ==this->vec[i]) return i;

	} return -1;
}
int QX_SeqList::at(int index){
	if(0<=index && index<this->size_vec ) return this->vec[index];
	else {
		std::cout<< "<fora do intervalo!>\n";
		return INT_MIN;
	}
}
void QX_SeqList::push_back(int x){
	if(this->isFull()){
		this->capacity_vec = this->capacity_vec*2;//nova capacidade
		int *newVec = new int[this->size_vec]; //cria vetor igual
		for(int i=0;i<this->size_vec;i++) newVec[i]=this->vec[i]; //copia
		this->vec = new int[this->capacity_vec]; //aumenta
		for(int i = 0;i<this->size_vec;i++) this->vec[i] = newVec[i]; //recebe a copia
		std::cout << "<vetor Extendido!>\n";
		delete[] newVec; // apaga a copia
		this->push_back(x);//cair no else
	}else{
		this->vec[this->size_vec] = x;
		this->size_vec++;
		std::cout<<"<Adicionado com sucesso!>\n";
	}
}
void QX_SeqList::printReverse(){
	for(int i = this->size_vec - 1;i>=0;i--) {
		std::cout<<this->vec[i] <<" ";
	}std::cout<<"\n";
}
void QX_SeqList::remove(int x){
	int index = this->search(x);
	if(index != -1){
		while(index <= this->size_vec -2 ){ //ultimo é size_vec -1
			this->vec[index] = this->vec[index+1];//usar o proximo precisa q seja -2
			index++;
		}this->size_vec--;
		std::cout<<"<Elemento Removido!>\n";
	}
}
void QX_SeqList::removeAll(int x){
	for(int i=0;i<this->size_vec;i++){
		if(this->vec[i]==x){ 
			this->remove(x);
			this->size_vec--;
		}
	}std::cout<<"<Elementos Removidos!>\n";
}

int QX_SeqList::pop_back(){
	if(size_vec ==0){
		return INT_MIN;
	}else{
		int valor = vec[size_vec-1];
		this->size_vec--;
		return valor;
	}
}