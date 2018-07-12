#include "gc.hpp"
#include<stdlib.h>
void list_init(){
    head->prev=NULL;   
    head->next=NULL;
    int size=sizeof(Chunk);
}

void GoGC(){
    Chunk *now = head->next;
    while(now->next){
        if(now->flag == false)
            free(now);
        now = now->next;
    }
}
void* HeapAllocator::alloc(std::size_t size){
    // ? val 
    // malloc(size);
    // memset(val,0,size);
}