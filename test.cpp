#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#define UNW_LOCAL_ONLY
#include <libunwind.h> 


 
static void print_backtrace(void)
{
    unw_context_t context;
    unw_cursor_t cursor;
    unw_word_t off, ip, sp;
    unw_proc_info_t pip;
    char procname[256];
    int ret;
    int a =0;
    a = 3;
 //

    if (unw_getcontext(&context))
        return;
 
    if (unw_init_local(&cursor, &context))
        return;
 
    while (unw_step(&cursor) > 0) {
        if (unw_get_proc_info(&cursor, &pip))
            break;
 
        ret = unw_get_proc_name(&cursor, procname, 256, &off);
        if (ret && ret != -UNW_ENOMEM) {
            procname[0] = '?';
            procname[1] = 0;
        }
 
        unw_get_reg(&cursor, UNW_REG_SP, &sp);
 
        fprintf(stderr,"sp = 0x%lx\n",(long)sp);
    
        //fprintf(stderr, "ip = 0x%lx (%s), sp = 0x%lx\n", (long)ip, procname, (long)sp);
    }

    printf(" \n");
    // fprintf(stderr, "NEW:ip = 0x%lx (%s), sp = 0x%lx\n\n", (long)ip, procname, (long)sp);
}
 
void dummy(void)
{
    print_backtrace();
}
 
int main(void)
{
    dummy();
    printf("----------------------------\n");
    struct Node{
        int data=0;
    };
    Node x;
    int a =3;
    x.data = 10;
    dummy();
    return 0;
}