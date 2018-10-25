#ifndef NODE_HPP
#define NODE_HPP

typedef int Type;

struct Node {
	public:
		Node(
			Type key,
			unsigned int level = 0,
			Node* faher = nullptr,
			Node* left_child = nullptr,
			Node* right_child = nullptr
		);

		Type key;

		unsigned int level;

		Node* father;
		Node* left_child;
		Node* right_child;

		unsigned int left_subtrees_count;
		unsigned int right_subtrees_count;
};

#include "../src/Node.cpp"

#endif
