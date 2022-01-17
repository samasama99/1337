#include "main.h"
#include <time.h>
int main()
{

	struct			timeval start_time;
	struct			timeval finish_time;
	/* unsigned		time; */
	unsigned long long	start;
	unsigned long long	finish;
	gettimeofday(&start_time, NULL);
	printf ("start time :: %lu %d\n", start_time.tv_sec, start_time.tv_usec);
	start = start_time.tv_sec * 1000000 + start_time.tv_usec;
	printf ("start time (usec) :: %llu\n", start);
	printf ("start time (msec) :: %llu\n", start / 1000);
	printf ("start time (sec) :: %llu\n", start / 1000000);
	sleep (1);
	sleep (1);
	usleep (450000);
	gettimeofday(&finish_time, NULL);
	printf ("finish time :: %lu %d\n", finish_time.tv_sec, finish_time.tv_usec);
	finish = finish_time.tv_sec * 1000000 + finish_time.tv_usec;
	printf ("finish time (usec) :: %llu\n", finish);
	printf ("start time (msec) :: %llu\n", finish / 1000);
	printf ("start time (sec) :: %llu\n", finish / 1000000);

	printf ("finish - start (usec) == %llu\n", finish - start);
	printf ("finish - start (msec) == %llu\n", (finish - start) / 1000);
	printf ("finish - start (sec) == %llu\n", (finish - start) / 1000000);
	/* time = calc_time(finish_time.tv_sec - start_time.tv_sec, */
	/* 		finish_time.tv_usec - start_time.tv_usec); */
	/* printf ("%u\n", time); */
}
