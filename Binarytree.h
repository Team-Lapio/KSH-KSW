#pragma once
#include<stdbool.h>

#define HEAP_LEN 100

typedef char HData;
typedef int PriorityComp(HData d1, HData d2);

typedef struct Heap {
	bool flag;
	PriorityComp* comp;
	int numOfData;
	HData heapArr[HEAP_LEN];
}Heap;

void HInsert(Heap *hp, HData data);
void HeapInit(Heap* ph, PriorityComp pc);
int HIsEmpty(Heap* ph);
HData Hdelete(Heap *ph);
