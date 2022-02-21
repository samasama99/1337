/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:35:51 by orahmoun          #+#    #+#             */
/*   Updated: 2022/02/18 21:54:53 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	print_parsed_data(t_list *data)
{
	t_section	*section;
	int			i;
	
	i = 0;
	if (data == NULL)
		return ;
	while (data)
	{
		section = data->content;	
		printf("Command : %s\n", section->command);
		while (section->args[i])
		{
			printf("argument[%d] : %s\n", i, section->args[i]);
			i++;
		}
		if (section->infile)
			printf ("infile : %s\n", section->infile);
		if (section->outfile)
			printf ("outfile : %s\n", section->outfile);
		i = 0;
		data = data->next;
	}
}

void	free_2d_array_elem(char **array)
{
	int	i;

	i = 0;
	if (array != NULL)
	{
		while (array[i])
			free(array[i++]);
	}
}
void	free_parsed_data(t_list *data)
{
	t_section	*section;
	t_list		*tmp;
	int			i;
	
	i = 0;
	if (data == NULL)
		return ;
	while (data)
	{
		tmp = data;
		section = data->content;	
		free_2d_array_elem(section->args);
		free(section->args - 1);
		free(section->command);
		free(section->infile);
		free(section->outfile);
		free(section);
		data = data->next;
		free(tmp);
	}
}

int main(int n, char **args, char **env)
{
	char		*rl;
	t_list		*parsed_data;
	bool		err;
	char		*prompt;
	ENV = dup_2d_array(env);

	prompt = "🔹 > ";
	while (1)
	{
		rl = readline(prompt);
		if (*rl != '\0' && check_errors(rl) == false)
			add_history(rl);
		else
		{
			free(rl);
			rl = NULL;
			continue ;
		}
		parsed_data =  parse_input(rl);
		if (parsed_data == NULL)
		{
			free(rl);
			rl = NULL;
			err = true;
			prompt = "🔸 > ";
			continue ;
		}
		print_parsed_data(parsed_data);
		free_parsed_data(parsed_data);
		parsed_data = NULL;
		free(rl);
		rl = NULL;
		err= false;
		prompt = "🔹 > ";
	}
}
