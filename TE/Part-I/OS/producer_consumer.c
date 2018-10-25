#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

#define BUF_SIZE 10
#define NITEM 5

typedef struct {
	int buf[BUF_SIZE];
	int in;
	int out;
	sem_t full;
	sem_t empty;
	pthread_mutex_t mutex;
} sem_buf;

sem_buf shared;

void* Producer(void* argp)
{
	int i, item;

	for (i=0;i<NITEM;i++) {
		item = i;

		sem_wait(&shared.empty);
		pthread_mutex_lock(&shared.mutex);

		shared.buf[shared.in] = item;
		shared.in = (shared.in + 1) % BUF_SIZE;
		printf("\nP%d", item);
		fflush(stdout);

		pthread_mutex_unlock(&shared.mutex);
		sem_post(&shared.full);

		if (i % 1 == 0)
			sleep(1);
	}

	return NULL;
}

void* Consumer(void* argc)
{
	int i, item;

	for (i=NITEM;i>0;i--) {
		sem_wait(&shared.full);
		pthread_mutex_lock(&shared.mutex);

		item = i;
		item = shared.buf[shared.out];
		shared.out = (shared.out + 1) % BUF_SIZE;
		printf("\nC%d", item);
		fflush(stdout);

		pthread_mutex_unlock(&shared.mutex);
		sem_post(&shared.empty);

		if (i % 1 == 0)
			sleep(1);
	}

	return NULL;

}

int main()
{
	pthread_t P_id, C_id;
	int index = 0;

	sem_init(&shared.full, 0, 0);
	sem_init(&shared.empty, 0, BUF_SIZE);
	pthread_mutex_init(&shared.mutex, NULL);

	pthread_create(&P_id, NULL, Producer, (void*)index);
	pthread_create(&C_id, NULL, Consumer, (void*)index);

	pthread_exit(NULL);
}
