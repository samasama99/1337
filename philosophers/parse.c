#include "main.h"

void init_philo_struct(t_info *info, int number_of_args, char **args)
{
	int		i;

	i = 0;
	info->number_of_philos = ft_atoi(args[1]);
	info->finished_eating = ft_atoi(args[1]);
	info->time_to_die = ft_atoi(args[2]);
	info->time_to_eat = ft_atoi(args[3]);
	info->time_to_sleep = ft_atoi(args[4]);
	info->philo_dies = 1;
	if (number_of_args == 6)
	{
		info->each_philo_must_eat = ft_atoi(args[5]);
		while (i < (int)info->number_of_philos)
			info->philos[i++].must_eat = ft_atoi(args[5]);
	}
	else
	{
		info->each_philo_must_eat = -1;
		while (i < (int)info->number_of_philos)
			info->philos[i++].must_eat = -1;
	}
}
