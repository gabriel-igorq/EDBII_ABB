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

bool BinarySearchTree::remove(const Type key, Node *&root) {
    bool removed;

    if (root == nullptr)
        return false;

    if (key < root->key) {
        bool removed = remove(key, root->left_child);

        if (removed)
            root->left_subtrees_count--;

        return removed;
    }
    else if (key > root->key) {
        bool removed = remove(key, root->right_child);

        if (removed)
            root->right_subtrees_count--;

        return removed;
    }
    else {
        if (root->left_child == nullptr && root->right_child == nullptr) {
            delete root;
            root = nullptr;
            return true;
        }
        if (root->left_child == nullptr) {
            Node *tmp = root;
            root = root->right_child;
            delete tmp;
            return true;
        }
        else if (root->right_child == nullptr) {
            Node *tmp = root;
            root = root->left_child;
            delete tmp;
            return true;
        }

        Node **minNode = &root->right_child;

        while ((*minNode)->left_child != nullptr) {
            (*minNode)->left_subtrees_count--;
            minNode = &(*minNode)->left_child;
        }

        root->key = (*minNode)->key;

        delete *minNode;
        *minNode = nullptr;

        removed = true;
    }

    return removed;
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
