#ifndef __GC_HEADER__
#define __GC_HEADER__

#include "includes.hpp"

class GarbageCollector {
private:
    void* bottom;
    
    void mark_stack();
    void mark_heap();

    void sweep();

    void check(void* ptr);

public:
    GarbageCollector(void* bottom);

    void GoGC();
    void end();
};

#endif