/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:27:48 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/20 12:36:53 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	check_input_error(char **args, size_t n_args)
{
	size_t	i;
	size_t	j;

	i = 1;
	j = 0;
	while (i < n_args)
	{
		while (args[i][j])
		{
			if (!ft_isdigit(args[i][j]))
				return (write_err_exit("All Params Should Be Numbers .",
						ft_strlen("All Params Should Be Numbers .")));
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	init_info_struct(t_info *info, int number_of_args, char **args)
{
	int		i;

	i = 0;
	info->number_of_philos = ft_atoi(args[1]);
	if (info->number_of_philos > 200)
		return (write_err_exit("Number Of Philos should be less than 200 .",
				ft_strlen("Number Of Philos should be less than 200 .")));
	info->finished_eating = ft_atoi(args[1]);
	info->time_to_die = ft_atoi(args[2]);
	info->time_to_eat = ft_atoi(args[3]);
	info->time_to_sleep = ft_atoi(args[4]);
	if (number_of_args == 6)
		info->each_philo_must_eat = ft_atoi(args[5]);
	else
		info->each_philo_must_eat = -1;
	return (0);
}

void	init_philos(t_philo *philo, t_info *info)
{
	size_t	i;

	i = 0;
	while (i < info->number_of_philos)
	{
		philo[i].id = i + 1;
		philo[i].must_eat = info->each_philo_must_eat;
		philo[i].info = info;
		i++;
	}
}
