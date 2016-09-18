#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>

int main()
{
    void *dlib = dlopen("./libdlib.so", RTLD_NOW);
    if (!dlib) {
        printf("dlopen failed\n");
        return -1;
    }

    void (*dfunc) (void) = dlsym(dlib, "dynamic_lib_call");
    if (!dfunc) {
        printf("dlsym failed\n");
        return -1;
    }

    dfunc();

    dlclose(dlib);

    return 0;

}

