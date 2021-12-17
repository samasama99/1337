#include "../headers/header.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;
	size_t	i;

	i = 0;
	tmp = (void *) malloc (size * count);
	if (!tmp)
		return (0);
	ft_bzero(tmp, count * size);
	return (tmp);
}
