#include "gc.hpp"
#include "heap.hpp"
#include "includes.hpp"

static void leak1();
static void leak2();
static void leak3();

static void printHeapUsed();

int main(int argc, char* argv[])
{
    GarbageCollector gc(&argc);

    std::cout << "Memory before leak!\n";
    printHeapUsed();

    std::cout << "Let's memory leak!\n";
    leak1();
    leak2();
    leak3();

    std::cout << "Memory after leak!\n";
    printHeapUsed();

    std::cout << "Let's start GC!\n";
    gc.GoGC();

    std::cout << "Memory after GC!\n";
    printHeapUsed();

    gc.end();
}

void error(string& message)
{
    std::cerr << "Error : " << message << std::endl;
    std::exit(-1);
}

static void leak1()
{
    char* c = (char*)HeapAllocator::get().alloc(14);
    std::memcpy(c, "Hello, World!", 14);

    std::cout << "Leak 1 / char* c : " << (void*)c << std::endl;
}

static void leak2()
{
    typedef struct {
        int a;
        int b;
        char c;
        char d;
        short e;
    } Test;

    Test* t = (Test*)HeapAllocator::get().alloc(sizeof(Test));

    t->a = 1;
    t->b = 2;
    t->c = 3;
    t->d = 4;
    t->e = 5;

    std::cout << "Leak 2 / Test* t : " << t << std::endl;
}

static void leak3()
{
    void* ptr = HeapAllocator::get().alloc(0x20);
    std::cout << "Leak 3 / void* ptr : " << ptr << std::endl;
}

static void printHeapUsed()
{
    std::cout << "\n-----[ Heap Used ]-----";
    std::cout << "\n Max\t: " << HeapAllocator::get().max();
    std::cout << "\n Used\t: " << HeapAllocator::get().used();
    std::cout << "\n-----[ Heap Used ]-----\n";
}