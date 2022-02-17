/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:34:34 by orahmoun          #+#    #+#             */
/*   Updated: 2022/02/12 11:20:45 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

char	*return_current_dir(void)
{
	char	*path;

	path = malloc (sizeof(char) * 4096 + 1);
	getcwd(path, 4096 + 1);
	return (path);
}

void	pwd(int fd)
{
	char	*path;

	path = malloc (sizeof(char) * 4096 + 1);
	getcwd(path, 4096 + 1);
	ft_putstr_fd(path, fd);
	ft_putstr_fd("\n", fd);
	free (path);
}
