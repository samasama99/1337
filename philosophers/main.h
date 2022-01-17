#ifndef MAIN_H
# define MAIN_H
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <sys/time.h>
#define STDERR 2

typedef struct timeval timeval;
typedef struct s_philo
{
	size_t			id;
	int				must_eat;
	unsigned long	last_meal;
}				t_philo;

typedef struct s_info
{
	t_philo				philos[200];
	pthread_mutex_t		forks[200];
	pthread_mutex_t		death;
	pthread_mutex_t		log;
	timeval				s_start;
	size_t				number_of_philos;
	size_t				finished_eating;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	int					each_philo_must_eat;
	size_t				philo_dies;
}				t_info;

/////// SIMULATION //////////////////////
///////////////////////////////////
int				is_alive(unsigned long last_meal, unsigned long time_to_die);
void			do_sleep(unsigned long timestamp, size_t id, t_info *info);
unsigned long	calc_time(timeval start);
void			*start_sim(void *params);
void			create_philos(t_info *info);

/////// PARSE //////////////////////
///////////////////////////////////
void	init_philo_struct(t_info *info, int number_of_args, char **args);

/////// UTILS //////////////////////
///////////////////////////////////
void	write_err_exit(const char *err, size_t len_err);

/////// MUTEX //////////////////////
///////////////////////////////////
void	lock_forks(pthread_mutex_t *fork1, pthread_mutex_t *fork2);
void	unlock_forks(pthread_mutex_t *fork1, pthread_mutex_t *fork2);

#endif
