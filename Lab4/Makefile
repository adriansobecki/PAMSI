#__start__: projekt4
#	./projekt4

all: projekt4

projekt4: main.o kolko_krzyzyk.o
	g++ -o projekt4 main.o kolko_krzyzyk.o

main.o:
	g++ -c -o main.o main.cpp

kolko_krzyzyk.o:
	g++ -c -o kolko_krzyzyk.o kolko_krzyzyk.cpp

clean:
	rm -f *.o projekt3