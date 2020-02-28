/* QŨESTÃO 2
Aluno: Henricky de Lima monteiro
Matricula: 475075
*/

#include <iostream> 
#include "QX_List.h"
#include <climits> // INT_MIN
#include <string>
#include <stdlib.h>
/* NÃO VOU COMENTAR DETALHES ESTÉTICOS DO MENU;

*/




int main(){
	int op,aux;
	bool start = true,reset = false;
	
	int k=1, m =5;
	std::string lst =("");
	QX_List *listas[m];
	for(int i = 0;i < m;i++){
		if(i < k)
			lst+=" "+std::to_string(i);
		listas[i] = new QX_List();	
	}system("clear");



	std::string str = ("\n------------------------------\n\t:::LISTA CIRCULAR OPERAÇÕES:::\n");
	str +=">listas: "+lst;
	str += ("\n0. _add_list_ \n");
	str += ("1. push_back(int x) \t\t| \t  11. clear() \n");
	str += ("2. print()\t\t\t| \t  12. concat(QX List *lst)\n");
	str += ("3. size()\t\t\t| \t  13. copy()\n");
	str += ("4. isEmpty()\t\t\t|\t  14. copyArray(int *arr, int n)\n");
	str += ("5. pop_back()\t\t\t|\t  15. equal(QX List *lst)\n");
	str += ("6. insertAfter(int key,int k)\t|\t  16. separate(int n)\n");
	str += ("7. remove(int key)\t\t|\t  17. merge lists(QX List *list2)\n");
	str += ("8. removeAll(int key)\n");
	str += ("9. removeNodeAt(int k)\n");
	str += ("10. printReverse()\n");
	str+=("-999. Finalizar\n");





	while(start == true){
		std::cout << str;	
		std::cout << "----------------------\nDigite uma operação: ";
		std::cin >> op;
		system("clear");
		switch (op){
			case -999: //sair
				start = false;
				std::cout<<"<Fim do programa!>\n";
				break;
			case 0: // usar lista nova
				if(k<m){
					k++;
					reset = true;
				} 
				lst = ("");
				for(int i=0;i<k;i++)
					lst+=" "+std::to_string(i);
				break;

			case 1:
				std::cout<<"\t::push_back(int x)::\n";
				if(k>=2){
					std::cout<<"Digite a lista ("<<lst<<"): ";
					std::cin>>aux;
				}else aux = 0;
				std::cout<<"digite um número para add ao vetor: ";
				if(aux < k){
					int x;
					std::cin>>x;
					listas[aux]->push_back(x);
				}else std::cout<<"<invalido!>\n";
				break;
			case 2:
				std::cout<<"\t::print()::\n";
				for(int i = 0;i<k;i++){
						std::cout<<"Lista["<<i<<"]: ";
						listas[i]->print();
					}
				break;
			case 3:
				std::cout<<"\t::size()::\n ";
				for(int i =0;i<k;i++)
					std::cout<<"lista["<<i<<"].size: "<<listas[i]->size()<<"\n";
				
				break;
			case 4:
				std::cout<<"\t::isFull()::\n ";
				for(int i =0;i<k;i++)
					std::cout<<"Lista["<<i<<"].isEmpty(): "<<listas[i]->isEmpty()<<"\n";
				break;
			case 5:
				std::cout<<"\t::pop_back()::\n ";
				if(k>=2){
					std::cout<<"Digite a lista ("<<lst<<"): ";
					std::cin>>aux;
				}else aux = 0;
				if(aux < k){
					listas[aux]->print();
					int valor = listas[aux]->pop_back();
					if( valor == INT_MIN)
						std::cout<<"<lista Vazia!>\n";
					else{
						std::cout<<"retirou: "<<valor<<"\n";
						listas[aux]->print();
					}
				}else std::cout<<"<invalido!>\n";
				break;
			case 6:
				std::cout<<"\t::insertAfter()::\n ";
				if(k>=2){
					std::cout<<"Digite a lista ("<<lst<<"): ";
					std::cin>>aux;
				}else aux = 0;
				if(aux < k){
					listas[aux]->print();
					int valor, pos;
					std::cout<<"Digite um numero para adicionar: ";
					std::cin>>valor;
					std::cout<<"Digite a posição: ";
					std::cin>>pos;
					listas[aux]->insertAfter(valor,pos);
					listas[aux]->print();
				}else std::cout<<"<invalido!>\n";
				break;
			case 7:
				std::cout<<"\t::remove(int key)::\n ";
				if(k>=2){
					std::cout<<"Digite a lista ("<<lst<<"): ";
					std::cin>>aux;
				}else aux = 0;
				if(aux < k){
					listas[aux]->print();
					int valor;
					std::cout<<"Digite um numero para remover: ";
					std::cin>>valor;
					listas[aux]->remove(valor);
					listas[aux]->print();
				}else std::cout<<"<invalido!>\n";
				break;
			case 8:
				std::cout<<"\t::removeAll(int key)::\n ";
				if(k>=2){
					std::cout<<"Digite a lista ("<<lst<<"): ";
					std::cin>>aux;
				}else aux = 0;
				if(aux < k){
					listas[aux]->print();
					int valor, pos;
					std::cout<<"Digite um numero para remover todos: ";
					std::cin>>valor;
					listas[aux]->removeAll(valor);
					listas[aux]->print();
				}else std::cout<<"<invalido!>\n";
				break;
			case 9:
				std::cout<<"\t::removeNodeAt(int k)::\n ";
				if(k>=2){
					std::cout<<"Digite a lista ("<<lst<<"): ";
					std::cin>>aux;
				}else aux = 0;
				if(aux < k){
					listas[aux]->print();
					int pos;
					std::cout<<"Digite a posição para remover o nó: ";
					std::cin>>pos;
					int valor = listas[aux]->removeNodeAt(pos);
					if(valor == INT_MIN)
						std::cout<<"<Lista Vazia!>\n"; 
					else{
						std::cout<<" Nó.valor: "<<valor<<"\n";
						listas[aux]->print();
					}
				}else std::cout<<"<invalido!>\n";
				break;
			case 10:
				std::cout<<"\t::printReverse()::\n ";
				for(int i=0;i<k;i++){
					std::cout<<"Lista["<<i<<"].printReverse(): ";
					listas[i]->printReverse();
					}
				break;
			case 11:
				std::cout<<"\t::clear()::\n ";
				if(k>=2){
					std::cout<<"Digite a lista ("<<lst<<"): ";
					std::cin>>aux;
				}else aux = 0;
				if(aux < k){
					listas[aux]->print();
					listas[aux]->clear();
				}else std::cout<<"<invalido!>\n";
				break;
			//
			case 12:
				std::cout<<"\t::concat(QX List *lst)::\n ";
				int l1,l2,l3;
				std::cout<<"Digite duas listas para concatenar("<<lst<<"):\n";
				std::cout<<"\tL1: ";
				std::cin >> l1;
				std::cout<<"\tL2: ";
				std::cin >> l2;
				
				std::cout<<"Lista["<<l1<<"]: ";
				listas[l1]->print();
				std::cout<<"Lista["<<l2<<"]: ";
				listas[l2]->print();
				listas[l1]->concat(listas[l2]);
				std::cout<<"Lista["<<l1<<"].concat: ";
				listas[l1]->print();
				std::cout<<"Lista["<<l2<<"].concat: ";
				listas[l2]->print();
				break;
			case 13:
				std::cout<<"\t::copy()::\n ";
				//int l1,l2;
				std::cout<<"Digite a lista que deseja copiar(0,1,2,3,4): ";
				std::cin>>l1;
				std::cout<<"Digite a lista onde deseja salvar(0,1,2,3,4): ";
				std::cin>>l2;
				if(0<=l2 && l2<m){
					reset = true;
					lst= "";
					for(int i=0;i<k;i++)
						lst+=" "+std::to_string(i);
					if(l2>=k) lst+=" "+std::to_string(l2);

					listas[l2] = listas[l1]->copy();
					std::cout<<"<QX_List copiada!>\n";
					std::cout<<"Lista["<<l2<<"].concat: ";
					listas[l2]->print();
				}else std::cout<<"<QX_List invalidá!>\n";
				break;
			case 14:
			{
				std::cout<<"\t::copyArray(int *arr, int n)::\n ";
				int n;
				if(k>=2){
					std::cout<<"Digite a lista ("<<lst<<"): ";
					std::cin>>aux;
				}else aux = 0;
				std::cout<<"Criando vetor:\n";
				std::cout<<"\tDigite o seu tamanho: ";
				std::cin>>n;
				if(n>=0){
					int v[n];
					int *p;
					for(int i=0;i<n;i++){
						std::cout<<"\tDigite o "<<i+1<<"º elemento: ";
						std::cin>>v[i];
					} p = v;
					std::cout<<"Vetor:";
					for(int i=0;i<n;i++) std::cout<<" "<<v[i];
					std::cout<<"\n";
					listas[aux]->copyArray(p,n);
				}else std::cout<<"<tamanho Invalido!>\n";
			}
				break;
			case 15:
			{
				std::cout<<"\t::equal(QX List *lst)::\n ";
				std::cout<<"Digite duas listas para comparar (0,1,2,3,4):\n";
				std::cout<<"\tL1: ";
				std::cin>>l1;
				std::cout<<"\tL2: ";
				std::cin>>l2;
				if((0<=l1 && l1<m) || (0<=l2 && l2<m) ){
					std::cout<<">Lista["<<l1<<"] == Lista["<<l2<<"]?: ("<<listas[l1]->equal(listas[l2])<<")<\n";  
					std::cout<<"Lista["<<l1<<"]: ";
					listas[l1]->print();
					std::cout<<"Lista["<<l2<<"]: ";
					listas[l2]->print();
				}else std::cout<<"<Listas Inválidas!>\n";

			}
				break;
			case 16:
			{
				std::cout<<"\t::separate(int n)::\n ";
				int valor;
				std::cout<<"Digite duas listas(0,1,2,3,4):\n";
				std::cout<<"\tL_separar: ";
				std::cin>>l1;
				std::cout<<"\tL_salvar: ";
				std::cin>>l2;
				std::cout<<"\tDigite o elemento separador: ";
				std::cin>>valor;
				if((0<=l1 && l1<m) && (0<=l2 && l2<m) ){
					listas[l2] = listas[l1]->separate(valor);
					
					std::cout<<"<QX_List separada!>\n";
					std::cout<<"Lista["<<l1<<"]: ";
					listas[l1]->print();
					std::cout<<"Lista["<<l2<<"]: ";
					listas[l2]->print();
				}else std::cout<<"<Listas Inválidas!>\n";

			}
				break;
			case 17:
			{
				std::cout<<"\t::merge_lists(QX List *list2)::\n ";
				std::cout<<"Digite duas listas para intercalar(0,1,2,3,4):\n";
				std::cout<<"\tL1: ";
				std::cin>>l1;
				std::cout<<"\tL2: ";
				std::cin>>l2;
				if((0<=l1 && l1<m) && (0<=l2 && l2<m)){
					listas[l1]->merge_lists(listas[l2]);
					std::cout<<"Lista["<<l1<<"]: ";
					listas[l1]->print();
				}else std::cout<<"<Listas Inválidas!>\n";

			}
				break;
			


			default:
				std::cout<<"<Operação Inválida!>\n";
				break;

		}
		if(reset){	
			str = ("\n------------------------------\n\t:::LISTA CIRCULAR OPERAÇÕES:::\n");
			str +=">listas: "+lst;
			str += ("\n0. _add_list_ \n");
			str += ("1. push_back(int x) \t\t| \t  11. clear() \n");
			str += ("2. print()\t\t\t| \t  12. concat(QX List *lst)\n");
			str += ("3. size()\t\t\t| \t  13. copy()\n");
			str += ("4. isEmpty()\t\t\t| \t  14. copyArray(int *arr, int n)\n");
			str += ("5. pop_back()\t\t\t| \t  15. equal(QX List *lst)\n");
			str += ("6. insertAfter(int key,int k)\t|\t  16. separate(int n)\n");
			str += ("7. remove(int key)\t\t|\t  17. merge lists(QX List *list2)\n");
			str += ("8. removeAll(int key)\n");
			str += ("9. removeNodeAt(int k)\n");
			str += ("10. printReverse()\n");
			str+=("-999. Finalizar\n");
			reset = false;
		}




	} 
	for(int i = 0;i < m;i++){
		delete listas[i];	
		}


}