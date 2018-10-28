#include <iostream>
#include "../include/Node.hpp"
#include "../include/BinarySearchTree.hpp"


int main() {
	std::cout << "Iniciando Testes:" << std::endl;

	BinarySearchTree tree;

	//Testando construtor
	Node* root = tree.getRoot();
	
	tree.insert(8);
	tree.insert(4);
	tree.insert(10);
	tree.insert(12);
	tree.insert(5);
	tree.insert(14);

	std::cout << tree.toString() << endl;

	//Testando busca
	Node* tmp = tree.search(10);
	if(tmp->key == 10) {
		std::cout << "Busca funcionando!" << std::endl;    	
	}

	std::cout << "Cheia? " << tree.isFull() << endl;
	std::cout << "Completa? " << tree.isComplete() << endl;	
	
	tree.remove(8);
	std::cout << tree.toString() << endl;
	
	
	// Testando remoção de elemento existente
	/*if ( tree.remove(10) )
		std::cout << "Remoção de elemento existente funcionando!" << std::endl;
	else
		std::cout << "Remoção de elemento existente falhou!" << std::endl;

	
	// Testando remoção de elemento não existente
	if ( tree.remove(10) )
		std::cout << "Remoção de elemento não existente funcionando!" << std::endl;
	else
		std::cout << "Remoção de elemento não existente falhou!" << std::endl;
	*/
/*
	std::cout << tree.toString() << endl;
	tree.remove(8);
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

*/
	return 0;
}
