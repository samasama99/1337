#include "client.h"

void send_binary(int c, int pid)
{
   int tab[8];
   int i;

   i = 0;
   while (i < 8)
       tab[i++] = 0;
    while(c > 0)
    {
        if(c % 2 == 0)
        {
            kill(pid, SIGUSR1);
        }
        else if (c % 2 == 1)
        {
            kill(pid, SIGUSR2);
        }
        c /= 2;
        usleep(100);
        i--;
    }
    while (i > 0)
    {
        kill(pid, SIGUSR1);
        i--;
        usleep(100);
    }
}
int main(int n, char **args)
{
    int i;

    i = 0;
    while(args[2][i])
    {
        send_binary((int)args[2][i], ft_atoi(args[1]));
        i++;
    }
}
