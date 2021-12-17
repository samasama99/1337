#include "../headers/header.h"


void handler(int sig)
{
    static int      index;
    static char     c;

    if(sig == SIGUSR2)
    {
        c = c << 1;
        index++;
    }
    else
    {
        c = c << 1;
        c = c | 1;
        index++;
    }
    if (index == 8)
    {
        write(1, &c, 1);
        index = 0;
        c = 0;
    }
    

}

int main()
{
    ft_putstr_fd("the server PID is : ", 1);
    ft_putnbr_fd(getpid(), 1);
    ft_putchar_fd('\n', 1);
    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);
    while(1)
        pause();
}
