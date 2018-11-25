#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define BUFFER_SIZE 1024

char shared[BUFFER_SIZE];
pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond;
int string_read=FALSE;

void* reader(void* arg)
{
	while(1)
	{
		while(string_read);
		pthread_mutex_lock(&lock);
		scanf("%s", shared);
		string_read=TRUE;
		pthread_mutex_unlock(&lock);
		pthread_cond_signal(&cond);
	}
}

void* writer(void* arg)
{
	while(1)
	{
		pthread_mutex_lock(&lock);
		while(!string_read)pthread_cond_wait(&cond, &lock);
		printf("Writer: %s\n", shared);
		string_read=FALSE;
		pthread_mutex_unlock(&lock);
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