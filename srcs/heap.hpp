#ifndef __HEAP_HEADER__
#define __HEAP_HEADER__

#include "includes.hpp"

struct BaseChunk;
struct Chunk;
struct HeapBase;
class HeapAllocator;

struct not_enough_field {
};
struct invalid_size {
};
struct already_free_or_not_alloc {
};

struct BaseChunk {
    Chunk* next;
};
struct Chunk : BaseChunk {
    bool flag;
    std::size_t size;

    char data[];
};

struct HeapBase {
    int base_size;
    int pointer;

    // Chunk* free_bin;
    // Chunk* allocated;

    BaseChunk free_bin{ nullptr };
    BaseChunk allocated{ nullptr };

    char datas[];
};

class HeapAllocator {
private:
    const int BASE_SIZE = 1024 * 10;
    HeapBase* base;

    friend class GarbageCollector;

    HeapAllocator();

    HeapAllocator(HeapAllocator& other) = delete;
    HeapAllocator(const HeapAllocator& other) = delete;
    HeapAllocator& operator=(HeapAllocator& other) = delete;
    HeapAllocator& operator=(const HeapAllocator& other) = delete;

public:
    static HeapAllocator& get()
    {
        static HeapAllocator instance;
        return instance;
    }

    void* alloc(std::size_t size);
    void free(void* ptr);

    int max();
    int used();
};

#endif