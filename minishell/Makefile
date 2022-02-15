# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/09 15:08:52 by orahmoun          #+#    #+#              #
#    Updated: 2022/02/09 15:15:43 by orahmoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

NAME_SRC = main.c

NAME_OBJ = main.o

HEADER = main.h

LIBFT = libft/libft.a

MAKE_LIBFT = libft/

SRC = parse_input.c \
	  vector.c

SRC_OBJ = ${SRC:%c=%o} 

CC = cc

FLAGS = -Wall -Wextra -Werror

READLINE = -lreadline

all : ${NAME}

${LIBFT} :
	make -C ${MAKE_LIBFT}

${NAME} : ${NAME_OBJ} ${SRC_OBJ} ${LIBFT}
	${CC} ${FLAGS} ${READLINE} $^ -o ${NAME}

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
