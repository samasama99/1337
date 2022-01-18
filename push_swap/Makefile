# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 12:20:38 by orahmoun          #+#    #+#              #
#    Updated: 2022/01/11 16:02:10 by orahmoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_SRC = push_swap.c

NAME_OBJ = push_swap.o

BONUS = checker

BONUS_SRC = checker.c \
			checker_utils.c

HEADER = header.h

LIBFT = libft/libft.a

MAKE_LIBFT = libft/

SRC = vector.c \
	  moves.c \
	  moves2.c \
	  sorting.c \
	  sort_small_number.c \
	  is_sorted.c \
	  sorting_utils.c \
	  extra_utils.c \
	  extra_utils_2.c \
	  parse.c \
	  longest_sequence.c \
	  str_append.c \
	  get_next_line.c \
	  moves_utils.c

SRC_OBJ = ${SRC:%c=%o} 

BONUS_OBJ = ${BONUS_SRC:%.c=%.o}

CC = cc

FLAGS = -Wall -Wextra -Werror

all : ${NAME}

${LIBFT} :
	make -C ${MAKE_LIBFT}

${NAME} : ${NAME_OBJ} ${SRC_OBJ} ${LIBFT}
	${CC} ${FLAGS} $^ -o ${NAME}

debug : ${NAME_SRC} ${SRC} 
	${CC} ${FLAGS} -g $^ libft/*.c -o ${NAME}

bonus : ${BONUS_OBJ} ${SRC_OBJ} ${LIBFT}
	${CC} ${FLAGS} $^ -o ${BONUS}

%.o : %.c ${HEADER}
	${CC} ${FLAGS} -c $<

clean :
	rm -f ${SRC_OBJ} ${NAME_OBJ}
	rm -f ${BONUS_OBJ}
	@make clean -C ${MAKE_LIBFT}

fclean : clean
	rm -f ${NAME}
	rm -f ${BONUS}
	@make fclean -C ${MAKE_LIBFT}

re : fclean all

.PHONY : clean fclean all re
