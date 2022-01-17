#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void *thread(void *param)
{
	static size_t	id;

	id++;
	pthread_mutex_lock ((pthread_mutex_t *)param);
	pthread_mutex_lock ((pthread_mutex_t *)param + 1);
	printf ("hello from thread %zu\n", id);
	sleep (2);
	pthread_mutex_unlock ((pthread_mutex_t *)param);
	
	pthread_exit(NULL);
}

int main()
{
	int i = 0;
	pthread_t id;
	pthread_mutex_t info[2];

	pthread_mutex_init(info, NULL);
	pthread_mutex_init(info + 1, NULL);
	while (i < 2)
	{
		if (pthread_create (&id, NULL, thread, info))
			exit(1);
		usleep(50);
		i++;
	}
	pthread_mutex_destroy(info);
	pthread_mutex_destroy(info + 1);
	pthread_exit(NULL);
}
