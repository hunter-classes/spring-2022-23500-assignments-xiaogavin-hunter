main: List.o Node.o OList.o ONode.o main.o 
	g++ -o main List.o Node.o OList.o ONode.o main.o

tests: tests.o
	g++ -o tests tests.o

List.o: List.cpp List.h Node.h

Node.o: Node.cpp Node.h

OList.o: OList.cpp OList.h ONode.h

ONode.o: ONode.cpp ONode.h

main.o: main.cpp OList.h ONode.h

tests.o: tests.cpp doctest.h OList.h ONode.h


clean: 
	rm -f List.o Node.o OList.o ONode.o main.o tests.o main tests