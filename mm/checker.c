#include "header.h"

typedef union u_moves
{
	void	(*f_proto) (t_stack *, bool);	
	void	(*s_proto) (t_stack *, t_stack *);	
}	t_moves;

char	**pasre_moves(char *s)
{
	char	**moves;

	moves = ft_split (s, '\n');
	return moves;
}


int	move_exist(char *move)
{
	return 0;
}

void	do_move(char *move)
{
	const t_moves func_ptr[7] = {
		{.f_proto = swap_top},
		{.f_proto = rotate},
		{.f_proto = rotate_reverse},
	 	{.s_proto = push_to},
		{.s_proto = ss},
		{.s_proto = rr},
		{.s_proto = rrr}
	};

	func_ptr[1]();
	func_ptr[1].s_proto();
}

int	testing_moves(char **moves)
{
	int	i;

	i = 0;
	if (move_exist(moves[i]))
		do_move(moves[i]);
	else
		return (-1);
	return (1);
}

int	main(int n_args, char **args)
{
	t_stack		a;
	t_stack		b;
	parse_check_error(&a, &b, args, n_args);
	
	if (is_sorted_circulary (a) == 0)
		printf ("ok\n");
	else
		printf ("ko\n");
	// free_stack ();
}
