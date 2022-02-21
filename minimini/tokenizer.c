/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 22:13:35 by orahmoun          #+#    #+#             */
/*   Updated: 2022/02/21 00:59:47 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "tokenizer.h"

t_token	*create_token(char *elem, int type)
{
	t_token	*token;

	token = malloc (sizeof(token));
	token->elem = elem;
	token->type = type;
	return (token);
}

int	redirection_state(t_list **head, char *line, int i)
{
	if (line[i] == line[i + 1])
	{
		if (line[i] == '>')
			ft_lstadd_back(head,
				ft_lstnew(create_token(ft_strdup(">>"), d_out)));
		else
			ft_lstadd_back(head,
				ft_lstnew(create_token(ft_strdup("<<"), d_in)));
		i += 2;
	}
	else
	{
		if (line[i] == '>')
			ft_lstadd_back(head, ft_lstnew(create_token(ft_strdup(">"), out)));
		else
			ft_lstadd_back(head, ft_lstnew(create_token(ft_strdup("<"), in)));
		i++;
	}
	return (i);
}

bool	crop(t_list **head, char *line, int i, bool prefix)
{
	char		*tmp;

	tmp = ft_substr(line, 0, i);
	if (*head && ((t_token *)(ft_lstlast(*head)->content))->type < 4)
		ft_lstadd_back(head,
			ft_lstnew(create_token(ft_substr(line, 0, i), io_file)));
	else
	{
		if (ft_strchr(tmp, '=') && tmp[0] != '=' && prefix)
		{
			ft_lstadd_back(head,
				ft_lstnew(create_token(tmp, assignment)));
		}
		else
		{
			ft_lstadd_back(head,
				ft_lstnew(create_token(tmp, word)));
			prefix = false;
		}
	}
	return (prefix);
}

void	tokenizer(t_list **head, char *s)
{
	int		i;
	int		j;
	bool	prefix;

	init_indexs(2, 0, &i, &j);
	prefix = true;
	while (s[i])
	{
		if (s[i] == '>' || s[i] == '<')
			i = redirection_state(head, s, i);
		else if (s[i] == ' ')
			i++;
		else if (s[i])
		{
			j = i;
			while (s[i] != ' ' && s[i] != '>' && s[i] != '<' && s[i])
			{
				if (s[i] == '\'' || s[i] == '\"')
					skip_until_char(s, &i, ++i - 1);
				else
					i++;
			}
			prefix = crop(head, s + j, i - j, prefix);
		}
	}
}
