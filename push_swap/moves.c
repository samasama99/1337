#include "header.h"



void	swap_top(t_stack *s)
{
	swap(&(s->elements[0]), &(s->elements[1]));
	write_move_name ("s", s->name);
}

void	push_to(t_stack *src, t_stack *dst)
{
	insert_element (dst, src->elements[0]);	
	delete_element (src, 0);
	write_move_name ("p", src->name);
}

void	rotate(t_stack *s)
{
	int		t;
	
	t = s->elements[0];
	delete_element (s, 0);
	s->elements[s->n_elements++] = t;
	write_move_name ("r", s->name);
}

void	ss(t_stack *a, t_stack *b)
{
	swap_top(a);
	swap_top(b);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
}
