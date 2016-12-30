#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <sys/syscall.h>
#include <string.h>
#include <errno.h>


void usage(char *program)
{
    printf("Usage: %s [OPTIONS] \n", program);
    printf("    -p target_pid \n");
    printf("    -s signal number (0~64) \n");
}

int tkill(int tid, int signo)
{
    int ret = syscall(SYS_tkill, tid, signo); 
    if(ret)
    {
        fprintf(stderr,"PID(%d) ------sig(%d)----->PID(%d)  failed (%s)\n",getpid(), signo, tid, strerror(errno));
    }
    return ret;
}

int main(int argc,  char* argv[])
{
    int c ;

    static struct option long_options[] = {
        {"target_pid",  required_argument, 0, 'p'},
        {"signal",  required_argument, 0, 's'},
        {0, 0 , 0, 0}
    };

    const char* short_options = "h?p:s:";

    int option_index = 0;

    int target_pid = -1 ;
    int signal_id = -1;
    int ret = -1; 

    while((c = getopt_long(argc, argv, short_options, long_options, &option_index)) != -1)
    {
        switch(c)
        {
        case 'p':
            target_pid = atoi(optarg);
            break;
        case 's':
            signal_id = atoi(optarg); 
            break;
        case 'h':
        case '?':
            usage(argv[0]);
            return 0;
            break;
        default:
            break;
        }

    }

    if(optind < argc)
    {
        fprintf(stderr,"Non-Option ARGV parameter: ");
        while((optind < argc))
        {
            fprintf(stderr, "%s ", argv[optind++]);
        }
        fprintf(stderr,"\n");
        usage(argv[0]);
        return 1;
    }


    if(target_pid <= 0)
    {
        fprintf(stderr, "invalid target pid %d\n", target_pid);
        return 2;
    }

    if(signal_id < 0 || signal_id > 64)
    {
        fprintf(stderr, "invalid signal number %d\n", signal_id);
        return 3;
    }

    ret = tkill(target_pid, signal_id);
    return ret;

}
