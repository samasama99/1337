/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:12:09 by orahmoun          #+#    #+#             */
/*   Updated: 2021/12/23 15:12:52 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/header.h"

static void	ft_free(char **s)
{
	free(*s);
	*s = NULL;
}

static int	msg_protection(int current_pid)
{
	static int	server_pid;

	if (server_pid == 0)
		server_pid = current_pid;
	if (current_pid != server_pid)
	{
		server_pid = current_pid;
		return (0);
	}
	return (1);
}

static void	receive_binary_handler(int sig, siginfo_t *info, void *context)
{
	static int		index;
	static char		c;
	static char		*str;

	(void)context;
	if (msg_protection (info->si_pid) == 0)
	{
		index = 0;
		ft_free (&str);
	}
	c = c << 1;
	if (sig == SIGUSR1)
		c = c | 1;
	if (++index == 8)
	{
		str = ft_append_char(str, c);
		if (c == 0)
		{
			ft_printf("%s\n -- msg was sent from : %d\n", str, info->si_pid);
			ft_free(&str);
			kill(info->si_pid, SIGUSR1);
		}
		index = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_putstr_fd("the server pid : ", 1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = receive_binary_handler;
	sigaction (SIGUSR1, &sa, NULL);
	sigaction (SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
