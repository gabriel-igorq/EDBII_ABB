#include <iostream>
#include "../include/ABB.hpp"

int main() {
	std::cout << "Iniciando Testes:" << std::endl;

	ABB arvore;

	//Testando construtor
	Node* raiz = arvore.getRaiz();

	if(raiz == nullptr) {
		cout << "Construtor OK!" << endl;
	}


	//Testando inserção
	arvore.inserir(8);
	int size = arvore.getSize();
	if(size == 1) {
		cout << "8 inserido!" << endl;	
	}

	//Testando inserção em árvore contendo um elemento
	arvore.inserir(4);
	size = arvore.getSize();
	if(size == 2) {
		cout << "4 inserido!" << endl;	
	}

	//Testando inserção em árvore contendo um elemento
	arvore.inserir(10);
	size = arvore.getSize();
	if(size == 3) {
		cout << "10 inserido!" << endl;    	
	}

	//Testando inserção em árvore contendo um elemento
	arvore.inserir(12);
	size = arvore.getSize();
	if(size == 4) {
		cout << "12 inserido!" << endl;	
	}

	//Testando busca
	Node* tmp = arvore.busca(10);
	if(tmp->dado == 10) {
		cout << "Busca funcionando!" << endl;    	
	}

	return 0;
}
