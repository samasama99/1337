#include "main.h"


unsigned	check_if_dead(unsigned now, unsigned last_meal, size_t time_to_die)
{
	if (now - last_meal > time_to_die)
		return (1);
	return (0);
}

unsigned calc_time_now()
{
	timeval now;
	unsigned long time_now;

	gettimeofday(&now, NULL);
	time_now = now.tv_sec * 1000000 + now.tv_usec;
	return (time_now);
}

int	is_alive(unsigned last_meal, unsigned now, unsigned time_to_die)
{
	
	if ((now - last_meal) > time_to_die)
		return (0);
	return (1);
}

void	do_sleep(unsigned timestamp, size_t id, t_info *info)
{
	printf ("%u %zu is sleeping\n", timestamp, id + 1);
	usleep(info->time_to_sleep);
}

unsigned calc_time(timeval s_now, timeval s_start)
{
	unsigned long	start; 
	unsigned long	now;

	start = s_start.tv_sec * 1000000 + (unsigned long)s_start.tv_usec;
	now = s_now.tv_sec * 1000000 + (unsigned long)s_now.tv_usec;
	return (now - start) / 1000;
}

void *start_sim(void *params)
{
	t_philo			*philo;
	t_info			*info;
	struct			timeval start;
	struct			timeval now;
	struct			timeval last_meal;
	static size_t	id = -1;

	id++;
	info = (t_info *)params;
	philo = &info->philos[id];
	philo->id = id;
	gettimeofday(&start, NULL);
	philo->last_meal = calc_time_now();
	while (info->philo_dies)
	{
		lock_forks(&info->forks[(philo->id)],
				&info->forks[(philo->id + 1) % (info->number_of_philos)]);
		philo->last_meal = calc_time_now();
		printf ("%u %zu has taken a fork\n",
					calc_time(now, start),
				philo->id + 1);
		gettimeofday(&now, NULL);
		gettimeofday(&last_meal, NULL);
		printf ("%u %zu is eating\n", 
					calc_time(now, start),
				philo->id + 1);
		usleep (info->time_to_eat);
		unlock_forks(&info->forks[(philo->id)],
				&info->forks[(philo->id + 1) % (info->number_of_philos)]);
		gettimeofday(&now, NULL);
		do_sleep(calc_time(now, start), philo->id, info);
		gettimeofday(&now, NULL);
		printf ("%u %zu is thinking\n",
					calc_time(now, start),
				philo->id + 1);
		/* if (!is_alive(last_meal.tv_usec, now.tv_usec, (int)info->time_to_die)) */
		/* { */
		/* 	logs("died", calc_time(now, start), philo->id, info); */
		/* 	pthread_exit(NULL); */
		/* } */
	}
	return (NULL);
}

void	create_philos(t_info *info)
{
	size_t		i;
	pthread_t	id[200];

	i = 0;
	while (i < info->number_of_philos)
	{
		if (pthread_create (&id[i], NULL, start_sim, info))
			write_err_exit ("Error\n", 6);
		usleep(50);
		i++;
	}
	i = 0;
	while (1337)
	{
		if (check_if_dead(calc_time_now(), info->philos[i].last_meal, info->time_to_die))
			break ;
		i = (i + 1) % info->number_of_philos;	
	}
	exit(1);
}
