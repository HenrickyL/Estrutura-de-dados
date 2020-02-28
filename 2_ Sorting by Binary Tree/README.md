# Estrutura de Dados

[PT-BR]

Implementação C++:


## Ordenação de Vetor por Árvore Binária

O problema consiste em realizar a ordenação de um ou mais vetores utilizando a Estrutura de dados da Árvore Binária, onde, dados, um vetor V de n elementos arbitrários devem ser obtidos de um arquivo (.txt).



Dentre outras funções:

```c++
std::queue<int> arv_Ordena(int *v,int n){
//cria folhas de uma arvore com os elementos do vetor
	std::queue<NoArv*> qLeafs = createLeaf(v,n); 
//Monta a arvore
	NoArv* raiz = arv_OrdenaCria(qLeafs);
//função que "ordena" os elementos da arvore
	std::queue<int> ordenado = arv_OrdenaVec(raiz);
	// desalocações
	arv_libera(raiz);

	
	return ordenado;
}
```


