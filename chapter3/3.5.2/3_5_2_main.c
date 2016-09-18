#include <stdlib.h>
#include <stdio.h>

extern void dynamic_lib_call(void);

int main(void)
{
    dynamic_lib_call();

    return 0;
}

