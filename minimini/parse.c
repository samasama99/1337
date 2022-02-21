/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:36:17 by orahmoun          #+#    #+#             */
/*   Updated: 2022/02/18 16:47:02 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	**parse_redirection(char **section_string, t_section *section_struct)
{
	size_t	i;
	char	**args;

	i = 0;
	if (section_string == NULL || section_struct == NULL)
		return (NULL);
	args = init_2d_array();
	while (section_string[i])
	{
		if (ft_strncmp(section_string[i], ">", ft_strlen(section_string[i])) == 0)
		{
			free (section_string[i]);
			free (section_struct->outfile);
			section_struct->outfile = section_string[++i];
		}
		else if (ft_strncmp(section_string[i], "<",
			ft_strlen(section_string[i])) == 0)
		{
			free (section_string[i]);
			free (section_struct->infile);
			section_struct->infile = section_string[++i];
		}
		else
			args = add_element_2d_array_last(args, section_string[i]);
		++i;
	}
	free (section_string);
	return (args);
}

static t_section	*create_section_struct(char **section_string)
{
	t_section	*section_struct;

	section_struct = (t_section *)malloc (sizeof(t_section));
	if (section_struct == NULL)
		return (NULL);
	section_struct->infile = NULL;
	section_struct->outfile = NULL;
	section_string = parse_redirection(section_string, section_struct);
	if (section_string == NULL || *section_string == NULL)
		return (NULL);
	section_struct->command = section_string[0];
	section_struct->args = section_string + 1;
	return (section_struct);
}

static t_list	*extract_commands(char **splited_input)
{
	t_list		*head;
	t_section	*tmp;
	char		**section_string;
	int			i;

	i = 1;
	section_string = scanner(splited_input[0]);
	if (section_string == NULL)
		return (NULL);
	head = ft_lstnew(create_section_struct(section_string));
	while (splited_input[i] != NULL)
	{
		section_string = scanner(splited_input[i]);
		if (section_string == NULL)
			return (NULL);
		tmp = create_section_struct(section_string);
		if (tmp == NULL)
			return (NULL);
		section_string = NULL;
		ft_lstadd_back(&head, ft_lstnew(tmp));
		i++;
	}
	return (head);
}

t_list	*parse_input(char *input)
{
	char	**splited_input;
	t_list	*data;

	if (input == NULL)
		return (0);
	splited_input = spilt_respecting_quotes(input, '|');
	if (splited_input == NULL)
		return (NULL);
	data = extract_commands(splited_input);
	free_2d_array(splited_input);
	if (data == NULL || data->content == NULL)
		return (NULL);
	return (data);
}
