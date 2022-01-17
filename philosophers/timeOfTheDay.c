#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	struct	timeval start_time;
	struct	timeval finish_time;
	int		i;

	i = 0;

	gettimeofday(&start_time, NULL);
	sleep (1);
	usleep (500000);
	gettimeofday(&finish_time, NULL);
	printf("time :: %ld,%06d\n", finish_time.tv_sec - start_time.tv_sec,
								finish_time.tv_usec - start_time.tv_usec);
}
