#include <iostream>
#include "../include/Node.hpp"
#include "../include/BinarySearchTree.hpp"


int main() {
	std::cout << "Iniciando Testes:" << std::endl;

	BinarySearchTree tree;

	//Testando construtor
	Node* root = tree.getRoot();
	if(root == nullptr) {
		std::cout << "Construtor OK!" << std::endl;
	}

	//Testando inserção
	tree.insert(8);
	int size = tree.getSize();
	if(size == 1) {
		std::cout << "8 inserido!" << std::endl;	
	}

	//Testando inserção em árvore contendo um elemento
	tree.insert(4);
	size = tree.getSize();
	if(size == 2) {
		std::cout << "4 inserido!" << std::endl;	
	}

	//Testando inserção em árvore contendo um elemento
	tree.insert(10);
	size = tree.getSize();
	if(size == 3) {
		std::cout << "10 inserido!" << std::endl;    	
	}

	//Testando inserção em árvore contendo um elemento
	tree.insert(12);
	size = tree.getSize();
	if(size == 4) {
		std::cout << "12 inserido!" << std::endl;	
	}

	//Testando busca
	Node* tmp = tree.search(10);
	if(tmp->data == 10) {
		std::cout << "Busca funcionando!" << std::endl;    	
	}

	return 0;
}