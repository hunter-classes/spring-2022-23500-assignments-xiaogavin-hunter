main: main.o Node.o 
	g++ -o main main.o Node.o 

main.o: main.cpp Node.h

node.o: Node.h Node.cpp

clean: 
	rm -f Node.o main.o 