#include "main.h"

unsigned long	calc_time_now()
{
	timeval now;
	unsigned long time_now;

	gettimeofday(&now, NULL);
	time_now = now.tv_sec * 1000000 + now.tv_usec;
	return (time_now);
}

unsigned	check_if_dead(unsigned long last_meal, size_t time_to_die)
{
	unsigned long	now;

	now = calc_time_now();
	/* printf ("%lu - %lu = %lu > %zu\n", now, last_meal, now - last_meal, time_to_die); */
	if (now - last_meal > time_to_die)
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

	/* printf ("sec - usec == %lu %d\n", s_start.tv_sec, s_start.tv_usec); */
	start = s_start.tv_sec * 1000000 + (unsigned long)s_start.tv_usec;
	now = calc_time_now();
	/* printf ("now - start == %lu %lu\n", now , start); */
	return (now - start) / 1000;
}

void *start_sim(void *param)
{
	static size_t	id;
	t_info			*info;
	t_philo			*philo;
	
	info = (t_info *)param;
	philo = &info->philos[id];
	philo->last_meal = calc_time_now();
	id++;
	philo->id = id;
	/* printf ("hello from philo number %zu\n", philo->id); */
	/* printf ("time of creation %u\n", philo->last_meal); */
	while (1337)
	{
		lock_forks (&info->forks[philo->id - 1], &info->forks[philo->id % info->number_of_philos]);
		printf ("%lu %zu has taken a fork\n", calc_time(info->s_start), philo->id);
		printf ("%lu %zu is eating\n", calc_time(info->s_start), philo->id);
		philo->last_meal = calc_time_now();
		usleep(info->time_to_eat);
		unlock_forks (&info->forks[philo->id - 1], &info->forks[philo->id % info->number_of_philos]);
		printf ("%lu %zu is sleeping\n", calc_time(info->s_start), philo->id);
		usleep(info->time_to_sleep);
		printf ("%lu %zu is thinking\n", calc_time(info->s_start), philo->id);
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
