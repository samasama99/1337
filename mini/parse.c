#include "main.h"

bool check_unfulfilled_redirection(char *rl)
{
	char	quote;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (rl[i])
	{
		if (rl[i] == '\'' || rl[i] == '\"')	
		{
			quote = rl[i++];
			while (rl[i] != quote)
				i++;
		}
		else if (rl[i] == '>' || rl[i] == '<')
		{
			j = i++;
			skip_char(rl, &i, ' ');
			if ((rl[j] == '>' && rl[i] == '<')
			   || (rl[j] == '<' && rl[i] == '>')
			   || (rl[i] == '|')
			   || (rl[i] == '\0'))
			{
				printf ("Parsing Error\n");
				return (true);
			}
		}
		i++;
	}
	return (false);
}

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
			section_struct->outfile = section_string[++i];
		}
		else if (ft_strncmp(section_string[i], "<", ft_strlen(section_string[i])) == 0)
		{
			free (section_string[i]);
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
	section_string = lexer(splited_input[0], 1);
	if (section_string == NULL)
		return (NULL);
	head = ft_lstnew(create_section_struct(section_string));
	while(splited_input[i] != NULL)
	{
		section_string = lexer(splited_input[i], 1);
		if (section_string == NULL)
			return (NULL);
		tmp =  create_section_struct(section_string);
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
	splited_input = spilt_with_sp_ignoring_external_quotes(input, '|');
	if (splited_input == NULL)
		return (NULL);
	data = extract_commands(splited_input);
	free_2d_array(splited_input);
	if (data == NULL || data->content == NULL)
		return (NULL);
	return (data);
}

/* int main() */
/* { */
/* 	char *tmp; */

/* 	while(1) */
/* 	{ */
/* 		tmp = readline("> "); */
/* 		check_unfulfilled_redirection(tmp); */
/* 	} */
/* } */
/* /1* int main(void) *1/ */
/* /1* { *1/ */
/* /1* 	char	*test = "ls -l folder | wc -l"; *1/ */
/* /1* 	t_list	*test_list; *1/ */
/* /1* 	int i; *1/ */

/* /1* 	i = 0; *1/ */
/* /1* 	test_list = parse_input(test); *1/ */
/* /1* 	printf("command == %s\n", ((t_section *)test_list->content)->command); *1/ */
/* /1* 	while ((((t_section *)test_list->content)->args)[i]) *1/ */
/* /1* 	{ *1/ */
/* /1* 		printf("arg[%d] == %s\n", i, (((t_section *)test_list->content)->args)[i]); *1/ */
/* /1* 		i++; *1/ */
/* /1* 	} *1/ */
/* /1* 	test_list = test_list->next; *1/ */
/* /1* 	i = 0; *1/ */
/* /1* 	printf("command == %s\n", ((t_section *)test_list->content)->command); *1/ */
/* /1* 	while ((((t_section *)test_list->content)->args)[i]) *1/ */
/* /1* 	{ *1/ */
/* /1* 		printf("arg[%d] == %s\n", i, (((t_section *)test_list->content)->args)[i]); *1/ */
/* /1* 		i++; *1/ */
/* /1* 	} *1/ */
/* /1* 	test_list = test_list->next; *1/ */
/* /1* } *1/ */

/* /1* 	/2* t_section	*test; *2/ *1/ */
/* /1* 	/2* char *ar[2] = {"test1", "test2"} ; *2/ *1/ */
/* /1* 	/2* test = create_section_struct(ar); *2/ *1/ */
