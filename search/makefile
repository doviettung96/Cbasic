all: test
test: test.o search.o 
	gcc -o test test.o search.o
test.o: test.c
	gcc -c test.c
search.o: search.c
	gcc -c search.c