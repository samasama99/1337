#include "header.h"

void	swap(int *a, int *b)
{
	int		t;

	t = *a;
	*a = *b;
	*b = t;
}

void	write_move_name (char *t, char *name)
{
	write (1, t, 1);
	write (1, name, 1);
	write (1, "\n", 1);
}
