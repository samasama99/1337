/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:33:39 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/20 12:36:54 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static unsigned	int	check_if_dead(unsigned long now, unsigned long last_meal
				, size_t time_to_die)
{
	return (now - last_meal > (time_to_die + DELAY));
}

static void	*start_sim(void *param)
{
	t_info			*info;
	t_philo			*philo;

	philo = (t_philo *)param;
	info = philo->info;
	philo->last_meal = calc_time_now();
	while (1337 && philo->must_eat)
	{
		if (philo->must_eat == 0)
			pthread_exit(NULL);
		philo_is_eating(philo);
		philo_is_sleeping(philo);
		usleep(info->time_to_sleep * 1000);
		philo_is_thinking(philo);
		if (philo->must_eat != -1)
			philo->must_eat--;
	}
	info->finished_eating--;
	pthread_exit(NULL);
}

static void	main_checker(t_philo *philo, t_info *info)
{
	size_t	i;

	i = 0;
	while (1337)
	{
		if (check_if_dead (calc_time_now(), philo[i].last_meal
				, info->time_to_die) && philo[i].must_eat)
		{
			pthread_mutex_lock(&info->logs);
			printf ("%lu %zu died\n", calc_time(info->s_start), i + 1);
			return ;
		}
		if (info->finished_eating == 0)
			return ;
		i = (i + 1) % info->number_of_philos;
	}
}

void	create_philos(t_philo *philo)
{
	size_t		i;
	t_info		*info;
	pthread_t	id[200];

	i = 0;
	info = philo->info;
	gettimeofday(&info->s_start, NULL);
	while (i < info->number_of_philos)
	{
		if (pthread_create (&id[i], NULL, start_sim, philo + i))
			write_err_exit ("Error\n", 6);
		usleep(100);
		i++;
	}
	i = 0;
	main_checker (philo, info);
}
