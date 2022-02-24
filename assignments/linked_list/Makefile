main: main.o Node.o List.o
	g++ -o main main.o Node.o List.o

List.o: List.cpp List.h Node.h


main.o: main.cpp List.h Node.h

Node.o: Node.cpp Node.h


clean: 
	rm -f Node.o main.o List.o main