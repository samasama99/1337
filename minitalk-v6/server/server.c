#include "../headers/header.h"


void handler(int sig)
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
            ft_putstr_fd("\n -- end of the msg\n", 1);
            free(str);
            str = NULL;
        }
        index = 0;
        c[0] = 0;
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
