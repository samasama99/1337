/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 22:13:35 by orahmoun          #+#    #+#             */
/*   Updated: 2022/02/20 20:35:28 by orahmoun         ###   ########.fr       */
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

enum e_token_types {d_in, d_out, out, in, assignment, word, io_file};
//					0     1		 2	  3   5           6     7

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
			return "assignment";
		case 5:
			return "word";
		case 6:
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

int	redirection_state(t_list **head, char *line, int i)
{
		if (line[i] == line[i + 1])
		{
			if (line[i] == '>')
				ft_lstadd_back(head, ft_lstnew(create_token(ft_strdup(">>"), d_out)));
			else
				ft_lstadd_back(head, ft_lstnew(create_token(ft_strdup("<<"), d_in)));	
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
		return i;
}

int space_state(t_list **head, char *line, int i)
{
		while(line[i] == ' ' && line[i])
			i++;
		/* ft_lstadd_back(head, ft_lstnew(create_token(ft_strdup(" "), space))); */
		return i;
}

int quote_state(char *line, int i)
{
		char	quote;

		quote = line[i++];
		while(line[i] != quote && line[i])
			i++;
		return i;
}

t_list	*tokenizer(char *line)
{
	int		i = 0;
	int		j = 0;
	t_list	*head = NULL;
	bool	assignment_bool = false;
	bool	redirection_bool = false;
	bool	prefix_bool = true;

	while (line[i])
	{
		/* printf ("tokenizing\n"); */
		if (line[i] == '>' || line[i] == '<')
		{
			i = redirection_state(&head, line, i);
			redirection_bool = true;
		}
		else if (line[i] == ' ')
			i = space_state(&head, line, i);
		else if (line[i]) 
		{
			j = i;
			while (line[i] != ' ' && line[i] != '>' && line[i] != '<' && line[i])
			{
				if (line[i] == '\'' || line[i] == '\"')
					i = quote_state(line, i);
				else if (i != j && line[i] == '=')
				{
					assignment_bool = true;
					i++;
				}
				else
					i++;
			}
			/* if (head) */
			/* 	printf ("previous : [%s]\n", ((t_token *)ft_lstlast(head)->content)->elem); */
			/* printf ("middle of the process\n"); */
			if (assignment_bool && prefix_bool) 
			{
				ft_lstadd_back(&head, ft_lstnew(create_token(ft_substr(line, j, i - j), assignment)));
				assignment_bool = false;
			}
			else if (redirection_bool)
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
	/* printf ("tokenizing finished\n"); */
	return (head);
}


void	print_tokens(t_list *tok_list)
{
	t_token	*token;

	while (tok_list)
	{
		token = tok_list->content;
		printf ("[%s] type : [%s]\n", token->elem, return_token_type(token->type));
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
		re_print_command(tok_list);
		line = NULL;
		tok_list = NULL;
	}
}
