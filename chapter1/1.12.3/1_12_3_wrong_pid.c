#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int fd = open("test.pid", O_WRONLY|O_CREAT, 0600);

    write(fd, "6789", sizeof("6789")-1);

    close(fd);

    return 0;
}

