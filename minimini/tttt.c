/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 22:13:35 by orahmoun          #+#    #+#             */
/*   Updated: 2022/02/20 23:58:26 by orahmoun         ###   ########.fr       */
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

void	crop(t_list **head, bool trio[3], char *line, int i)
{
	if (trio[2] && trio[1])
	{
		ft_lstadd_back(head,
			ft_lstnew(create_token(ft_substr(line, 0, i), assignment)));
		trio[2] = false;
	}
	else if (*head && ((t_token *)(ft_lstlast(*head)->content))->type < 4)
	{
		ft_lstadd_back(head,
			ft_lstnew(create_token(ft_substr(line, 0, i), io_file)));
		/* trio[0] = false; */
	}
	else
	{
		ft_lstadd_back(head,
			ft_lstnew(create_token(ft_substr(line, 0, i), word)));
		trio[1] = false;
	}
}

//	REDIRECTION_BOOL trio[0]
//	PREFIX_BOOL trio[1]
//	ASSIGNMENT_BOOL trio[2]
t_list	*tokenizer(char *line)
{
	int		i;
	int		j;
	t_list	*head;
	bool	trio[3];

	i = 0;
	j = 0;
	head = NULL;
	/* trio[0] = false; */
	trio[1] = true;
	trio[2] = false;
	while (line[i])
	{
		if (line[i] == '>' || line[i] == '<')
		{
			i = redirection_state(&head, line, i);
			/* trio[0] = true; */
		}
		else if (line[i] == ' ')
			i++;
		else if (line[i])
		{
			j = i;
			while (line[i] != ' ' && line[i] != '>'
				&& line[i] != '<' && line[i])
			{
				if (line[i] == '\'' || line[i] == '\"')
					skip_until_char(line, &i, ++i - 1);
				else if (i != j && line[i] == '=')
				{
					trio[2] = true;
					i++;
				}
				else
					i++;
			}
			crop(&head, trio, line + j, i - j);
		}
	}
	return (head);
}
