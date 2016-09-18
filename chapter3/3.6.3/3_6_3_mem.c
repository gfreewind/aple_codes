#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void mem_leak1(void)
{
    char *p = malloc(1);
}

static void mem_leak2(void)
{
    FILE *fp = fopen("test.txt", "w");
}

static void mem_overrun1(void)
{
    char *p = malloc(1);
    *(short*)p = 2;

    free(p);
}

static void mem_overrun2(void)
{
    char array[5];
    strcpy(array, "hello");
}

static void mem_double_free(void)
{
    char *p = malloc(1);
    free(p);
    free(p);
}

static void mem_free_wild_pointer(void)
{
    char *p;
    free(p);
}


int main()
{
    mem_leak1();
    mem_leak2();
    mem_overrun1();
    mem_overrun2();
    mem_double_free();
    mem_free_wild_pointer();

    return 0;
}

