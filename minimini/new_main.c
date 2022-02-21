/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 22:53:25 by orahmoun          #+#    #+#             */
/*   Updated: 2022/02/21 00:19:13 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

int main(void)
{
	t_list	*tok_list;
	char	*line;

	tok_list = NULL;
	while (1)
	{
		line = readline("> ");
		add_history(line);
		tokenizer(&tok_list, line);
		print_tokens(tok_list);
		re_print_command(tok_list);
		line = NULL;
		tok_list = NULL;
	}
}
