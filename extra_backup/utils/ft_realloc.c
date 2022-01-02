/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 13:16:36 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/02 08:00:27 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../header.h"

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*bf1;
	unsigned char	*bf2;
	size_t			i;

	i = 0;
	bf1 = dst;
	bf2 = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		bf1[i] = bf2[i];
		i++;
	}
	return (dst);
}

void	**ft_realloc(void **tab, int new_size)
{
	int		i;
	void	**new_elements;

	i = 0;
	new_elements = malloc (sizeof(void *) * (new_size + 1));
	if (new_elements == NULL)
	{
		perror ("Error ");
		exit (1);
	}
	ft_memcpy (new_elements, tab,
		(new_size + 1) * sizeof (void *));
	free (tab);
	return (new_elements);
}
