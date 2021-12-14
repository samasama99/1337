#include "../headers/header.h"

static int ft_pow(int n, int p)
{
	int total;

	total = 1;
	if (!p)
		return 1;
	while (p--)
		total *= n;
	return total;
}

int ft_binary_to_decimal(int *tab, int size)
{
	int	decimal;
	int i;

	i = 0;
	decimal = 0;
	while(size)
	{
		decimal += tab[i] * ft_pow(2, --size);
		i++;
	}
	return decimal;
}
