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
    this->root = remove(key, this->root);
	return this->root != nullptr;
}

Node* BinarySearchTree::remove(const Type key, Node* root) {
    if (root == nullptr)
        return root;

    if (key < root->key) {
        root->left_child = remove(key, root->left_child);
    }
    else if (key > root->key) {
        root->right_child = remove(key, root->right_child);
    }
    else {
        if (root->left_child == nullptr && root->right_child == nullptr) {
            delete(root);
        }
        else if (root->left_child == nullptr) {
            Node* aux = root->right_child;
            delete(root);
            return aux;
        }
        else if (root->right_child == nullptr) {
            Node* aux = root->left_child;
            delete(root);
            return aux;
        }
        Node* aux = minValue(root->right_child);
        root->key = aux->key;
        root->right_child = remove(aux->key, root->right_child);
    }

    return root;
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
