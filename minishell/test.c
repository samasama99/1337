#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include "main.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((unsigned char)s1[i] == (unsigned char)s2[i]
		&& s1[i] && s2[i])
		i++;
	if ((unsigned char)s1[i] - (unsigned char)s2[i] > 0)
		return (1);
	else if ((unsigned char)s1[i] - (unsigned char)s2[i] < 0)
		return (-1);
	return (0);
}

/* void handling_sigint(int sig) */
/* { */
/* 	if (sig == SIGINT) */
/* 	{ */
/* 		/1* rl_replace_line("", 0); *1/ */
/* 		rl_redisplay(); */
/* 		rl_on_new_line(); */
/* 		printf("hello\n"); */
/* 	} */
/* } */

int main(int n, char **args, char **env)
{
	char	*tmp;
	t_list	*list;
	char	**env_dup;
	/* signal(SIGINT, handling_sigint); */
	env_dup = dup_2d_array(env);
	while(1)
	{
		tmp = readline("> ");
		if (ft_strcmp(tmp, "exit") == 0)
			exit(0);
		if (ft_strcmp(tmp, "pwd") == 0)
			pwd();
		if (ft_strcmp(tmp, "env") == 0)
			print_env(env_dup);
		if (tmp != NULL && *tmp != '\0')
		{
			list = parse_input(tmp);
			if (ft_strcmp(((t_section  *)list->content)->command, "cd") == 0)
				cd(((t_section  *)list->content)->args[0], env_dup);
		}
		if (tmp != NULL && *tmp != '\0')
		{
			if (ft_strcmp(((t_section  *)list->content)->command, "echo") == 0)
				echo(((t_section  *)list->content)->args);
		}
		add_history(tmp);
	}
}
