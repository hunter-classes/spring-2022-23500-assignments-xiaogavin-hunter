main: List.o main.o Node.o Person.o Dictionary.o
	g++ -o main List.o main.o Node.o Person.o Dictionary.o

tests: tests.o Person.o Node.o List.o Dictionary.o
	g++ -o tests tests.o Person.o Node.o List.o Dictionary.o

Dictionary.o: Dictionary.cpp Dictionary.h Person.h List.h Node.h
List.o: List.cpp List.h Node.h Person.h
main.o: main.cpp Dictionary.h Person.h List.h Node.h
Node.o: Node.cpp Node.h Person.h
Person.o: Person.cpp Person.h
tests.o: tests.cpp doctest.h Dictionary.h Person.h List.h Node.h

clean: 
	rm -f tests.o Person.o Node.o List.o Dictionary.o main.o main tests