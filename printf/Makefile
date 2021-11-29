NAME	=	libftprintf.a

FUNCTION = ft_printf.c

SRCS	=	utils/ft_putchar_fd.c \
			utils/ft_putnbr_base.c \
			utils/ft_putnbr_fd.c \
			utils/ft_putstr_fd.c \
			utils/ft_strlen.c	

OBJS	=	*.o

INCL	=	includes/ft_printf.h

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror -c

all : ${NAME}

${NAME} : ${OBJS} ${INCL}
	ar rcs $@ $^

${OBJS}	: ${FUNCTION} ${SRCS}
	${CC} ${FLAGS} ${FUNCTION} ${SRCS}

clean :
	rm -f *.o

fclean : clean
	rm -f ${NAME}

re : fclean all
	
