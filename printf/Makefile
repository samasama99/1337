NAME	=	libftprintf.a

FUNCTION = ft_printf.c

SRCS	=	utils/ft_putchar_fd.c \
			utils/ft_putnbr_base.c \
			utils/ft_putnbr_fd.c \
			utils/ft_putstr_fd.c \
			utils/ft_strlen.c	

OBJS	=	${SRCS:utils/%.c=%.o}

OBJS_FUN	=	${FUNCTION:.c=.o}

INCL	=	includes/ft_printf.h

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror -c

all : ${NAME}

${NAME} : ${INCL} ${OBJS_FUN} ${OBJS} 
	ar rcs $@ $^

${OBJS}	: ${SRCS}
	${CC} ${FLAGS} ${SRCS}

${OBJS_FUN}	: ${FUNCTION}
	${CC} ${FLAGS} ${FUNCTION}

clean :
	rm -f *.o

fclean : clean
	rm -f ${NAME}

re : fclean all
	
