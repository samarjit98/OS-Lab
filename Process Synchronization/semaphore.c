#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

char shared[1024];
sem_t sema;

void* reader(void* arg)
{
	while(1)
	{
		//printf("Enter String: ");
		scanf("%s", shared);
		sem_post(&sema);
	}
}

void* writer(void* arg)
{
	while(1)
	{
		sem_wait(&sema);
		printf("Writer: %s\n", shared);
	}
}

int main(int argc, char* argv[])
{
	pthread_t tid1, tid2;
	pthread_create(&tid1, NULL, reader, NULL);
	pthread_create(&tid2, NULL, writer, NULL);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	return 0;
}