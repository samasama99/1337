#include "../headers/header.h"

int *ft_dec_to_binary(int decimal, int size)
{
	int	*tab;
	int	i;
	
	tab = (int *)malloc(sizeof(int) * size);
	if(!tab)
		return 0;
	i = 0;
	while(decimal)
	{
		tab[size - i - 1] = decimal % 2;
		decimal /= 2;
		i++;
	}
	while(size - i - 1 >= 0)
	{
		tab[size - i - 1] = 0;
		i++;
	}
	return tab;
}
