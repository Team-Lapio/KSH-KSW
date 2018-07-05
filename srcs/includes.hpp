#ifndef __INCLUDES_HEADER__
#define __INCLUDES_HEADER__

#include <iostream>
#include <stdbool.h>

const int HEAP_LEN = 128;

typedef char HData;
typedef int PriorityComp(HData d1, HData d2);

typedef struct Heap {
	bool flag;
	PriorityComp* comp;
	int numOfData;
	HData heapArr[HEAP_LEN];
}Heap;
void PreorderTraverse(Heap& ph, int HEAP_LEN);
void OnUsing(Heap& ph);
void OffUsing(Heap& ph);
void HeapInit(Heap& ph, PriorityComp pc);
int HIsEmpty(Heap& ph);
void HInsert(Heap& hp, HData data);
HData Hdelete(Heap& ph);

#endif