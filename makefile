prog2: main.o prim.o vertex.o 
	g++ main.o prim.o vertex.o -o prog2

main.o: main.cpp prim.h 
	g++ -g -c main.cpp

prim.o: prim.cpp prim.h
	g++ -g -c prim.cpp 

vertex.o: vertex.cpp vertex.h
	g++ -c vertex.cpp

clean:
	rm prog2 main.o prim.o vertex.o 

all:
	make prog2 main.o prim.o vertex.o 