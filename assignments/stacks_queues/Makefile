main: main.o List.o Node.o stack.o queue.o
	g++ -o main main.o List.o Node.o stack.o queue.o

tests: tests.o List.o Node.o stack.o queue.o
	g++ -o tests tests.o List.o Node.o stack.o queue.o

List.o: List.cpp List.h Node.h

main.o: main.cpp stack.h List.h Node.h queue.h

Node.o: Node.cpp Node.h

queue.o: queue.cpp queue.h

stack.o: stack.cpp stack.h List.h Node.h

tests.o: tests.cpp doctest.h stack.h List.h Node.h queue.h


clean: 
	rm -f tests.o main.o List.o Node.o stack.o queue.o main tests