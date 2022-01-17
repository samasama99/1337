#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
void *sum_thread1(void *param)
{
	printf ("thread1 started\n");
	while (*(int *)param < 10000)
		*(int *)param++;
	pthread_exit(param);
}

void *sum_thread2(void *param)
{
	printf ("thread2 started\n");
	while (*(int *)param < 20000)
		*(int *)param++;
	pthread_exit(param);
}

int main ()
{

	/* struct	timeval start_time; */
	/* struct	timeval finish_time; */
	pthread_t id1;
	pthread_t id2;
	int x, y;
	x = y = 0;

	/* gettimeofday(&start_time, NULL); */
	if (pthread_create (&id1, NULL, sum_thread1, &x))
		return (1);
	if (pthread_create (&id2, NULL, sum_thread2, &y))
		return (1);
	/* usleep (500); */
	printf("%d %d\n", (int)x, (int)y);
	pthread_exit(NULL);
	/* gettimeofday(&finish_time, NULL); */
	/* printf("time :: %ld ses %d microsec\n", finish_time.tv_sec - start_time.tv_sec, */
	/* 							finish_time.tv_usec - start_time.tv_usec); */
}
