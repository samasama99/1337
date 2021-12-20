#include "../headers/header.h"

static void receive_binary_handler(int sig, siginfo_t *info, void *context)
{
    static int      index;
    static char     c;
    static char     *str;

    c = c << 1;
    if(sig == SIGUSR1)
        c = c | 1;
    if (++index == 8)
    {
        if (str == 0)
            str = ft_init_null();
        str = ft_append_char(str, c);
        if (c == 0)
        {
            ft_putstr_fd(str, 1);
            ft_putstr_fd("\n -- msg was sent from : ", 1);
            ft_putnbr_fd(info->si_pid, 1);
            ft_putchar_fd('\n', 1);
            free(str);
            str = NULL;
            kill(info->si_pid, SIGUSR2);
        }
        index = 0;
        c = 0;
    }
	/* else */
    	/* kill(info->si_pid, SIGUSR1); */
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
