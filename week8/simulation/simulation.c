#include "queue.h"
#include "menu.h"

#define MAX 4

element_type create(int remMem, int parNum);

void main() {
	int parNum, memNum;
	int choice;
	element_type process;
	queue_type *run;
	queue_type *wait;
	run = iniQueue(run);
	wait = iniQueue(wait);

	char sections[MAX][40] = {"Create new program", "Kill a recent program", "Show programs status", "Exit"};

	printf("Process simulator\n");
	printf("Type in the number of parallel processes: ");
	scanf("%d", &parNum);
	printf("Type in the memory capacity (MB): ");
	scanf("%d", &memNum);

	do {
		choice = getMenu(sections, MAX);
		switch (choice) {
		case 1:
			process = create(memNum, parNum);
			if (process.status == 1)
			{
				memNum -= process.mem;
				parNum--;
				enQueue(process, run);
			}
			else
				enQueue(process, wait);
			break;
		case 2: printf("Kill a recent program\n"); //it seems not to work normally @@
			process = deQueue(run);
			memNum += process.mem;
			parNum++;
			printf("Auto run a waiting program\n");
			process = deQueue(wait);
			if (process.mem < memNum && parNum > 0) //how about priorize a process that has memory < memNum?
			{
				process.status = 1;
				enQueue(process, run);
				memNum -= process.mem;
				parNum--;
			}
			else
			{
				enQueue(process, wait);
				printf("The waiting program doesn't meet the requirements to be re-run\n");
			}
			break;
		case 3:
			printf("Remaining memory: %d (MB)\n", memNum);
			traverse(run);
			traverse(wait);
			break;
		case 4:
			break;
		default: printf("Choice must be from 1 to 4\n");
			break;
		}
	} while (choice != 4);
}

//remMem = remaining memory
element_type create(int remMem, int parNum) {
	element_type n;
	printf("Create a program\n");
	printf("ID: "); scanf("%d", &n.id);
	printf("Memory need (MB): "); scanf("%d", &n.mem);
	if (n.mem > remMem || parNum == 0)
		n.status = 0;
	else
		n.status = 1;
	return n;
}