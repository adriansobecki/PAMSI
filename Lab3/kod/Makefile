#__start__: projekt3
#	./projekt3

all: projekt3

projekt3: projekt_grafy.o list_graph.o matrix_graph.o base_graph.o
	g++ -o projekt3 projekt_grafy.o list_graph.o matrix_graph.o base_graph.o

projekt_grafy.o:
	g++ -c -o projekt_grafy.o projekt_grafy.cpp

list_graph.o:
	g++ -c -o list_graph.o list_graph.cpp

matrix_graph.o:
	g++ -c -o matrix_graph.o matrix_graph.cpp

base_graph.o:
	g++ -c -o base_graph.o base_graph.cpp

clean:
	rm -f *.o projekt3