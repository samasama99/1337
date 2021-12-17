#include "../headers/header.h"


int main(int n, char **args)
{
    int x = 8;
    char c;
    int server_pid = ft_atoi(args[1]);
    int i = 0;

    while (i < (ft_strlen(args[2]) + 1))
    {
        c = args[2][i];
        while(x)
        {
            x--;
            if ((c >> x) & 1)
                kill(server_pid, SIGUSR1);
            else
                kill(server_pid, SIGUSR2);
            usleep(100);
        }
        x = 8;
        i++;
    }

}
