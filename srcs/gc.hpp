#ifndef __GC_HEADER__
#define __GC_HEADER__

#include "includes.hpp"

class GarbageCollector {
private:
    void* bottom;

public:
    GarbageCollector(void* bottom);
    
    void GoGC();
    void end();
};

#endif