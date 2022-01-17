#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t lock;

void *print_name (void *info)
{
	static int i;

	pthread_mutex_lock(&lock);
	printf("my id is %u\n", (unsigned int)pthread_self());
	while(i < 500000)
	{
		printf("%d\n", i++);
	}
	printf("%d\n", i);
	pthread_mutex_unlock(&lock);
	pthread_exit(NULL);
	/* return NULL; */
}

int main()
{
	pthread_t id;

	pthread_mutex_init(&lock, NULL);
	pthread_create(&id, NULL, print_name, NULL);
	/* sleep(1); */
	pthread_create(&id, NULL, print_name, NULL);
	pthread_exit(NULL);
	pthread_mutex_destroy(&lock);
}
