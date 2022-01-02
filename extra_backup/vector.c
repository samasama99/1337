#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct s_vec
{
	char	**elements;
	int		filled_size;
	int		capacity;
}	t_vec;

void	intial_vec(t_vec *vec)
{
	vec->filled_size = 0;
	vec->capacity = 2;
	vec->elements = malloc(sizeof(char*) * (vec->capacity + 1));
	vec->elements[0] = NULL;
}

void	realloc_vec(t_vec *vec, int newSize)
{
	int		i;
	char	**new_elements;

	i = 0;
	new_elements = malloc(sizeof(char *) * (newSize + 1));
	while (i < vec->filled_size)
	{
		new_elements[i] = vec->elements[i];
		i++;
	}
	new_elements[i] = NULL;
	free(vec->elements);
	vec->elements = new_elements;
}

void	insert_element(t_vec *vec, char *str)
{
	if (vec->filled_size == vec->capacity)
	{
		vec->capacity *= 2;
		realloc_vec(vec, vec->capacity);
	}
	vec->elements[vec->filled_size++] = str;
	vec->elements[vec->filled_size] = NULL;
}


int main()
{
	t_vec	map;
	
	intial_vec(&map);
	insert_element(&map, strdup("hello world 1"));
	insert_element(&map, strdup("hello world 2"));
	insert_element(&map, strdup("hello world 3"));
	insert_element(&map, strdup("hello world 4"));
	insert_element(&map, strdup("hello world 5"));
	insert_element(&map, strdup("hello world 6"));
	
	for (int i = 0; i < map.filled_size; i++)
	{
		printf("%s\n", map.elements[i]);
	}


	return (0);
}
