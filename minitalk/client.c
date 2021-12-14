#include "header.h"

int main(int n, char **args)
{
    int one_char;
    int server_pid;
    int i = 0;

    server_pid = ft_atoi(args[1]);

    while (args[2][i])
    {
        one_char = (int)args[2][i];
        ft_printf("sent : %c\n", one_char);
        while(one_char - 10 > 10)
        {
            one_char -= 10;
            kill(server_pid, SIGUSR1);
            usleep(1500);
        }
        while(one_char > 0)
        {
            one_char--;
            kill(server_pid, SIGUSR2);
            usleep(1500);
        }
        kill(server_pid, SIGUSR1);
        i++;
    }
    return 0;
}
