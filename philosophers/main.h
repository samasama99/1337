/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:20:43 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/20 12:36:54 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <sys/time.h>
# define STDERR 2
# define DELAY 7

typedef struct timeval	t_timeval;

typedef struct s_info
{
	pthread_mutex_t		forks[200];
	pthread_mutex_t		logs;
	t_timeval			s_start;
	size_t				number_of_philos;
	size_t				finished_eating;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	int					each_philo_must_eat;
}				t_info;

typedef struct s_philo
{
	size_t			id;
	int				must_eat;
	unsigned long	last_meal;
	t_info			*info;
}				t_philo;

/////// SIMULATION //////////////////////
///////////////////////////////////
void			philo_is_sleeping(t_philo *philo);
void			philo_is_eating(t_philo *philo);
void			philo_is_thinking(t_philo *philo);
unsigned long	calc_time(t_timeval start);
void			create_philos(t_philo *philo);
/////// PARSE //////////////////////
///////////////////////////////////
int				init_info_struct(t_info *info, int number_of_args, char **args);
void			init_philos(t_philo	*philo, t_info *info);
int				check_input_error(char **args, size_t n_args);
/////// UTILS //////////////////////
///////////////////////////////////
int				write_err_exit(const char *err, size_t len_err);
unsigned long	calc_time_now(void);
unsigned long	calc_time(t_timeval s_start);
/////// MUTEX //////////////////////
///////////////////////////////////
void			protected_printf(size_t id, char *action, t_info *info);
#endif
