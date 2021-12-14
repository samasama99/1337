#include "header.h"

typedef struct  one_char
{
    int total;
    int the_end;
}               one_char;


one_char o_char = {0, 0};

void ft_sum(int sig)
{
    char wr;

    if(sig == SIGUSR1 && o_char.the_end == 0)
        o_char.total += 10;
    else if(sig == SIGUSR2)
    {
        o_char.total++;
        o_char.the_end = 1;
    }else
    {
        wr = o_char.total;
        write(1, &wr, 1);
        o_char.total = 0;
        o_char.the_end = 0;
    }
}

/* void ft_sum(int sig) */
/* { */
/*     if(sig == SIGUSR1) */
/*         ft_printf("I'm signal number %d\n",sig); */
/*     else if(sig == SIGUSR2) */
/*     { */
/*         ft_printf("I'm signal number %d\n",sig); */
/*     } */
/* } */

int main()
{
    int pid;

    pid = getpid();
    ft_printf("the process PID is : %d\n", pid);   
    signal(SIGUSR1, ft_sum); 
    signal(SIGUSR2, ft_sum); 

    while(1);
}
