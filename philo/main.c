/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:10:56 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/20 12:36:49 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int n, char **args)
{
	t_info		info;
	t_philo		philo[200];
	size_t		i;

	i = -1;
	if (n < 5 || n > 6)
		return (write_err_exit ("Error\n", 6));
	if (check_input_error(args, n))
		return (1);
	if (init_info_struct(&info, n, args))
		return (1);
	init_philos(philo, &info);
	while (++i < info.number_of_philos)
		pthread_mutex_init(info.forks + i, NULL);
	pthread_mutex_init(&info.logs, NULL);
	create_philos(philo);
	i = -1;
	while (++i < info.number_of_philos)
		pthread_mutex_destroy(info.forks + i);
	pthread_mutex_destroy(&info.logs);
	return (0);
}
