#ifndef NODE_HPP
#define NODE_HPP

typedef int Type;

struct Node {
	public:
		Node(
			Type value,
			int nivel = 0,
			Node* father = nullptr,
			Node* left_child = nullptr,
			Node* right_child = nullptr
		);

		Type data;

		Node* father;
		Node* left_child;
		Node* right_child;

		unsigned int left_subtrees_count;
		unsigned int right_subtrees_count;
		unsigned int level;
};

#include "../src/Node.cpp"

#endif
