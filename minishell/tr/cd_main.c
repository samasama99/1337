#include "main.h"

int	main(int n, char **args, char **env)
{
	char	**env_dup;

	env_dup = dup_2d_array(env);
	printf ("%d\n", cd("libft2", env_dup));

	free_2d_array(env_dup);
	while(1);
}
