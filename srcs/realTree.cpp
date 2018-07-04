#include"includes.hpp"

static int GetParentIDX(int idx) {
	return idx / 2;
}

static int GetLChildIDX(int idx) {
	return idx * 2;
}

static int GetRChildIDX(int idx) {
	return GetLChildIDX(idx) + 1;
}

static int GetHiPriChildIDX(Heap& ph, int idx) {
	if (GetLChildIDX(idx) > ph.numOfData)
		return 0;
	else if (GetLChildIDX(idx) == ph.numOfData)
		return GetLChildIDX(idx);
	else {
		if (ph.comp(ph.heapArr[GetLChildIDX(idx)], ph.heapArr[GetRChildIDX(idx)]) < 0)
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}
}


void HeapInit(Heap& ph, PriorityComp pc) {
	ph.numOfData = 0;
	ph.comp = pc;
}

int HIsEmpty(Heap& ph) {
	if (ph.numOfData == 0)
		return 1;
	else
		return 0;
}

void HInsert(Heap& ph, HData data) {
	int idx = ph.numOfData + 1;

	while (idx != 1){
		if (ph.comp(data, ph.heapArr[GetParentIDX(idx)]) > 0) {
			ph.heapArr[idx] = ph.heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else
			break;
	}
	ph.heapArr[idx] = data;
	ph.numOfData += 1;
}

HData Hdelete(Heap& ph) {
	HData retData = ph.heapArr[1];
	HData lastElem = ph.heapArr[ph.numOfData];

	int parentIDX = 1;
	int childIDX;

	while (childIDX = GetHiPriChildIDX(ph, parentIDX)) {
		if (ph.comp(lastElem, ph.heapArr[childIDX]) >= 0)
			break;

		ph.heapArr[parentIDX] = ph.heapArr[childIDX];
		parentIDX = childIDX;
	}
	
	ph.heapArr[parentIDX] = lastElem;
	ph.numOfData -= 1;
	return retData;
}

void OnUsing(Heap& ph){
	ph.flag = true; //죄송해여 //IM SO SORRY BUT I LOVE YOU
}

void OffUsing(Heap& ph){
	ph.flag = false;
}