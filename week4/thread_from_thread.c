#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

void **rr;
unsigned i;

void *thread_one(void *);
void *thread_two(void *);

void *thread_two(void *arg)
{
	pthread_t tid;
	i++;
	pthread_create(&tid, NULL, thread_one, NULL);
	pthread_join(tid, rr);
}

void *thread_one(void *arg) 
{
	pthread_t tid;
	i++;
	pthread_create(&tid, NULL, thread_two, NULL);
	pthread_join(tid, rr);
}

int main(int argc, const char *argv[]) {
	pthread_t pr;
	i = 0;
	printf("test?\n");
	pthread_create(&pr, NULL, thread_one, NULL);
	pthread_join(pr, rr);
	printf("w0t?!\n");
	printf("%d\n", i);
return 0;
}

