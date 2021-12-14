#include "../headers/header.h"

void receive_binary_handler(int sig, siginfo_t *info, void *context)
{
	static char 	*msg;
	static int		index;
	int		tab[8];
	char	c[2];
	/* char	*temp; */
	
	/* ft_putnbr_fd(index, 1); */
	if (!msg)
		msg = ft_strdup("");	
	if(sig == SIGUSR1 && index < 8)
		tab[index] = 0;
	else if (sig == SIGUSR2 && index < 8)
		tab[index] = 1;
	/* kill(info->si_pid, SIGUSR1); */
	if(index < 8)
	{
		write(1, "tab[index] : ", ft_strlen("tab[index] : "));
		ft_putnbr_fd(tab[index], 1);
		write(1, "\n", 1);
		write(1, "index : ", ft_strlen("index : "));
		ft_putnbr_fd(index, 1);
		write(1, "\n", 1);
	}
	index++;
	/* if(index == 8) */
	/* { */
	/* 	c[0] = ft_binary_to_decimal(tab, 8); */
	/* 	c[1] = 0; */
	/* 	write(1, &c[0], 1); */
	/* 	int i = 0; */
	/* 	while(i < 0) */
	/* 		ft_putnbr_fd(tab[i++], 1); */
	/* 	/1* temp = msg; *1/ */
	/* 	/1* msg = ft_strjoin(msg, c); *1/ */
	/* 	/1* free(temp); *1/ */
	/* } */
	if(index == 9)
	{
		/* write(1, "\n", 1); */
		/* write(1, msg, ft_strlen(msg)); */
		/* write(1, "\n", 1); */
		/* if(sig == SIGUSR2) */
		/* { */
		/* 	/1* write(1, msg, ft_strlen(msg)); *1/ */
		/* 	free(msg); */
		/* 	msg = NULL; */
		/* } */
		index = 0;
	}
}

int main()
{
	struct sigaction sa;
	
	ft_putstr_fd("the server pid : ", 1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = receive_binary_handler;
	sigaction (SIGUSR1, &sa, NULL);
	sigaction (SIGUSR2, &sa, NULL);
	while(1)
		pause();
}
