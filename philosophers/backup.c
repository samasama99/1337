#include "main.h"
#include "libft/libft.h"
#include <sys/time.h>


// todo : args 
//	number_of_philosophers 
//	time_to_die
//	time_to_eat 
//	time_to_sleep 
//	[number_of_times_each_philosopher_must_eat]
void	write_err_exit(const char *err, size_t len_err)
{
	write (STDERR, err, len_err);
	exit(1);
}

void init_philo_struct(t_info *info, int number_of_args, char **args)
{
	info->number_of_philos = ft_atoi(args[1]);
	info->time_to_die = ft_atoi(args[2]) * 1000;
	info->time_to_eat = ft_atoi(args[3]) * 1000;
	info->time_to_sleep = ft_atoi(args[4]) * 1000;
	info->philo_dies = 1;
	if (number_of_args == 6)
		info->each_philo_must_eat = ft_atoi(args[5]);
}

void *start_sim(void *params)
{
	t_philo			*philo;
	t_info			*info;
	struct			timeval start_time;
	struct			timeval finish_time;
	struct			timeval last_meal;
	static size_t	id = -1;

	id++;
	info = (t_info *)params;
	philo = &info->philos[id];
	philo->id = id;
	gettimeofday(&start_time, NULL);
	while (1)
	{
		pthread_mutex_lock (&info->forks[(philo->id) % (info->number_of_philos)]);
		pthread_mutex_lock (&info->forks[(philo->id + 1) % (info->number_of_philos)]);
		gettimeofday(&finish_time, NULL);
		printf ("%d %zu has taken a fork\n",
				(finish_time.tv_usec - start_time.tv_usec) / 1000,
				philo->id + 1);
		gettimeofday(&finish_time, NULL);
		gettimeofday(&last_meal, NULL);
		printf ("%d %zu is eating\n", 
				(finish_time.tv_usec - start_time.tv_usec) / 1000,
				philo->id + 1);
		usleep (info->time_to_eat);
		pthread_mutex_unlock (&info->forks[(philo->id) % (info->number_of_philos)]);
		pthread_mutex_unlock (&info->forks[(philo->id + 1) % (info->number_of_philos)]);
		gettimeofday(&finish_time, NULL);
		printf ("%d %zu is sleeping\n", 
				(finish_time.tv_usec - start_time.tv_usec) / 1000,
				philo->id + 1);
		usleep (info->time_to_sleep);
		gettimeofday(&finish_time, NULL);
		printf ("%d %zu is thinking\n",
				(finish_time.tv_usec - start_time.tv_usec) / 1000,
				philo->id + 1);
		if ((finish_time.tv_usec - last_meal.tv_usec) > (int)info->time_to_die)
		{
			printf ("%d %zu died\n",
					(finish_time.tv_usec - start_time.tv_usec) / 1000,
					philo->id + 1);
			info->number_of_philos--;
		}
	}
	return (NULL);
}

void	create_philos(t_info *info)
{
	size_t		i;
	pthread_t	id;

	i = 0;
	while (i < info->number_of_philos)
	{
		if (pthread_create (&id, NULL, start_sim, info))
			write_err_exit ("Error\n", 6);
		usleep(50);
		i++;
	}
	while (info->philo_dies);
}

int main(int n, char **args)
{
	t_info info;
	size_t		i;

	i = -1;
	if (n < 5 || n > 6)
		write_err_exit ("Error\n", 6);
	init_philo_struct (&info, n, args);
	while (++i < info.number_of_philos)
		pthread_mutex_init(info.forks + i, NULL);
	create_philos(&info);	
	pthread_mutex_destroy(info.forks);
}
