/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 02:07:03 by orahmoun          #+#    #+#             */
/*   Updated: 2021/12/31 19:40:11 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((unsigned char)s1[i] == (unsigned char)s2[i]
		&& s1[i] && s2[i])
		i++;
	if ((unsigned char)s1[i] - (unsigned char)s2[i] > 0)
		return (1);
	else if ((unsigned char)s1[i] - (unsigned char)s2[i] < 0)
		return (-1);
	return (0);
}
