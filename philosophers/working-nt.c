#include "main.h"

unsigned long	calc_time_now()
{
	timeval now;

	gettimeofday(&now, NULL);
	return (now.tv_sec * 1000000 + now.tv_usec);
}

unsigned	check_if_dead(unsigned long last_meal, size_t time_to_die)
{
	unsigned long	now;

	now = calc_time_now();
	printf ("%lu %lu  %lu %lu\n", (now / 1000) , (last_meal / 1000), (now / 1000) - (last_meal / 1000), time_to_die / 1000);
	if (now / 1000 - last_meal / 1000 > time_to_die / 1000)
		return (1);
	return (0);
}


int	is_alive(unsigned long last_meal, unsigned long time_to_die)
{
	unsigned long	now;

	now = calc_time_now();
	if ((now - last_meal) > time_to_die)
		return (1);
	return (0);
}

void	do_sleep(unsigned long timestamp, size_t id, t_info *info)
{
	printf ("%lu %zu is sleeping\n", timestamp, id + 1);
	usleep(info->time_to_sleep);
}

unsigned long	calc_time(timeval s_start)
{
	unsigned long	start; 
	unsigned long	now;

	start = s_start.tv_sec * 1000000 + (unsigned long)s_start.tv_usec;
	now = calc_time_now();
	return (now - start) / 1000;
}

void *start_sim(void *param)
{
	static size_t	id;
	t_info			*info;
	t_philo			*philo;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	
	info = (t_info *)param;
	philo = &info->philos[id];
	philo->last_meal = calc_time_now();
	id++;
	philo->id = id;
	while (1337)
	{
		lock_forks (&info->forks[philo->id - 1], &info->forks[philo->id % info->number_of_philos]);
		time_to_eat = calc_time(info->s_start);
		printf ("%lu %zu has taken a fork\n", time_to_eat, philo->id);
		printf ("%lu %zu is eating\n", time_to_eat, philo->id);
		philo->last_meal = calc_time_now();
		usleep(info->time_to_eat);
		unlock_forks (&info->forks[philo->id - 1], &info->forks[philo->id % info->number_of_philos]);
		time_to_sleep = calc_time(info->s_start);
		printf ("%lu %zu is sleeping\n", time_to_sleep, philo->id);
		usleep(info->time_to_sleep);
		printf ("%lu %zu is thinking\n", time_to_sleep + info->time_to_sleep / 1000, philo->id);
	}
	return param;
}

void	create_philos(t_info *info)
{
	size_t		i;
	pthread_t	id[200];

	i = 0;
	gettimeofday(&info->s_start, NULL);
	while (i < info->number_of_philos)
	{
		if (pthread_create (&id[i], NULL, start_sim, info))
			write_err_exit ("Error\n", 6);
		usleep(20);
		i++;
	}
	i = 0;
	while (1337)
	{
		if (check_if_dead(info->philos[i].last_meal, info->time_to_die))
		{
			printf ("%lu %zu died\n", calc_time(info->s_start), i + 1);
			exit(0);
		}
		i = (i + 1) % info->number_of_philos;	
	}
}
