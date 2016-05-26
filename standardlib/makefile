all: test ex2015
test: test.o link.o sort.o
	gcc -o test link.o sort.o test.o
ex2015: ex2015.o avl.o
	gcc -o ex2015 ex2015.o avl.o
ex2015.o: ex2015.c
	gcc -c ex2015.c
avl.o: avl.c
	gcc -c avl.c
test.o: test.c
	gcc -c test.c
link.o: link.c
	gcc -c link.c
sort.o: sort.c
	gcc -c sort.c

