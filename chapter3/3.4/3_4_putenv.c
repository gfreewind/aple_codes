#include <stdlib.h>
#include <stdio.h>

static void set_env_string(void)
{
    char test_env[] = "test_env=test";

    if (0 != putenv(test_env)) {
        printf("fail to putenv\n");
    }

    printf("1. The test_evn string is %s\n", getenv("test_env"));
}

static void show_env_string(void)
{
    printf("2. The test_env string is %s\n", getenv("test_env"));
}

int main()
{
    set_env_string();
    show_env_string();

return 0;
}

