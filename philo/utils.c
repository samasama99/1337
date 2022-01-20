/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:20:29 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/20 12:36:52 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	write_err_exit(const char *err, size_t len_err)
{
	write (STDERR, err, len_err);
	return (1);
}

unsigned long	calc_time_now(void)
{
	t_timeval	now;

	gettimeofday(&now, NULL);
	return (now.tv_sec * 1000 + now.tv_usec / 1000);
}

unsigned long	calc_time(t_timeval s_start)
{
	unsigned long	start;
	unsigned long	now;

	start = s_start.tv_sec * 1000 + s_start.tv_usec / 1000;
	now = calc_time_now();
	return (now - start);
}

void	protected_printf(size_t id, char *action, t_info *info)
{
	pthread_mutex_lock(&info->logs);
	printf ("%lu %zu %s\n", calc_time(info->s_start), id, action);
	pthread_mutex_unlock(&info->logs);
}
