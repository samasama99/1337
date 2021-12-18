#include "../headers/header.h"
int sending_msg;
void handler(int sig){
    sending_msg = 0;
}

int main(int n, char **args)
{
    int x = 8;
    char c;
    int server_pid = ft_atoi(args[1]);
    int i = 0;
    sending_msg = 1;

    signal(SIGUSR1, handler);
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
            /* usleep(100); */
        }
        x = 8;
        i++;
    }
    while(sending_msg);
    ft_putstr_fd("-- msg was sent to the server(", 1);
    ft_putnbr_fd(server_pid, 1);
    ft_putstr_fd(")\n", 1);
}
