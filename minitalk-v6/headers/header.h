#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
int ft_binary_to_decimal(int *tab, int size);
int *ft_dec_to_binary(int decimal, int size);
char    *ft_strjoin(char const *s1, char const *s2);
size_t  ft_strlen(const char *s);
char    *ft_strdup(const char *s);
void    *ft_calloc(size_t count, size_t size);
void    ft_bzero(void *s, size_t n);
int ft_atoi(const char *str);
void    ft_putstr_fd(char *s, int fd);
void    ft_putnbr_fd(int n, int fd);
void    ft_putchar_fd(char c, int fd);
char	*ft_append_char(char *s, char c);
char	*ft_init_null(void);
