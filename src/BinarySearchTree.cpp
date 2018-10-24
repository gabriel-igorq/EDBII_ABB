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
	Type data;
	Node* aux = this->root;
	while (aux != nullptr) {
		data = aux->data;
		if (data == value) {
			return aux;
		} else if (data > value) {
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
	Type data = node->data;

	if ( data != value ) {
		if (data < value) { // Inserir do lado right_childeito
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
		} else { // Inserir do lado left_childuerdo
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

bool BinarySearchTree::remove(const Type value) {
	return remove(this->root, value);
}

bool BinarySearchTree::remove(Node* node, const Type value) {
	if ( node->data == value ) {
		return true;
	}
	else {
		return false;
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
