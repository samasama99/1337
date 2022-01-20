/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:35:09 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/20 12:36:55 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	philo_is_sleeping(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	protected_printf(philo->id, "is sleeping", info);
	usleep (info->time_to_sleep);
}

void	philo_is_eating(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	pthread_mutex_lock (&info->forks[philo->id - 1]);
	protected_printf(philo->id, "has taken a fork", info);
	pthread_mutex_lock (&info->forks[philo->id % info->number_of_philos]);
	protected_printf(philo->id, "has taken a fork", info);
	philo->last_meal = calc_time_now();
	protected_printf(philo->id, "is eating", info);
	usleep (info->time_to_eat * 1000);
	pthread_mutex_unlock (&info->forks[philo->id - 1]);
	pthread_mutex_unlock (&info->forks[philo->id % info->number_of_philos]);
}

void	philo_is_thinking(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	protected_printf(philo->id, "is thinking", info);
}
