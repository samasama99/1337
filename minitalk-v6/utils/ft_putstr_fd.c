#include "../headers/header.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i])
			i++;
		write (fd, s, i);
	}
}
