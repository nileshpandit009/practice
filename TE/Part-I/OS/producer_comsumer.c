#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

#define BUF_SIZE 5
#define PCITEMS  4

typedef struct {
	int buf[BUF_SIZE];
	int in;
	int out;
	sem_t full;
	sem_t empty;
	pthread_mutex_t mutex;
} sem_buf_t;

sem_buf_t shared;

void* Producer(void* argp)
{
	int item, index;
}

int main()
{
}
