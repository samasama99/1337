#include "server.h"
typedef struct  s_binary
{
    int tab[8];
    int current_bit;
    int decimal;
}               t_binary;

t_binary binary;

int ft_pow(int n, int p)
{
    int total;

    total = 1;
    if (!p)
        return 1;
    while (p--)
        total *= n;
    return total;
}

int binary_to_decimal(int tab[])
{
    int len;
    int decimal;
    int i;
    
    len = 7;
    i = 0;
    decimal = 0;
    while (len >= 0)
    {
        decimal += tab[len] * (ft_pow(2, i));
        len--;
        i++;
    }
    return decimal;
}
void receive_binary_handler(int sig, siginfo_t *info, void *context)
{
    unsigned char   t; 
    int i;
    
    i = 0;
    t = 0;
    if(sig == SIGUSR1 && binary.current_bit >= 0)
    {
        binary.tab[binary.current_bit--] = 0;
		kill(info->si_pid, SIGUSR1);
    }
    else if (sig == SIGUSR2 && binary.current_bit >= 0)
    {
        binary.tab[binary.current_bit--] = 1;
		kill(info->si_pid, SIGUSR1);
    }
    if (binary.current_bit < 0)
    {
        binary.current_bit = 7;
        t = (char)binary_to_decimal(binary.tab);
        write(1,&t,1);
        /* while(i < 8) */
        /*     binary.tab[i++] = 0; */
		/* kill(info->si_pid, SIGUSR1); */
    }
}
int main()
{
    ft_printf("the server PID is %d\n", getpid());
    binary.current_bit = 7;
	struct sigaction		sa;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = receive_binary_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
    while(1);
}
