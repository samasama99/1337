/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:33:42 by orahmoun          #+#    #+#             */
/*   Updated: 2022/02/10 13:57:56 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int n, char **args)
{
	int	i;

	if (n > 1)
	{
		i = 1;
		if (ft_strcmp(args[1], "-n") == 0)
		{
			++i;
			--n;
		}
		while (--n)
		{
			printf("%s", args[i]);
			if (n - 1)
				printf (" ");
			i++;
		}
		if (ft_strcmp(args[1], "-n") != 0)
			printf ("\n");
	}
	else
		printf ("\n");
}
