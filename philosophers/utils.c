#include "main.h"

void	write_err_exit(const char *err, size_t len_err)
{
	write (STDERR, err, len_err);
	exit(1);
}
