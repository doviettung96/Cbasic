#include "queue.h"
#include "menu.h"

#define MAX 4

typedef struct turn{
	
}

void main(int argc, char **argv){
	int num;
	int choice;
	num = atoi(argv[1]);
	queue_type *q;
	FILE *f;
	char sections[MAX][LENGTH] = {"Adding customer", "Directing customer to a queue", "Reporting", "Exit"};
	iniQueue(q);

	do{
		choice = getMenu(sections, MAX);
		switch(choice){
			case 1: break;
			case 2: break;
			case 3: break;
			case 4: exit(1); break;
			default: printf("Choice must be from 1 to 4\n");
			break;
		}
	}while(choice != 4);
}	