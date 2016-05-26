all: test
test: test.o link.o 
	gcc -o test link.o test.o
test.o: test.c
	gcc -c test.c
link.o: link.c
	gcc -c link.c

