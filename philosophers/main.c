#include "main.h"

// args :
//	number_of_philosophers 
//	time_to_die
//	time_to_eat 
//	time_to_sleep 
//	[number_of_times_each_philosopher_must_eat]


int main(int n, char **args)
{
	t_info info;
	size_t		i;

	i = -1;
	if (n < 5 || n > 6)
		write_err_exit ("Error\n", 6);
	init_philo_struct (&info, n, args);
	while (++i < info.number_of_philos)
		pthread_mutex_init(info.forks + i, NULL);
	pthread_mutex_init(&info.death, NULL);
	create_philos(&info);	
	pthread_mutex_destroy(info.forks);
	pthread_mutex_destroy(&info.death);
}
