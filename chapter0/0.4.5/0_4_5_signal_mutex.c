#include <stdlib.h>
#include <stdio.h>

#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

static const char * const caller[2] = {"mutex_thread", "signal handler"};
static pthread_t mutex_tid;
static pthread_t sleep_tid;
static volatile int signal_handler_exit = 0;

static void hold_mutex(int c)
{
    printf("enter hold_mutex [caller %s]\n", caller[c]);

    pthread_mutex_lock(&mutex);

    /* 这里的循环为了保证在信号处理函数退出前锁不会被释放 */
    while (!signal_handler_exit && c != 1) {
        sleep(5);
    }

    pthread_mutex_unlock(&mutex);

    printf("leave hold_mutex [caller %s]\n", caller[c]); 
}

static void *mutex_thread(void *arg)
{
    hold_mutex(0);
    return NULL;
}

static void *sleep_thread(void *arg)
{
    sleep(10);
    return NULL;
}

static void signal_handler(int signum)
{
    hold_mutex(1);
    signal_handler_exit = 1;
}

int main()
{
    signal(SIGUSR1, signal_handler);

    pthread_create(&mutex_tid, NULL, mutex_thread, NULL);
    pthread_create(&sleep_tid, NULL, sleep_thread, NULL);

    pthread_kill(sleep_tid, SIGUSR1);
    pthread_join(mutex_tid, NULL);
    pthread_join(sleep_tid, NULL);

    return 0;
} 




