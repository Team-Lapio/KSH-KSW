#include<stdio.h>
#include<iostream>
#include<Windows.h>
#include"Binarytree.h"

int DataPrioritycomp(char ch1, char ch2) {
	return ch2 - ch1;
	//return ch1-ch2;
}

int main() {
	Heap heap;
	HeapInit(&heap, DataPrioritycomp);
	
	HInsert(&heap, 'A');
	printf("%c \n", Hdelete(&heap));
	HInsert(&heap, 'B');
	printf("%c \n", Hdelete(&heap));
	HInsert(&heap, 'C');
	printf("%c \n", Hdelete(&heap));

	HInsert(&heap, 'A');
	HInsert(&heap, 'B');
	HInsert(&heap, 'C');
	HInsert(&heap, 'D');
	printf("%c \n", Hdelete(&heap));
	printf("%c \n", Hdelete(&heap));

	while (!HIsEmpty(&heap)){
		printf(".%c \n", Hdelete(&heap));
	}
	system("pause");
	return 0;
}