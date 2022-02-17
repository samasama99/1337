/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:33:42 by orahmoun          #+#    #+#             */
/*   Updated: 2022/02/16 10:38:27 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	echo(char **args, int fd)
{
	int	i;

	i = 0;
	if (args != NULL && *args != NULL && **args != '\0')
	{
		if (ft_strncmp(args[0], "-n", ft_strlen(args[0])) == 0)
			++i;
		while (args[i])
		{
			ft_putstr_fd(args[i], fd);
			if (args[i + 1])
				ft_putstr_fd(" ", fd);
			i++;
		}
		if (ft_strncmp(args[0], "-n", ft_strlen(args[0])) != 0)
			ft_putstr_fd("\n", 1);
	}
	else
		ft_putstr_fd("\n", fd);
}
