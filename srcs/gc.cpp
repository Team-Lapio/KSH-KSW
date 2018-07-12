#include "gc.hpp"
#include "heap.hpp"
#include "includes.hpp"

GarbageCollector::GarbageCollector(void* bottom)
    : bottom(bottom)
{
}

static HeapAllocator& heap = HeapAllocator::get();
void GarbageCollector::GoGC()
{
    for (Chunk* c = heap.base->allocated.next;
         (c = c->next) != nullptr;) {
        c->flag = false;
    }

    mark_stack();
    mark_heap();

    sweep();
}

void GarbageCollector::mark_stack()
{
    void* sp;
    char* p;

    std::cout << "Stack pointer is : " << sp << "\n";

    if (sp < bottom) {
        for (p = (char*)sp; p >= bottom; p--) {
            check(p);
        }
    } else if (sp > bottom) {
        for (p = (char*)bottom; p <= sp; p++) {
            check(p);
        }
    } else {
        return;
    }
}

void GarbageCollector::mark_heap()
{
    char* p;
    for (p = (char*)heap.base;
         p <= ((char*)heap.base) + heap.base->base_size; p++) {
        check(p);
    }
}

void GarbageCollector::sweep()
{
    Chunk* c;
    while ((c = heap.base->allocated.next) != nullptr) {
        if (!c->flag) {
            heap.free(c->data);
            std::cout << "Sweeped : " << (void*)c->data << "\n";
        } else {
            break;
        }
    }

    while (c != nullptr && c->next != nullptr) {
        if (!c->next->flag) {
            std::cout << "Sweeped : " << (void*)c->next->data << "\n";
            heap.free(c->next->data);
        } else {
            c = c->next;
        }
    }
}

void GarbageCollector::check(void* ptr)
{
    void* ptr2 = (void*)(*(unsigned int*)ptr);
    if (ptr2 >= (void*)heap.base
        && ptr2 <= ((char*)heap.base) + heap.base->base_size) {
        for (Chunk* c = heap.base->allocated.next;
             (c = c->next) != nullptr;) {
            if ((char*)c->data == (char*)ptr2) {
                std::cout << (void*)c->data << " is used at : " << ptr << "\n";
                c->flag = true;
                return;
            }
        }
    }
}

void GarbageCollector::end()
{
    HeapAllocator::get().free_all();
}