/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ber_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:59:32 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/04 18:59:35 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

int	check_ber(char *map_name)
{
	while (*(map_name) != '.')
		map_name++;
	return (ft_strcmp (map_name, ".ber"));
}
