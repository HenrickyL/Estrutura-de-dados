/* QŨESTÃO 1
Aluno: Henricky de Lima monteiro
Matricula: 475075
*/

#include <iostream> 
#include "QX_SeqList.h"
#include <string>
#include <stdlib.h>

int main(){
	int op,aux;
	bool start = true;
	std::string str = ("\t::Operação::\n");
	str += ("1. push_back(int x) //add  \n");
	str += ("2. print()\n");
	str += ("3. size()\n");
	str += ("4. isFull()\n");
	str += ("5. at(index)\n");
	str += ("6. search(int x)\n");
	str += ("7. printReverser()\n");
	str += ("8. remove(int x)\n");
	str += ("9. removeAll(int x)\n");
	str += ("10. pop_back()\n");
	str+=("0. Finalizar\n");

	int n=10;
	QX_SeqList lista(n);



	while(start == true){
		
		std::cout << str;	
		std::cout << "----------------------\nDigite uma operação: ";
		std::cin >> op;
		system("clear");
		switch (op){
			case 0:
				start = false;
				std::cout<<"<Fim do programa!>\n";
				break;
			case 1:
				std::cout<<"\t::push_back(int x)::\ndigite um número para add ao vetor: ";
				std::cin>>aux;
				lista.push_back(aux);
				break;
			case 2:
				std::cout<<"\t::print()::\n";
				lista.print();
				break;
			case 3:
				std::cout<<"\t::size()::\n";
				std::cout<<"Tamanho: "<<lista.size()<<"\n";
				break;
			case 4:
				std::cout<<"\t::isFull()::\n";
				std::cout<<"Cheio? "<<lista.isFull()<<"\n";
				break;	
			case 5:
				std::cout<<"\t::at(int index)::\n";
				std::cout<<"digite o indice para acessar o valor: ";
				std::cin>>aux;
				std::cout<<"valor: "<<lista.at(aux)<<"\n";
				break;
			case 6:
				std::cout<<"\t::search(int x)::\n";
				std::cout<<"Digite o numero que deseja Buscar: ";
				std::cin>>aux;
				std::cout<<"indice: "<<lista.search(aux)<<"\n";
				break;
			case 7:
				std::cout<<"\t::printReverser()::\n";
				lista.printReverse();
				break;
			case 8:
				std::cout<<"\t::remove(int x)::\n";
				std::cout<<"Digite o numero que deseja remover: ";
				std::cin>>aux;
				lista.remove(aux);
				break;
			case 9:
				std::cout<<"\t::removeAll()::\n";
				std::cout<<"Digite o numero que deseja remover: ";
				std::cin>>aux;
				lista.removeAll(aux);
				break;
			case 10:
				std::cout<<"\t::pop_back()::\n";
				std::cout<<"Elemento: "<<lista.pop_back()<<" removido!\n";
				break;

		}




	}



}