PROG = bin/teste
CC = g++
CPPFLAGS = -O0 -g -W -Wall -pedantic -std=c++14
OBJS = teste.o ABB.o
RM = -f *.o

$(PROG) : $(OBJS)
	$(CC)  $(OBJS) -o $(PROG)
	mv *.o build/

ABB.o : include/ABB.hpp
	$(CC) $(CPPFLAGS) -c src/ABB.cpp

teste.o : include/ABB.hpp
	$(CC) $(CPPFLAGS) -c src/teste.cpp

clean:
	rm -f $(PROG) build/*.o