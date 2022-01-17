/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:33:39 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/17 18:43:13 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// 
unsigned long	calc_time_now()
{
	timeval now;

	gettimeofday(&now, NULL);
	return (now.tv_sec * 1000 + now.tv_usec / 1000);
}
// 68504

unsigned	check_if_dead(unsigned long now, unsigned long last_meal, size_t time_to_die)
{
	/* unsigned long	now; */

	/* now = calc_time_now(); */
	/* if (now < last_meal) */
	/* 	return 0; */
	/* if (now - last_meal > time_to_die) */
	/* { */
		/* printf ("%lu %lu  %lu %lu\n", (now) , (last_meal), (now) - (last_meal), time_to_die); */
		/* return (1); */
	/* } */
	/* return (0); */
	return (now - last_meal > time_to_die);
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

void	philo_is_sleeping(t_info *info, unsigned long at, size_t id)
{
	pthread_mutex_lock(&info->death);
	printf ("%lu %zu is sleeping\n", at, id);
	pthread_mutex_unlock(&info->death);
	usleep (info->time_to_sleep);
}

void	philo_is_eating(t_info *info, unsigned long at, size_t id)
{
	/* pthread_mutex_lock (&info->forks[id - 1]); */
	pthread_mutex_lock(&info->death);
	printf ("%lu %zu has taken a fork\n", at, id);
	pthread_mutex_unlock(&info->death);
	/* pthread_mutex_lock (&info->forks[id % info->number_of_philos]); */
	pthread_mutex_lock(&info->death);
	printf ("%lu %zu has taken a fork\n", at, id);
	pthread_mutex_unlock(&info->death);
	pthread_mutex_lock(&info->death);
	printf ("%lu %zu is eating\n", at, id);
	pthread_mutex_unlock(&info->death);
	usleep (info->time_to_eat * 1000);
}

void	philo_is_thinking(t_info *info, unsigned long at, size_t id)
{
	pthread_mutex_lock(&info->death);
	printf ("%lu %zu is thinking\n", at, id);
	pthread_mutex_unlock(&info->death);
}

void *start_sim(void *param)
{
	static size_t	id;
	t_info			*info;
	t_philo			*philo;
	/* unsigned long	time_to_eat; */
	unsigned long	time_to_sleep;
	
	info = (t_info *)param;
	philo = &info->philos[id];
	id++;
	philo->id = id;
	philo->last_meal = calc_time_now();
	while (1337 && philo->must_eat)
	{
		if (philo->must_eat == 0)
			pthread_exit(NULL);
		lock_forks (&info->forks[philo->id - 1], &info->forks[philo->id % info->number_of_philos]);
		/* time_to_eat = calc_time(info->s_start); */
		philo->last_meal = calc_time_now();
		philo_is_eating(info, calc_time(info->s_start), philo->id);
		unlock_forks (&info->forks[philo->id - 1], &info->forks[philo->id % info->number_of_philos]);
		time_to_sleep = calc_time(info->s_start);
		philo_is_sleeping(info, time_to_sleep, philo->id);
		usleep(info->time_to_sleep * 1000);
		philo_is_thinking(info, time_to_sleep + info->time_to_sleep, philo->id);
		if (philo->must_eat != -1)
			philo->must_eat--;
	}
	info->finished_eating--;
	pthread_exit(NULL);
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
		usleep(100);
		i++;
	}
	i = 0;
	while (1337)
	{
		if (check_if_dead(calc_time_now(), info->philos[i].last_meal, info->time_to_die) && info->philos[i].must_eat)
		{
			pthread_mutex_lock(&info->death);
			printf ("%lu %zu died\n", calc_time(info->s_start), i + 1);
			return ;
		}
		if (info->finished_eating == 0)
			return ;
		/* usleep (1000); */
		i = (i + 1) % info->number_of_philos;	
	}
	// mutex_lock(gl);
}
