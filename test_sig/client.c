#include "header.h"

void ft_msgres(int sig)
{
    ft_printf("server received the msg !\n");
}

int main(int n, char **args)
{
    if (ft_strcmp(args[1] ,"msg") == 0)
    {
        kill(ft_atoi(args[2]), SIGUSR1);
    }
    else if (ft_strcmp(args[1] ,"quit") == 0)
    {
        kill(ft_atoi(args[2]), 2);
    }
    signal(2, ft_msgres);
    return 0;
}
