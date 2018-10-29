all:
	@echo "how to use:\n"
	@echo "\tmake build\t\t- Compile your program into /bin folder."
	@echo "\tmake clean\t\t- Clean compiled files."

build: ./src/main.cpp
	@mkdir -p bin/
	@g++ -Wall -std=c++11 -O0 -g -ggdb -Iinclude/ src/main.cpp -o bin/BinarySearchTree

clean:
	@rm -rf bin/

