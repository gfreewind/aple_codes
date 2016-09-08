#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    const char str[] = "123456789";
    FILE *fp = fopen("tmp.txt", "w");
    size_t size = fwrite(str, strlen(str), 1, fp);

    printf("size is %d\n", size);

    fclose(fp);

    return 0;
}

