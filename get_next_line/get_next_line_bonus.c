/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:19:07 by orahmoun          #+#    #+#             */
/*   Updated: 2021/11/27 14:31:59 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

static void	free_null(char **p)
{
	free (*p);
	*p = NULL;
}

static char	*read_line(int fd, char *current)
{
	char	buffer[BUFFER_SIZE + 1];
	int		read_bytes;

	read_bytes = 1;
	if (current == NULL)
		current = ft_strdup ("");
	while (!ft_strchr (current, '\n') && read_bytes)
	{
		read_bytes = read (fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free_null (&current);
			return (0);
		}
		buffer[read_bytes] = 0;
		current = ft_strjoin(current, buffer);
	}
	return (current);
}

static char	*return_line(char **current)
{
	char	*temp;
	char	*rest;

	if (ft_strlen (*current) && !ft_strchr (*current, '\n'))
	{
		temp = ft_strdup (*current);
		free_null (current);
		return (temp);
	}
	else if (ft_strchr (*current, '\n'))
	{
		temp = ft_substr(*current, 0, ft_strchr(*current, '\n') - *current + 1);
		rest = ft_strdup(ft_strchr(*current, '\n') + 1);
		free_null (current);
		*current = rest;
		return (temp);
	}
	free_null (current);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*tab[1024];

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (0);
	tab[fd] = read_line (fd, tab[fd]);
	if (!tab[fd])
		return (0);
	return (return_line(&tab[fd]));
}
