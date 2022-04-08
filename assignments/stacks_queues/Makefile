main: main.o 
	g++ -o main main.o 

tests: tests.o 
	g++ -o tests tests.o 

tests.o: tests.cpp doctest.h 

clean: 
	rm -f tests.o main.o 