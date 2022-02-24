main: main.o Node.o List.o
	g++ -o main main.o Node.o List.o

main.o: main.cpp Node.h List.h

node.o: Node.h Node.cpp

List.o: List.cpp List.h

clean: 
	rm -f Node.o main.o List.o