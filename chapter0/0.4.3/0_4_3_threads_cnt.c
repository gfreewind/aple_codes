#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


static int counter = 0;
#define LOOPS	10000000

static void * thread(void *unused)
{
	int i;
	
	for (i = 0; i < LOOPS; ++i) {
		++counter;
	}

	return NULL;
}

int main(void)
{
	pthread_t t1, t2;

	pthread_create(&t1, NULL, thread, NULL);
	pthread_create(&t2, NULL, thread, NULL);


	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	printf("Counter is %d by threads\n", counter);

	return 0;
}
