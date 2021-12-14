#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
int main(int n, char **args)
{
	printf("%d",getpid());
	kill(atoi(args[1]), SIGUSR1);	
}
