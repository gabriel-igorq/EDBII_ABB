#include <iostream>

#include "../include/ABB.hpp"

int main() {
    std::cout << "Iniciando Testes:" << std::endl;

    ABB* abb = new ABB();

    //Testando construtor
    Node* raiz = abb->getRaiz();
    if(raiz == nullptr){
    	cout << "Construtor OK!" << endl;
    }
    
    
    //Testando inserção
    abb->insercao(8);
    int size = abb->getSize();
    if(size == 1){
    	cout << "8 inserido!" << endl;	
    }
    

    //Testando inserção em árvore contendo um elemento
    abb->insercao(4);
    size = abb->getSize();
    if(size == 2){
    	cout << "4 inserido!" << endl;	
    }

    //Testando inserção em árvore contendo um elemento
    abb->insercao(10);
    size = abb->getSize();
    if(size == 3){
		cout << "10 inserido!" << endl;    	
    }


    //Testando inserção em árvore contendo um elemento
    abb->insercao(12);
    size = abb->getSize();
    if(size == 4){
    	cout << "12 inserido!" << endl;	
    }
    

    //Testando busca
    Node* tmp = abb->busca(10);
    if(tmp->dado == 10){
		cout << "Busca funcionando!" << endl;    	
    }


    return 0;
}
