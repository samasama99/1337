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
			pause();
		}
		else if (c % 2 == 1)
		{
			kill(pid, SIGUSR2);
			pause();
		}
		c /= 2;
		usleep(LAG);
		i--;
	}
	while (i > 0)
	{
		kill(pid, SIGUSR1);
		i--;
		usleep(LAG);
	}
}

void handler1(int sig){};

/* void handler2(int sig) */
/* { */
/* 	write(1, "R", 1); */
/* } */

int main(int n, char **args)
{
    int i;
    if (n != 3)
        return -1;
    i = 0;
	signal(SIGUSR1, handler1);
	/* signal(SIGUSR2, handler2); */
    while(args[2][i])
    {
        send_binary((int)args[2][i], ft_atoi(args[1]));
        i++;
    }
}
