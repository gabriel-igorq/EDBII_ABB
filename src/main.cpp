#include <iostream>
#include <string>
#include <fstream>
#include "../include/Node.hpp"
#include "../include/BinarySearchTree.hpp"


int main(int argc, char *argv[]) {
	BinarySearchTree tree;

	string tree_file = argv[1];
	std::ifstream tree_inputs;
	tree_inputs.open("data/" + tree_file);
	if ( tree_inputs.is_open() ) {
		string str;
		while ( std::getline(tree_inputs, str, ' ') ) {

			int key = std::stoi(str);
			tree.insert(key);

		}
	}
	std::cout << tree.toString() << std::endl;

	string commands_file = argv[2];
	std::ifstream command_inputs;
	command_inputs.open("data/" + commands_file);
	if ( command_inputs.is_open() ) {
		string line;
		while ( std::getline(command_inputs, line) ) {

			std::cout << strtok(line,' ') << std::endl;

		}
	}
	return 0;
}
