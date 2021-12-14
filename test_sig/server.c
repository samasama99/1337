#include "header.h"


void ft_running(int sig)
{
    ft_printf("server is still running ! received  signal %d \n",sig);
}

/* void ft_stopped(int sig) */
/* { */
/*     ft_printf("server is stopped !\n"); */
/*     kill(pid, sig); */
/* } */

int main()
{
    int pid;

    pid = getpid();
    ft_printf("the process PID is : %d\n", pid);   
    signal(SIGUSR1, ft_running); 
    /* signal(3, ft_stopped); */ 
    while(1)
        pause();
}
