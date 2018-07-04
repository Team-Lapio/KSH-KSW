#include "includes.hpp"

int DataPrioritycomp(char ch1, char ch2) {
	return ch2 - ch1;
	//return ch1-ch2;
}

int main() {
	Heap heap;
	
	HeapInit(heap, DataPrioritycomp);
	
	HInsert(heap, 'A');
	std::cout << Hdelete(heap) << " \n";
	HInsert(heap, 'B');
	std::cout << Hdelete(heap) << " \n";
	HInsert(heap, 'C');
	std::cout << Hdelete(heap) << " \n";

	HInsert(heap, 'A');
	HInsert(heap, 'B');
	HInsert(heap, 'C');
	HInsert(heap, 'D');

	std::cout << Hdelete(heap) << " \n";
	std::cout << Hdelete(heap) << " \n";

	while (!HIsEmpty(heap)){
		std::cout << Hdelete(heap) << " \n";
	}

	return 0;
}