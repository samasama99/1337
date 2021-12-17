#include "ft_dec_to_binary.c"
#include "ft_binary_to_decimal.c"
#include <stdio.h>

int main()
{
	int *tab = ft_dec_to_binary(2, 8);
	int i = 0;
	int decimal;

	while(i < 8)
	{
		printf("%d",tab[i++]);
	}
	decimal = ft_binary_to_decimal(tab, 8);
	printf("\n%d", decimal);
}
