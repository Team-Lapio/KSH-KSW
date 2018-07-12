#include "heap.hpp"
#include "includes.hpp"

HeapAllocator::HeapAllocator()
{
    base = (HeapBase*)malloc(sizeof(HeapBase) + BASE_SIZE);

    base->base_size = BASE_SIZE;
    base->pointer = 0;

    base->free_bin.next = nullptr;
    base->allocated.next = nullptr;
}

HeapAllocator::~HeapAllocator()
{
    free(base);
}
void* HeapAllocator::alloc(std::size_t size)
{
    if (size < 1) {
        throw invalid_size();
    }
    if (base->free_bin.next != nullptr) {
        Chunk* c = base->free_bin.next;
        BaseChunk* prev = &base->free_bin;
        do {
            if (c->size == size) {
                prev->next = c->next;
                return &c->data;
            }
            prev = c;
        } while ((c = c->next) != nullptr);
    }
    if (base->pointer + size >= base->base_size) {
        throw not_enough_field();
    }

    Chunk* chunk = (Chunk*)(((char*)&base->datas) + base->pointer);
    base->pointer += sizeof(Chunk) + size;

    chunk->size = size;
    chunk->next = nullptr;

    BaseChunk* last = &base->allocated;
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = chunk;

    return &chunk->data;
}
void HeapAllocator::free(void* ptr)
{
    Chunk* c = (Chunk*)(((char*)ptr) - sizeof(Chunk));

    BaseChunk* last = &base->allocated;
    while (last->next != nullptr) {
        if (c == last->next) {
            break;
        }
        last = last->next;
    }

    if (last == nullptr) {
        throw already_free_or_not_alloc();
    }

    last->next = c->next;

    last = &base->free_bin;
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = c;
    c->next = nullptr;
}

void HeapAllocator::free_all()
{
    if (base->allocated.next == nullptr) {
        return;
    }
    Chunk* c;
    while ((c = base->allocated.next)->next != nullptr) {
        free(c->next->data);
    }
}

int HeapAllocator::max()
{
    return base->base_size;
}

int HeapAllocator::used()
{
    int i = 0;
    if (base->allocated.next != nullptr) {
        Chunk* bsc = base->allocated.next;
        i += bsc->size;
        while ((bsc = bsc->next) != nullptr) {
            i += bsc->size;
        }
    }
    return i;
}