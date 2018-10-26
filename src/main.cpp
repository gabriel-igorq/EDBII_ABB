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

	//Testando inserção em árvore contendo um elemento
	tree.insert(5);
	size = tree.getSize();
	if(size == 5) {
		std::cout << "5 inserido!" << std::endl;	
	}

	//Testando busca
	Node* tmp = tree.search(10);
	if(tmp->key == 10) {
		std::cout << "Busca funcionando!" << std::endl;    	
	}

	std::cout << tree.toString() << endl;
	
	
	
	// Testando remoção de elemento existente
	if ( tree.remove(10) )
		std::cout << "Remoção de elemento existente funcionando!" << std::endl;
	else
		std::cout << "Remoção de elemento existente falhou!" << std::endl;

	
	// Testando remoção de elemento não existente
	if ( tree.remove(10) )
		std::cout << "Remoção de elemento não existente funcionando!" << std::endl;
	else
		std::cout << "Remoção de elemento não existente falhou!" << std::endl;
	

	std::cout << tree.toString() << endl;

	std::cout << "-----------ENÉSIMO-----------" << endl;
	std::cout << tree.enesimo(1) << endl;
	std::cout << tree.enesimo(2) << endl;
	std::cout << tree.enesimo(3) << endl;
	std::cout << tree.enesimo(4) << endl;
	std::cout << tree.enesimo(5) << endl;
	std::cout << tree.enesimo(6) << endl;

	std::cout << "-----------POSITION-----------" << endl;
	std::cout << tree.position(8) << endl;
	std::cout << tree.position(4) << endl;
	std::cout << tree.position(5) << endl;
	std::cout << tree.position(10) << endl;
	std::cout << tree.position(12) << endl;
	std::cout << tree.position(15) << endl;

	std::cout << "-----------MEDIAN-----------" << endl;
	std::cout << tree.median() << endl;


	return 0;
}
