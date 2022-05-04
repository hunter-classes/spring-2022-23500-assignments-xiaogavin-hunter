main: main.o Node.o BSTree.o
	g++ -o main main.o Node.o BSTree.o

tests: tests.o Node.o BSTree.o
	g++ -o tests tests.o Node.o BSTree.o

BSTree.o: BSTree.cpp BSTree.h Node.h
main.o: main.cpp Node.h BSTree.h
Node.o: Node.cpp Node.h
tests.o: tests.cpp doctest.h Node.h BSTree.h



clean: 
	rm -f Node.o main.o BSTree.o tests.o main tests