#include <iostream>
#include <string>
#include <fstream>
#include "../include/Node.hpp"
#include "../include/BinarySearchTree.hpp"

void execute_command(string command, BinarySearchTree& tree);

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

	string commands_file = argv[2];
	std::ifstream command_inputs;
	command_inputs.open("data/" + commands_file);
	if ( command_inputs.is_open() ) {
		string line;
		while ( std::getline(command_inputs, line) ) {

			execute_command(line, tree);

		}
	}
	return 0;
}

void execute_command(string command, BinarySearchTree& tree) {
		string cmd = command.substr(0,5);
		if ( cmd == "ENESI" ) {
			string strn = command.substr(8, command.length());
			int n = std::stoi(strn);
			std::cout << "Enésimo (" << n << "): "  << tree.enesimo(n) << std::endl;
		}
		else if ( cmd == "POSIC" ) {
			string strkey = command.substr(8, command.length());
			int key = std::stoi(strkey);
			std::cout << "Posição (" << key << "): " << tree.position(key) << std::endl;
		}
		else if ( cmd == "MEDIA" ) {
			std::cout << "Mediana: " << tree.median() << std::endl;
		}
		else if ( cmd == "CHEIA" ) {
			if(tree.isFull()){
				std::cout << "Árvore cheia" << std::endl;
			} else {
				std::cout << "Árvore não é cheia" << std::endl;
			}
		}
		else if ( cmd == "COMPL" ) {
			if(tree.isComplete()){
				std::cout << "Árvore completa" << std::endl;
			} else {
				std::cout << "Árvore não é completa" << std::endl;
			}
		}
		else if ( cmd == "IMPRI" ) {
			std::cout << "-----Árvore-----" << std::endl;
			std::cout << tree.toString() << std::endl;
			std::cout << "----------------" << std::endl;
		}
		else if ( cmd == "REMOV" ) {
			string strn = command.substr(7, command.length());
			int n = std::stoi(strn);
			if(tree.remove(n)){
				std::cout << "Remoção realizada com sucesso" << std::endl;
			} else {
				std::cout << "Remoção inválida" << std::endl;
			}
		}
		else if ( cmd == "INSIR" ) {
			string strn = command.substr(7, command.length());
			int n = std::stoi(strn);
			if(tree.insert(n)){
				std::cout << "Inserção realizada com sucesso" << std::endl;
			} else {
				std::cout << "Inserção inválida" << std::endl;
			}
			
		}
 
}
