#Makefile

all: add-nbo

add-nbo: add-nbo.o
	g++ -o add-nbo add-nbo.o main.o

add-nbo.o: add-nbo.c
	gcc -c add-nbo.c -o add-nbo.o

main.o: main.h main.cpp

clean:
	rm add-nbo *.o

