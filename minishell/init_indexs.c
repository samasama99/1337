/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_indexs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:02:31 by orahmoun          #+#    #+#             */
/*   Updated: 2022/02/14 12:13:13 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"
#include <stdarg.h>

void	init_indexs(int amount, int value, ...)
{
	va_list	args;
	int		*tmp;

	va_start(args, value);
	while (amount--)
	{
		tmp = va_arg(args, int *);
		*tmp = value;
	}
	va_end(args);
}

/* int main() */
/* { */
/* 	int x; */
/* 	int y; */

/* 	init_indexs(2, 0, &x, &y); */
/* 	printf ("%d %d\n", x , y); */
/* } */
