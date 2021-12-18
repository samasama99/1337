#include "../headers/header.h"


void receive_binary_handler(int sig, siginfo_t *info, void *context)
{
    static int      index;
    static char     c[2];
    static char     *str;

    if(sig == SIGUSR2)
    {
        c[0] = c[0] << 1;
        index++;
    }
    else
    {
        c[0] = c[0] << 1;
        c[0] = c[0] | 1;
        index++;
    }
    c[1] = 0;
    if (index == 8)
    {
        if (str == 0)
            str = ft_strdup("");
        str = ft_strjoin(str, c);
        if (c[0] == 0)
        {
            ft_putstr_fd(str, 1);
            ft_putstr_fd("\n -- msg was sent from : ", 1);
            ft_putnbr_fd(info->si_pid, 1);
            ft_putchar_fd('\n', 1);
            free(str);
            str = NULL;
            kill(info->si_pid, SIGUSR1);
        }
        index = 0;
        c[0] = 0;
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
