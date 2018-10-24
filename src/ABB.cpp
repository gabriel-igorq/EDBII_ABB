#include "../include/ABB.hpp"

Node::Node(tipo valor, int nivel, Node* pai, Node* esq, Node* dir) {
	this->pai = pai;
	this->esq = esq;
	this->dir = dir;
	esq_cnt = 0;
	dir_cnt = 0;
	dado = valor;
	this->nivel = nivel;
}

ABB::ABB(Node* raiz){
	this->raiz = raiz;
	size = 0;
	height = 0;
}

ABB::~ABB() { 
    destruir(raiz); 
}

void ABB::destruir(Node* node) {
    if (node != nullptr) {
		Node* esq = node->esq;
		node->esq = nullptr;

		Node* dir = node->dir;
		node->dir = nullptr;

		destruir(esq);
		destruir(dir);

		node->pai = nullptr;
		delete node;
    }
}

Node* ABB::busca(const tipo valor) {
	tipo dado;
	Node* aux = this->raiz;
	while (aux != nullptr) {
		dado = aux->dado;
		if (dado == valor) {
			return aux;
		} else if (dado > valor) {
			aux = aux->esq;
		} else {
			aux = aux->dir;
		}
	}
	return nullptr;
}

// Inserção em árvore vazia
bool ABB::inserir(const tipo valor) {
    if (raiz == nullptr) {
	    raiz = new Node(valor, 1, nullptr);
	    height = 1;
	    size = 1;
	    return true;
    } else {
	    return inserir(raiz, valor);
    }
}

// Inserção em árvore não vazia
bool ABB::inserir(Node* node, const tipo valor) {
	int dado = node->dado;

	if (dado != valor) {
		if (dado < valor) { // Inserir do lado direito
			if (node->dir == nullptr) {
				node->dir = new Node(valor, node->nivel + 1, node);
				if (node->dir->nivel > height) {
				++height;
				}
				++size;
				++node->dir_cnt;
				return true;
			} else if (inserir(node->dir, valor)) {
				++node->dir_cnt;
				return true;
			}
		} else { // Inserir do lado esquerdo
			if (node->esq == nullptr) {
				node->esq = new Node(valor, node->nivel + 1, node);
				if (node->esq->nivel > height) {
					++height;
				}
				++size;
				++node->esq_cnt;
				return true;
			} else if (inserir(node->esq, valor)) {
				++node->esq_cnt;
				return true;
			}
		}
	}
	return false;
}

bool ABB::remover(const tipo valor) {
	return remover(this->raiz, valor);
}

bool ABB::remover(Node* node, const tipo valor) {
	if ( node->dado == valor ) {
		return true;
	}
	else {
		return false;
	}
}

Node* ABB::getRaiz() { 
    return raiz; 
}

int ABB::getSize() { 
    return size; 
}

int ABB::getHeight() { 
    return height; 
}
