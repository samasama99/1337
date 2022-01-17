#include "main.h"

void lock_forks(pthread_mutex_t *fork1, pthread_mutex_t *fork2)
{
		pthread_mutex_lock (fork1);
		pthread_mutex_lock (fork2);
}

void unlock_forks(pthread_mutex_t *fork1, pthread_mutex_t *fork2)
{
		pthread_mutex_unlock (fork1);
		pthread_mutex_unlock (fork2);
}
