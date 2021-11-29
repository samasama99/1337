NAME	=	libftprintf.a

SRCS	=	libftprintf.c utils/*.c

OBJS	=	${SRCS:.c:.o}

INCL	=	*/*.h

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

LIBFT_PATH	=	libft

LIBFT_LIB	=	libft/libft.a

all : ${NAME}

${NAME} : ${OBJS} ${LIBFT_LIB} ${INCL}
	ar rcs $@ $^

${LIBFT_LIB} : 
	cd ${LIBFT_PATH} && Make && make clean && cd ..

clean :
	rm *.o */*.o

fclean : clean
	rm ${NAME}

re : fclean all
	
