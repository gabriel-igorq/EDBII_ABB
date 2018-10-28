#include "../include/BinarySearchTree.hpp"

using namespace std;

BinarySearchTree::BinarySearchTree(Node* root){
	this->root = root;
	size = 0;
	height = 0;
}

BinarySearchTree::~BinarySearchTree() { 
    destroy(root); 
}

void BinarySearchTree::destroy(Node* node) {
    if (node != nullptr) {
		Node* left = node->left_child;
		node->left_child = nullptr;

		Node* right = node->right_child;
		node->right_child = nullptr;

		destroy(left);
		destroy(right);

		node->father = nullptr;
		delete node;
    }
}

Node* BinarySearchTree::search(const Type value) {
	Type key;
	Node* aux = this->root;
	while (aux != nullptr) {
		key = aux->key;
		if (key == value) {
			return aux;
		} else if (key > value) {
			aux = aux->left_child;
		} else {
			aux = aux->right_child;
		}
	}
	return nullptr;
}

// Inserção em árvore vazia
bool BinarySearchTree::insert(const Type value) {
    if (root == nullptr) {
	    root = new Node(value, 1, nullptr);
	    height = 1;
	    size = 1;
	    return true;
    } else {
	    return insert(root, value);
    }
}

// Inserção em árvore não vazia
bool BinarySearchTree::insert(Node* node, const Type value) {
	Type key = node->key;

	if ( key != value ) {
		if (key < value) {
			if (node->right_child == nullptr) {
				node->right_child = new Node(value, node->level + 1, node);
				if (node->right_child->level > height) {
				++height;
				}
				++size;
				++node->right_subtrees_count;
				return true;
			} else if (insert(node->right_child, value)) {
				++node->right_subtrees_count;
				return true;
			}
		} else {
			if (node->left_child == nullptr) {
				node->left_child = new Node(value, node->level + 1, node);
				if (node->left_child->level > height) {
					++height;
				}
				++size;
				++node->left_subtrees_count;
				return true;
			} else if (insert(node->left_child, value)) {
				++node->left_subtrees_count;
				return true;
			}
		}
	}
	return false;
}

Node* BinarySearchTree::minValue(Node* root) {
    Node* curr = root;
    while (curr->left_child != nullptr)
        curr = curr->left_child;
    return curr;
}

bool BinarySearchTree::remove(const Type key) {
    return remove(key, this->root);
}

bool BinarySearchTree::remove(const Type key, Node* node) {
	bool found = false;
	Node* predecessor=nullptr;
	Node* current=node;
	if(current==nullptr) {
		 return found;
	}
	while(current!=nullptr) {
		if(current->key==key) {
			found = true;
			break;
		}
		else {
			predecessor = current;
			if(key > (current->key))
				current=current->right_child;
			else
				current=current->left_child;
		}
	}
	if(!found) {
		return found;
	}
	if((current->left_child==nullptr && current->right_child != nullptr) || (current->left_child != nullptr && current->right_child==nullptr)) {
		if(current->left_child==nullptr && current->right_child != nullptr) {
			if(predecessor->left_child==current) {
				predecessor->left_child=current->right_child;
				delete current;
				current=nullptr;
			}
			else
			{
				predecessor->right_child=current->right_child;
				delete current;
				current=nullptr;
			}
		}
		else {
			if(predecessor->left_child==current)
			{
				predecessor->left_child=current->left_child;
				delete current;
				current=nullptr;
			}
			else
			{
				predecessor->right_child=current->left_child;
				delete current;
				current=nullptr;
			}
		}
		return found;
	}
	if(current->left_child==nullptr && current->right_child==nullptr)
	{
		if(predecessor->left_child==current)
			predecessor->left_child=nullptr;
		else
			predecessor->right_child=nullptr;
		delete current;
		return found;
	}
	if(current->left_child != nullptr && current->right_child != nullptr)
	{
		Node* check=current->right_child;
		if((current->left_child==nullptr)&&(current->right_child==nullptr))
		{
			current=check;
			delete check;
			current->right_child==nullptr;
		}
		else
		{
			if((current->right_child)->left_child!=nullptr)
			{
				Node* leftCurrent;
				Node* leftCurrentPred;
				leftCurrentPred=current->right_child;
				leftCurrent=(current->right_child)->left_child;
				while(leftCurrent->left_child != nullptr)
				{
					leftCurrentPred=leftCurrent;
					leftCurrent=leftCurrent->left_child;
				}
				current->key=leftCurrent->key;
				delete leftCurrent;
				leftCurrentPred->left_child==nullptr;
			}
			else
			{
				Node* temp=current->right_child;
				current->key=temp->key;
				current->right_child=temp->right_child;
				delete temp;
			}
		}
		return found;
	}
}

Node* BinarySearchTree::getRoot() { 
    return root; 
}

int BinarySearchTree::getSize() { 
    return size; 
}

int BinarySearchTree::getHeight() { 
    return height; 
}

int BinarySearchTree::enesimo(const int n) {
    int tmp = 0; //Qtd de nós a esquerda do nó atual + ele mesmo
    int acc = 0;
    Node* current = root;
    while (current != nullptr) {
        tmp = current->left_subtrees_count + 1;
        // Se tmp == valor, então retorna raiz
        if (acc + tmp == n) {
            return current->key;
        }
        // Se tmp < valor, então está do lado direito
        if (acc + tmp < n) {
            acc += tmp;
            current = current->right_child;
        } else { 
            current = current->left_child;
        }
    }
    return false;
}

int BinarySearchTree::position(const Type key) {
    int tmp = 0; // Qtd de nós a esquerda do nó atual + ele mesmo
    int acc = 0; // Acumulador
    Node* current = root;
    while (current != nullptr) {
        tmp = current->left_subtrees_count + 1;
        if (current->key == key) {
            return tmp + acc;
        }
        if (current->key < key) {
            acc += tmp;
            current = current->right_child;
        } else { 
            current = current->left_child;
        }
    }
    return false;
}

int BinarySearchTree::median() {
    if (size % 2 == 0) {
        return enesimo(size / 2);
    } else {
        return enesimo((size / 2) + 1);
    }
}

bool BinarySearchTree::isFull(){
	return size == pow(2,getHeight()) - 1;
}

bool BinarySearchTree::isComplete(){

	if(isFull()){
		return true;
	}

	if(root == nullptr){
		return false;
	}

	// Conta os nós lidos em cada nível
	int cont = 0;
	// Armazena a quantidade máxima de nós por nível
	int level = 1;
	// Indica se está no penúltimo nível
    bool penultimate = false;
    // Indica se está no último nível
    bool last = false;

    queue<Node*> queue;
    Node* actual = root;
    queue.push(actual);

    while (!queue.empty()) {
    	cont++;
        Node* actual = queue.front();
        queue.pop();

        if(actual->left_child != nullptr or actual->right_child != nullptr){
        	if(last){
        		return false;
        	}
        }

        if(actual->right_child != nullptr){
        	queue.push(actual->right_child);
        }

        if(actual->left_child != nullptr){
        	queue.push(actual->left_child);
        }

        if(actual->left_child == nullptr or actual->right_child == nullptr){
        	penultimate = true;
        }

        //Verifica se todos os nós daquele nível foram lidos
		if(cont == level){
			cont = 0;
			level = level*2;
			if(penultimate){
				last = true;
			}
		}
    }

	return true;   
}

string BinarySearchTree::toString(){
    string keys;
    queue<Node*> queue;
    Node* node = root;
    
    queue.push(node);
    while (!queue.empty()) {
        node = queue.front();
        queue.pop();
        keys += to_string(node->key) + " ";
        if (node->left_child != nullptr) {
            queue.push(node->left_child);
        }
        if (node->right_child != nullptr) {
            queue.push(node->right_child);
        }
    }
    return keys;
}
