#include "main.h"

static t_section	*create_section_struct(char **section_string)
{
	t_section	*section_struct;

	section_struct = malloc (sizeof(t_section));
	section_struct->command = section_string[0];
	section_struct->args = section_string + 1;
	return (section_struct);
}

static t_list	*extract_commands(char **splited_input)
{
	t_list		*head;
	char		**section_string;
	int			i;

	i = 1;
	section_string = ft_split(splited_input[0], ' ');
	head = ft_lstnew(create_section_struct(section_string));
	while(splited_input[i] != NULL)
	{
		section_string = ft_split(splited_input[i], ' ');
		ft_lstadd_back(&head, ft_lstnew(create_section_struct(section_string)));
		i++;
	}
	return (head);
}

t_list	*parse_input(char *input)
{
	char	**splited_input;

	if (input == NULL)
		return (0);
	splited_input = ft_split(input, '|');
	return (extract_commands(splited_input));
}

/* int main(void) */
/* { */
/* 	char	*test = "ls -l folder | wc -l"; */
/* 	t_list	*test_list; */
/* 	int i; */

/* 	i = 0; */
/* 	test_list = parse_input(test); */
/* 	printf("command == %s\n", ((t_section *)test_list->content)->command); */
/* 	while ((((t_section *)test_list->content)->args)[i]) */
/* 	{ */
/* 		printf("arg[%d] == %s\n", i, (((t_section *)test_list->content)->args)[i]); */
/* 		i++; */
/* 	} */
/* 	test_list = test_list->next; */
/* 	i = 0; */
/* 	printf("command == %s\n", ((t_section *)test_list->content)->command); */
/* 	while ((((t_section *)test_list->content)->args)[i]) */
/* 	{ */
/* 		printf("arg[%d] == %s\n", i, (((t_section *)test_list->content)->args)[i]); */
/* 		i++; */
/* 	} */
/* 	test_list = test_list->next; */
/* } */

/* 	/1* t_section	*test; *1/ */
/* 	/1* char *ar[2] = {"test1", "test2"} ; *1/ */
/* 	/1* test = create_section_struct(ar); *1/ */
