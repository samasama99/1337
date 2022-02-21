/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:44:08 by orahmoun          #+#    #+#             */
/*   Updated: 2022/02/19 21:33:29 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static bool	check_unfulfilled_pipes(char *rl)
{
	int	i;

	i = 0;
	skip_char(rl, &i, ' ');
	if (rl[i] == '|')
		return (true);
	while (rl[i])
	{
		if (rl[i] == '\'' || rl[i] == '\"')
			skip_char(rl, &i, rl[++i - 1]);
		if (rl[i] == '|')
		{
			++i;
			skip_char(rl, &i, ' ');
			if (rl[i] == '\0' || rl[i] == '|')
				return (true);
		}
		i++;
	}
	return (false);
}

static bool	check_unclosed_quotes(char *read_line)
{
	bool	open_quotes;
	char	quote;

	quote = '\0';
	open_quotes = false;
	if (read_line == NULL || *read_line == '\0')
		return (1);
	while (*read_line)
	{
		if (*read_line == '\"' || *read_line == '\'')
		{
			if (open_quotes == false && quote == '\0')
			{
				quote = *read_line;
				open_quotes = true;
			}
			else if (*read_line == quote)
			{
				quote = '\0';
				open_quotes = false;
			}
		}
		++read_line;
	}
	return (open_quotes);
}

static bool	check_unfulfilled_redirection(char *rl)
{
	int		i;
	int		j;

	init_indexs(2, 0, &i, &j);
	while (rl[i])
	{
		if (rl[i] == '\'' || rl[i] == '\"')
			skip_until_char(rl, &i, rl[i++]);
		else if (rl[i] == '>' || rl[i] == '<')
		{
			j = i++;
			skip_char(rl, &i, ' ');
			if ((rl[j] == '>' && rl[i] == '<')
				|| (rl[j] == '<' && rl[i] == '>')
				|| (rl[i] == '|')
				|| (rl[i] == '\0')
				|| ((i - j) != 1 && (rl[j] == rl [i])))
			{
				return (true);
			}
		}
		i++;
	}
	return (false);
}

bool	check_errors(char *rl)
{
	if (rl == NULL || *rl == '\0')
		return (true);
	if (check_unclosed_quotes(rl))
	{
		write (2, "MiniShell : unclosed Quotes\n", 28);
		return (true);
	}
	if (check_unfulfilled_pipes(rl))
	{
		write (2, "MiniShell : unfulfilled pipes\n", 30);
		return (true);
	}
	if (check_unfulfilled_redirection(rl))
	{
		write (2, "MiniShell : unfulfilled redirection\n", 35);
		return (true);
	}
	return (false);
}
