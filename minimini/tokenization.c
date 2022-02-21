/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 22:13:35 by orahmoun          #+#    #+#             */
/*   Updated: 2022/02/20 23:16:32 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// %token  DLESS  DGREAT
//         '<<'   '>>'    
//
//simple_command   : cmd_prefix cmd_word cmd_suffix
                 /* | cmd_prefix cmd_word */
                 /* | cmd_prefix */
                 /* | cmd_name cmd_suffix */
                 /* | cmd_name */
                 /* ; */
/* cmd_name         : WORD                   /1* Apply rule 7a *1/ */
                 /* ; */
/* cmd_word         : WORD                   /1* Apply rule 7b *1/ */
                 /* ; */
/* cmd_prefix       :            io_redirect */
                 /* | cmd_prefix io_redirect */
                 /* |            ASSIGNMENT_WORD */
                 /* | cmd_prefix ASSIGNMENT_WORD */
                 /* ; */
/* cmd_suffix       :            io_redirect */
                 /* | cmd_suffix io_redirect */
                 /* |            WORD */
                 /* | cmd_suffix WORD */
                 /* ; */
/* redirect_list    :               io_redirect */
                 /* | redirect_list io_redirect */
                 /* ; */
/* io_redirect      :           io_file */
                 /* | IO_NUMBER io_file */
                 /* |           io_here */
                 /* | IO_NUMBER io_here */
                 /* ; */
/* io_file          : '<'       filename */
                 /* | '>'       filename */
                 /* ; */
/* filename         : WORD                      /1* Apply rule 2 *1/ */
                 /* ; */
/* io_here          : DLESS     here_end */
                 /* ; */
/* here_end         : WORD                      /1* Apply rule 3 *1/ */

enum e_token_types {d_in, d_out, out, in, space, assignment, word, io_file};
//					0     1		 2	  3   4      5           6     7

char	*return_token_type(int type)
{
	switch (type)
	{
		case 0:
			return "d_out";
		case 1:
			return "d_out";
		case 2:
			return "out";
		case 3:
			return "in";
		case 4:
			return "space";
		case 5:
			return "assignment";
		case 6:
			return "word";
		case 7:
			return "io_word";
		default :
		{
			printf ("unreachable !\n");
			return (NULL);
		}
	}
}
typedef struct s_token
{
	char	*elem;
	int		type;
}	t_token;

t_token	*create_token(char *elem, int type)
{
	t_token *token;

	token = malloc (sizeof(token));
	token->elem = elem;
	token->type = type;
	return (token);
}

t_list	*tokenizer(char *line)
{
	int		i;
	int		j;
	t_list	*head;
	bool	assignment_bool;
	bool	redirection_bool = false;
	bool	prefix_bool = false;

	i = 0;
	j = 0;
	head = NULL;
	assignment_bool = false;
	redirection_bool = false;
	prefix_bool = true;
	while (line[i])
	{
		if (line[i] == '>')
		{
			if (line[i + 1] == '>')
			{
				ft_lstadd_back(&head, ft_lstnew(create_token(ft_strdup(">>"), d_out)));
				i += 2;
			}
			else
			{
				ft_lstadd_back(&head, ft_lstnew(create_token(ft_strdup(">"), out)));
				i++;
			}
			redirection_bool = true;
			
		}
		else if (line[i] == '<')
		{
			if (line[i + 1] == '<')
			{
				ft_lstadd_back(&head, ft_lstnew(create_token(ft_strdup("<<"), d_in)));
				i += 2;
			}
			else
			{
				ft_lstadd_back(&head, ft_lstnew(create_token(ft_strdup("<"), in)));
				i++;
			}
			redirection_bool = true;
		}
		else if (line[i] == ' ')
		{
			while (line[i] == ' ' && line[i])
				i++;
			ft_lstadd_back(&head, ft_lstnew(create_token(ft_strdup(" "), space)));
		}
		else 
		{
			j = i;
			while (line[i] != ' ' && line[i] != '>' && line[i] != '<' && line[i])
			{
				if (line[i] == '\'' || line[i] == '\"')
				{
					skip_until_char(line, &i, line[++i - 1]);
					i++;
				}
				else if (i != j && line[i] == '=')
				{
					assignment_bool = true;
					while (line[i] != ' ' && line[i] != '>' && line[i] != '<' && line[i])
						i++;
					break ;
				}
				else
					i++;
			}
			if (assignment_bool && prefix_bool) 
			{
				ft_lstadd_back(&head, ft_lstnew(create_token(ft_substr(line, j, i - j), assignment)));
				assignment_bool = false;
			}
			else if (redirection_bool == true)
			{
				ft_lstadd_back(&head, ft_lstnew(create_token(ft_substr(line, j, i - j), io_file)));
				redirection_bool = false;
			}
			else
			{
				ft_lstadd_back(&head, ft_lstnew(create_token(ft_substr(line, j, i - j), word)));
				prefix_bool = false;
			}
		}
	}
	return (head);
}


void	print_tokens(t_list *tok_list)
{
	t_token	*token;

	while (tok_list)
	{
		token = tok_list->content;
		printf ("elem : [%s] type : [%s]\n", token->elem, return_token_type(token->type));
		tok_list = tok_list->next;
	}
}

void	re_print_command()
{

}

int main()
{
	t_list	*tok_list;
	char	*line;

	while (1)
	{
		line = readline("> ");
		add_history(line);
		tok_list = tokenizer(line);
		print_tokens(tok_list);
		line = NULL;
		tok_list = NULL;
	}
}
