#include "gc.hpp"
#include "heap.hpp"
#include "includes.hpp"

GarbageCollector::GarbageCollector(void* bottom)
    : bottom(bottom)
{
}

void GarbageCollector::GoGC()
{
    char dummy[1024];
    void *sp;
    
}

void GarbageCollector::end()
{
}
// Chunk *now = head->next;
// while(now->next){
//     if(now->flag == false)
//         free(now);
//     now = now->next;
// }