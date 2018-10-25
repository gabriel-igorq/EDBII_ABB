#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include "Node.hpp"

typedef int Type;

class BinarySearchTree {
    private:

	Node* root;

	unsigned int size;
	unsigned int height;

	bool insert(Node* node, const Type value);
	Node* remove(const Type value, Node* node);
	Node* minValue(Node* root);

    public:

	BinarySearchTree(Node* root = nullptr);
	~BinarySearchTree();


	Node* getRoot();

	int getSize();
	int getHeight();

	void destroy(Node* node);
	Node* search(const Type value);
	bool insert(const Type value);
	bool remove(const Type value);
};

#include "../src/BinarySearchTree.cpp"

#endif
