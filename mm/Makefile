# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 12:20:38 by orahmoun          #+#    #+#              #
#    Updated: 2022/01/07 22:00:42 by orahmoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_SRC = push_swap.c

NAME_OBJ = push_swap.o

HEADER = header.h

LIBFT = libft/libft.a

MAKE_LIBFT = libft/

SRC = vector.c \
	  moves.c \
	  moves2.c \
	  sorting.c \
	  is_sorted.c \
	  sorting_utils.c \
	  print_error.c \
	  parse.c \
	  moves_utils.c

SRC_OBJ = ${SRC:%c=%o} 

CC = cc

FLAGS = -Wall -Wextra -Werror

all : ${NAME}

${LIBFT} :
	make -C ${MAKE_LIBFT}

${NAME} : ${NAME_OBJ} ${SRC_OBJ} ${LIBFT}
	${CC} ${FLAGS} $^ -o ${NAME}

debug : ${NAME_SRC} ${SRC} 
	${CC} ${FLAGS} -g $^ libft/*.c -o ${NAME}

%.o : %.c ${HEADER}
	${CC} ${FLAGS} -c $<

clean :
	rm -f ${SRC_OBJ} ${NAME_OBJ}
	@make clean -C ${MAKE_LIBFT}

fclean : clean
	rm -f ${NAME}
	@make fclean -C ${MAKE_LIBFT}

re : fclean all

.PHONY : clean fclean all re
