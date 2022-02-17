/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:12:25 by orahmoun          #+#    #+#             */
/*   Updated: 2022/02/15 15:12:33 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	skip_char(char *str, int *i, char c)
{
	while (str[*i] && str[*i] == c)
		(*i)++;
	if (str[*i] == '\0')
		return (-1);
	return (*i);
}

int	skip_until_char(char *str, int *i, char c)
{
	while (str[*i] && str[*i] != c)
		(*i)++;
	if (str[*i] == '\0')
		return (-1);
	return (*i);
}
