Node::Node(Type key, unsigned int level, Node* father, Node* left_child, Node* right_child) {
	this->father = father;
	this->left_child = left_child;
	this->right_child = right_child;
	left_subtrees_count = 0;
	right_subtrees_count = 0;
	this->key = key;
	this->level = level;
}
