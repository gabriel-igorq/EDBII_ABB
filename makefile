all:
	@echo "how to use:\n"
	@echo "\tmake build\t\t- Compile your program into /bin folder."
	@echo "\tmake run\t\t- Run compiled executable."
	@echo "\tmake clean\t\t- Clean compiled files."

build: ./src/main.cpp
	@g++ -Wall -std=c++11 -O0 -g -ggdb -Iinclude/ src/main.cpp -o bin/BinarySearchTree

run: ./bin/main
	@./bin/BinarySearchTree

clean:
	@rm -f bin/BinarySearchTree

