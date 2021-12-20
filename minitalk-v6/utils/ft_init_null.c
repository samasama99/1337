#include "../headers/header.h"

char	*ft_init_null(void)
{
	char	*str;

	str = (char *)malloc(1);
	if (!str)
		return 0;
	*str = 0;
	return str;
}
