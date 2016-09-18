#include <stdlib.h>
#include <stdio.h>

static void __attribute__ ((constructor)) before_main(void)
{
    printf("Before main...\n");
}

int main(void)
{
    printf("Main!\n");
    return 0;
}

