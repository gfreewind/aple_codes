#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void usage()
{
  fprintf(stdout, "Usage: t_sys command\n");
  fprintf(stdout, "Example: t_sys \"ls -al\"\n");
  fprintf(stdout, "NOTICE: NEVER call dangerous command \n");
}

void print_wait_exit(int status)
{
  printf("status = %d\n",status);
  if(WIFEXITED(status))
  {
    printf("normal termination,exit status = %d\n", WEXITSTATUS(status));
  }
  else if(WIFSIGNALED(status))
  {
    printf("abnormal termination,signal number = %d%s\n", WTERMSIG(status),
#ifdef WCOREDUMP
	WCOREDUMP(status)?"core file generated": "");
#else
    "");
#endif
  }
}


int main(int argc ,char* argv[])
{
  if(argc != 2)
  {
    usage();
    exit(1);
  }

  /*NOTICE, this is very dangerous to try harmful command*/
  int status = system(argv[1]);
  if(status == -1)
  {
    fprintf(stderr, "system() function return -1 (%s)\n", strerror(errno));
  }
  else if(WIFEXITED(status) && WEXITSTATUS(status) == 127)
  {
    fprintf(stderr, "cannot invoke shell to exec command(%s)\n",argv[1]);
  }
  else
    print_wait_exit(status);

  return 0;
}
