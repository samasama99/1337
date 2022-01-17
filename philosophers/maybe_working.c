#include "main.h"

unsigned long	calc_time_now()
{
	timeval now;

	gettimeofday(&now, NULL);
	return (now.tv_sec * 1000 + now.tv_usec / 1000);
	/* return (now.tv_sec * 1000); */
}

unsigned	check_if_dead(unsigned long last_meal, size_t time_to_die)
{
	unsigned long	now;

	now = calc_time_now();
	/* printf ("%lu %lu  %lu %lu\n", (now) , (last_meal), (now) - (last_meal), time_to_die); */
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

	start = s_start.tv_sec * 1000 + s_start.tv_usec / 1000;
	/* start = s_start.tv_sec * 1000; */
	now = calc_time_now();
	return (now - start);
}

void	philo_is_sleeping(t_info info, size_t time_to_do, unsigned long at, size_t id)
{
	pthread_mutex_lock(&info.death);
	printf ("%lu %zu is sleeping\n", at, id);
	usleep (time_to_do);
	pthread_mutex_lock(&info.death);
}

void	philo_is_eating(t_info *info, unsigned long at, size_t id)
{
	pthread_mutex_lock(&info->death);
	printf ("%lu %zu has taken a fork\n", at, id);
	printf ("%lu %zu is eating\n", at, id);
	pthread_mutex_unlock(&info->death);
	usleep (info->time_to_eat * 1000);
}

void	philo_is_thinking(t_info info, unsigned long at, size_t id)
{
	pthread_mutex_lock(&info.death);
	printf ("%lu %zu is thinking\n", at, id);
	pthread_mutex_lock(&info.death);
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
		philo->last_meal = calc_time_now();
		time_to_eat = calc_time(info->s_start);
		philo_is_eating(info, time_to_eat, philo->id);
		/* pthread_mutex_lock(&info->death); */
		/* printf ("%lu %zu has taken a fork\n", time_to_eat, philo->id); */
		/* printf ("%lu %zu is eating\n", time_to_eat, philo->id); */
		/* pthread_mutex_unlock(&info->death); */
		/* usleep(info->time_to_eat * 1000); */
		unlock_forks (&info->forks[philo->id - 1], &info->forks[philo->id % info->number_of_philos]);
		time_to_sleep = calc_time(info->s_start);
		pthread_mutex_lock(&info->death);
		printf ("%lu %zu is sleeping\n", time_to_sleep, philo->id);
		pthread_mutex_unlock(&info->death);
		usleep(info->time_to_sleep * 1000);
		pthread_mutex_lock(&info->death);
		printf ("%lu %zu is thinking\n", time_to_sleep + info->time_to_sleep , philo->id);
		pthread_mutex_unlock(&info->death);
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
		pthread_mutex_lock(&info->death);
		if (check_if_dead(info->philos[i].last_meal, info->time_to_die))
		{
			printf ("%lu %zu died\n", calc_time(info->s_start), i + 1);
			exit(0);
		}
		pthread_mutex_unlock(&info->death);
		i = (i + 1) % info->number_of_philos;	
	}
}
