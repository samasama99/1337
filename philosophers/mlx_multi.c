#include <mlx.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
// 5120 x 2880
//
typedef struct s_info
{
	void *init;
	void *window;
}				t_info;

void *draw_th1(void *param)
{
	int x = 0;
	int y = 0;
	t_info *info = (t_info *)param;

	while (y < 1000)
	{
		while (x < 500)
		{
			mlx_pixel_put (info->init, info->window, x, y, 0x00FF0000);
			printf ("th 1 :: x = %d , y = %d\n", x, y);
			x++;
		}
		x = 0;
		y++;
	}
	pthread_exit(NULL);
}

void *draw_th2(void *param)
{
	int x = 500;
	int y = 0;
	t_info *info = (t_info *)param;

	while (y < 1000)
	{
		while (x < 1000)
		{
			mlx_pixel_put (info->init, info->window, x, y, 0x000000FF);
			printf ("th 2 :: x = %d , y = %d\n", x, y);
			x++;
		}
		x = 500;
		y++;
	}
	pthread_exit(NULL);
}

int main()
{
	struct	timeval start_time;
	struct	timeval finish_time;
	t_info info;
	pthread_t id1;
	pthread_t id2;

	info.init = mlx_init();
	if (info.init == NULL)
		return (1);
	info.window = mlx_new_window (info.init, 1100, 1100, "multi_threading");
	if (info.window == NULL)
		return (2);

	gettimeofday(&start_time, NULL);
	if (pthread_create (&id1, NULL, draw_th1, (void *)&info))
		return (3);
	if (pthread_create (&id2, NULL, draw_th2, (void *)&info))
		return (4);
	pthread_join(id1, NULL);
	pthread_join(id2, NULL);
	gettimeofday(&finish_time, NULL);
	printf("time :: %ld ses %d microsec\n", finish_time.tv_sec - start_time.tv_sec,
								finish_time.tv_usec - start_time.tv_usec);
	/* mlx_destroy_window (info.init, info.window); */
	/* free (info.init); */
	mlx_loop(info.init);
}
