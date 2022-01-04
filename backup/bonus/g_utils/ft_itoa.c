/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 05:51:20 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/03 22:48:02 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

static char	*ft_strdup_static(const char *s)
{
	char	*temp;
	int		i;
	int		l;

	l = 0;
	i = 0;
	while (s[l])
		l++;
	temp = (char *)malloc(l + 1);
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

static char	*ft_itoa_negative(long long n)
{
	int			len;
	long long	num;
	char		*str;

	n = n * -1;
	num = n;
	len = 1;
	while (num)
	{
		num = num / 10;
		len++;
	}
	str = (char *)malloc (len + 1);
	if (!str)
		return (0);
	str[len] = '\0';
	while (n)
	{
		str[len - 1] = (n % 10) + 48;
		len--;
		n = n / 10;
	}
	str[0] = '-';
	return (str);
}

static char	*ft_itoa_positive(int n)
{
	int		len;
	int		num;
	char	*str;

	if (n == 0)
		return (ft_strdup_static ("0"));
	len = 0;
	num = n;
	while (num)
	{
		num = num / 10;
		len++;
	}
	str = (char *)malloc (len + 1);
	if (!str)
		return (0);
	str[len] = '\0';
	while (n)
	{
		str[len - 1] = (n % 10) + 48;
		len--;
		n = n / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	if (n >= 0)
		return (ft_itoa_positive(n));
	else
		return (ft_itoa_negative(n));
	return (0);
}
