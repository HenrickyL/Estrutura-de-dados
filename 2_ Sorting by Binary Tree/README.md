# Estrutura de Dados

[PT-BR]

Implementa�0�4�0�0o C++:


## Ordena�0�4�0�0o de Vetor por �0�9rvore Bin��ria

O problema consiste em realizar a ordena�0�4�0�0o de um ou mais vetores utilizando a Estrutura de dados da �0�9rvore Bin��ria, onde, dados, um vetor V de n elementos arbitr��rios devem ser obtidos de um arquivo (.txt).



Dentre outras fun�0�4�0�1es:

```c++
std::queue<int> arv_Ordena(int *v,int n){
//cria folhas de uma arvore com os elementos do vetor
	std::queue<NoArv*> qLeafs = createLeaf(v,n); 
//Monta a arvore
	NoArv* raiz = arv_OrdenaCria(qLeafs);
//fun�0�4�0�0o que "ordena" os elementos da arvore
	std::queue<int> ordenado = arv_OrdenaVec(raiz);
	// desaloca�0�4�0�1es
	arv_libera(raiz);

	
	return ordenado;
}
```


