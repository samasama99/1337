#include "../headers/header.h"

char	*ft_strdup(const char *s)
{
	char	*temp;
	int		i;
	int		l;

	l = 0;
	i = 0;
	while (s[l])
		l++;
	temp = ft_calloc(l + 1, sizeof(char));
	if (!temp)
		return (0);
	while (i < l)
	{
		temp[i] = s[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
