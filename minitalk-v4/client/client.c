#include "../headers/header.h"

void send_binary(char c, int server_pid)
{
	int	*tab;
	int i;

	i = 0;
	tab = ft_dec_to_binary((int)c, 8);
	/* ft_putnbr_fd(c, 1); */
	/* ft_putchar_fd('\n', 1); */
	/* while(i < 8) */
	/* 	ft_putnbr_fd(tab[i++], 1); */
	/* i = 0; */
	while(i < 8 && c)
	{
		if (tab[i] == 0)
			kill(server_pid, SIGUSR1);
		else if (tab[i] == 1)
			kill(server_pid, SIGUSR2);
		usleep(20000);
		i++;
	}

}

void send_msg(char *msg, int server_pid)
{
	int	i;

	i = 0;
	while(msg[i])
	{
		send_binary(msg[i], server_pid);
		i++;
		/* if(msg[i]) */
		/* 	kill(server_pid, SIGUSR1); */
		/* else */
		/* 	kill(server_pid, SIGUSR2); */
	}
	kill(server_pid, SIGUSR1);
}
/* void handler(int sig){}; */
int main(int n, char **args)
{
	/* signal(SIGUSR1, handler); */
	send_msg(args[2], ft_atoi(args[1]));
}
