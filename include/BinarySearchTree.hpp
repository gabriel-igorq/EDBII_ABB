#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include "Node.hpp"
#include <string>
#include <queue>
#include <cmath>

typedef int Type;

class BinarySearchTree {
    private:

	Node* root;

	unsigned int size;
	unsigned int height;

	bool insert(Node* node, const Type key);
	bool remove(const Type key, Node*& node);
	Node* minValue(Node* root);

    public:

	BinarySearchTree(Node* root = nullptr);
	~BinarySearchTree();

	Node* getRoot();

	int getSize();
	int getHeight();

	void destroy(Node* node);
	Node* search(const Type key);
	bool insert(const Type key);
	bool remove(const Type key);

	int enesimo(const int n);
	int position(const Type key);
	int median();
	bool isFull();
	bool isComplete();
	std::string toString();
};

#include "../src/BinarySearchTree.cpp"

#endif
