#include "header.h"

static long long	ft_calclenght(const char *str)
{
	unsigned long	x;
	int				i;

	i = 0;
	x = 1;
	while (str[i] >= 48 && str[i] <= 57)
	{
		x = x * 10;
		i++;
	}
	return (x / 10);
}

int	ft_atoi(const char *str)
{
	unsigned int		i;
	unsigned long long	t;
	unsigned long long	x;

	i = 0;
	t = 0;
	x = 1;
	x = ft_calclenght(&str[i]);
	while (str[i] >= 48 && str[i] <= 57)
	{
		t = ((str[i++] - 48) * x) + t;
		x = x / 10;
	}
	return (t);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((unsigned char)s1[i] == (unsigned char)s2[i] && s1[i] && s2[i])
		i++;
	if ((unsigned char)s1[i] - (unsigned char)s2[i] > 0)
		return (1);
	else if ((unsigned char)s1[i] - (unsigned char)s2[i] < 0)
		return (-1);
	return (0);
}
