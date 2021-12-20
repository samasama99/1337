#include "../headers/header.h"

char	*ft_append_char(char *s, char c)
{
	char	*str;
	int		i;

	if (s == NULL)
		return (0);
	str = (char *)malloc (ft_strlen(s) + 2);
	if (!str)
		return (0);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i++] = c;
	str[i] = '\0';
	return (str);
}
