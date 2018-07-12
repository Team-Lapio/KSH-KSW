#ifndef __GC_HEADER__
#define __GC_HEADER__

#include "includes.hpp"
using namespace std;
void GoGC();

struct Chunk;
struct HeapBase;
class HeapAllocator;

// 사용할 때에는
// size
// data (min size : sizeof(void *) * 2)
// ...
//
// 사용하지 않을 때 : free 되었을 때
// size
// next
// prev
// ...

//  bin1    bin2    bin3
//  chunk1  chunk1  chunk1
//    ↓↑
//  chunk2  chunk2
//  ......
// 근데 여기 구현체에서는 bin은 1개만
struct Chunk {
    bool flag;
    int size;
    Chunk* next;
    Chunk* prev;
    char data[];
};
Chunk *head;//, *tail;

struct HeapBase {
    int base_size;
    Chunk* free_bin; // 해제 목록 :)
    Chunk* allocated; // 첫 번째 청크
    char datas[];
};

class HeapAllocator {
private:
                                                                                                                    eapBase* base;
    const int BASE_SIZE = 1024 * 10;

public:
    HeapAllocator();

    void* alloc(std::size_t size);
    void free(void* ptr);
};

void list_init(Chunk* chunk);

#endif