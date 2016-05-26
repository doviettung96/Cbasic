#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "dlink.h"

typedef struct {
	dlist *list;
	void *position;
} queue_type;

int Qempty(queue_type *q);
queue_type *iniQueue();
void enQueue(void *val, queue_type *q);
void *deQueue(queue_type *q);
// void traverse(queue_type *q);
void removeQueue(queue_type *q);
#endif