#include "includes/ft_printf.h"
#include <stdio.h>
int main()
{
	int a = 1000;
	printf(" ::: %d\n", ft_printf("%c %d %d %i %u %d %s %x %X %p", 'A' , 'A' , 5 , -10 , -10 , 10 , "HELLO", 255 , 255 , &a));
	printf(" ::: %d\n", printf   ("%c %d %d %i %u %d %s %x %X %p", 'A' , 'A' , 5 , -10 , -10 , 10 , "HELLO", 255 , 255 , &a));
	printf(" ::: %d\n", ft_printf("%c",65));
	printf(" ::: %d\n",    printf("%c",65));
}
