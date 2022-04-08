main: main.o List.o Node.o stack.o
	g++ -o main main.o List.o Node.o stack.o

tests: tests.o 
	g++ -o tests tests.o 

List.o: List.cpp List.h Node.h

main.o: main.cpp stack.h List.h Node.h

Node.o: Node.cpp Node.h

stack.o: stack.cpp stack.h List.h Node.h

tests.o: tests.cpp doctest.h

clean: 
	rm -f tests.o main.o l