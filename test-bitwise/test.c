#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/* void handler(int sig) */
/* { */
/*     static int index; */
/*     char c = 0; */

/*     if(sig == SIGUSR1) */
/*     { */
/*         c = c << 1; */
/*         index++; */
/*     } */
/*     else */
/*     { */
/*         c = c | 1; */
/*         c = c << 1; */
/*         index++; */
/*     } */
/*     if (index == 8) */
/*         write(1, &c, 1); */

/* } */

int main()
{
    char c = 0;
    
    c = c | 1;
    c = c << 6;
    c = c | 1;
    printf("%c %d\n", c, c);
}
