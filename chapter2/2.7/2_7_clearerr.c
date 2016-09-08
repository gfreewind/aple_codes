#include <stdlib.h>
#include <stdio.h>


int main(void)
{
    FILE *fp = fopen("./tmp.txt", "r");
    if (!fp) {
        printf("Fail to fopen\n");
        return -1;
    }

    while (1) {
        int c = getc(fp);

        if (feof(fp)) {
            printf("reach feof\n");
        }
    }

    return 0;

}

