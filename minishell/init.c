#include "main.h"

char	**init_2d_array()
{
	char	**init;

	init = malloc(sizeof(char *));
	*init = NULL;
	return (init);
}

int main()
{
	char **init = init_2d_array();
	init = add_element_2d_array(init, "test", size_of_2d_array(init));
	init = add_element_2d_array(init, "hello", size_of_2d_array(init));
	print_2d_array(init, 1);
}
