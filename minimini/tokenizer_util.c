/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 22:53:25 by orahmoun          #+#    #+#             */
/*   Updated: 2022/02/20 23:14:53 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

char	*return_token_type(int type)
{
	if (type == 0)
		return ("d_in");
	else if (type == 1)
		return ("d_out");
	else if (type == 2)
		return ("out");
	else if (type == 3)
		return ("in");
	else if (type == 4)
		return ("assignment");
	else if (type == 5)
		return ("word");
	else if (type == 6)
		return ("io_word");
	else if (type == 6)
		return ("delimiter");
	return (NULL);
}

void	print_tokens(t_list *tok_list)
{
	t_token	*token;

	while (tok_list)
	{
		token = tok_list->content;
		printf ("[%s] type : [%s]\n",
			token->elem, return_token_type(token->type));
		tok_list = tok_list->next;
	}
}

void	re_print_command(t_list	*tok_list)
{
	t_token	*token;

	while (tok_list)
	{
		token = tok_list->content;
		printf ("%s ", token->elem);
		tok_list = tok_list->next;
	}
	printf("\n");
}
