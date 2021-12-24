/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:12:15 by orahmoun          #+#    #+#             */
/*   Updated: 2021/12/23 20:06:42 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/header.h"

static void	handler(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_printf("msg was sent to the server !");
		exit(0);
	}
}

static void	ft_sending_msg(char *s, int server_pid)
{
	char	c;
	int		x;
	int		i;

	x = 8;
	i = 0;
	while (i < (int)(ft_strlen(s) + 1))
	{
		c = s[i];
		while (x)
		{
			x--;
			if ((c >> x) & 1)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			usleep(137);
		}
		x = 8;
		i++;
	}
}

int	main(int n, char **args)
{
	int		server_pid;

	if (n == 3)
	{
		server_pid = ft_atoi(args[1]);
		signal(SIGUSR1, handler);
		ft_sending_msg(args[2], server_pid);
		pause();
		return (0);
	}
	ft_printf("argument 1 should be the server pid (int)\n");
	ft_printf("argument 2 should be the msg\n");
	return (1);
}
