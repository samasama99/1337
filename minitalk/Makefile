SERVER = server_dir/server.c

CLIENT = client_dir/client.c

SERVER_NAME = server

CLIENT_NAME = client

INCL = headers/header.h

UTILS = utils/ft_append_char.c \
		utils/ft_atoi.c \
		utils/ft_init_null.c \
		utils/ft_printf.c \
		utils/ft_putchar_fd.c \
		utils/ft_putnbr_fd.c \
		utils/ft_putstr_fd.c \
		utils/ft_strdup.c \
		utils/ft_strlen.c

UTILS_OBJS = ${UTILS:utils/%.c=%.o}

SERVER_OBJ = server.o

CLIENT_OBJ = client.o


GCC = gcc

FLAGS = -Wall -Wextra -Werror

all : ${SERVER_NAME} ${CLIENT_NAME}

${SERVER_NAME} : ${SERVER_OBJ} ${UTILS_OBJS}
	${GCC} ${FLAGS} $^ -o $@

${CLIENT_NAME} : ${CLIENT_OBJ} ${UTILS_OBJS}
	${GCC} ${FLAGS} $^ -o $@

${UTILS_OBJS} : ${UTILS} ${INCL}
	${GCC} ${FLAGS} -c $^

${SERVER_OBJ} : ${SERVER} ${INCL}
	${GCC} ${FLAGS} -c $<

${CLIENT_OBJ} : ${CLIENT} ${INCL}
	${GCC} ${FLAGS} -c $<

clean :
	rm -f ${UTILS_OBJS} ${SERVER_OBJ} ${CLIENT_OBJ}

fclean : clean
	rm -f ${SERVER_NAME} ${CLIENT_NAME} 

re : fclean all

.PHONY : clean fclean all re
