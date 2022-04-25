main: main.o Node.o BSTree.o
	g++ -o main main.o Node.o BSTree.o

BSTree.o: BSTree.cpp BSTree.h Node.h
main.o: main.cpp Node.h BSTree.h
Node.o: Node.cpp Node.h


clean: 
	rm -f Node.o main.o BSTree.o main