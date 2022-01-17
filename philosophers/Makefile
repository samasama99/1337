# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 12:20:38 by orahmoun          #+#    #+#              #
#    Updated: 2022/01/17 18:19:40 by orahmoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

NAME_SRC = main.c

NAME_OBJ = main.o

HEADER = main.h

LIBFT = libft/libft.a

MAKE_LIBFT = libft/

SRC = main.c philo.c utils.c parse.c mutex.c

SRC_OBJ = ${SRC:%c=%o} 

BONUS_OBJ = ${BONUS_SRC:%.c=%.o}

CC = cc

# FLAGS = -Wall -Wextra -Werror

all : ${NAME}

${LIBFT} :
	make -C ${MAKE_LIBFT}

${NAME} : ${NAME_OBJ} ${SRC_OBJ} ${LIBFT}
	${CC} ${FLAGS} $^ -o ${NAME}

# debug : ${NAME_SRC} ${SRC} 
# 	${CC} ${FLAGS} -g $^ libft/*.c -o ${NAME}

# bonus : ${BONUS_OBJ} ${SRC_OBJ} ${LIBFT}
# 	${CC} ${FLAGS} $^ -o ${BONUS}

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
