# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 17:52:43 by orahmoun          #+#    #+#              #
#    Updated: 2022/01/04 14:58:38 by orahmoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

FLAGS = -Wall -Wextra -Werror 

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

NAME_SRC = mandatory/so_long.c

B_NAME_SRC = bonus/so_long_bonus.c

HEADER = mandatory/header.h

B_HEADER = bonus/header_bonus.h

SRC =		mandatory/utils/check_ber.c \
			mandatory/utils/check_collision.c \
			mandatory/utils/check_map.c \
			mandatory/utils/draw.c \
			mandatory/utils/draw_utils.c \
			mandatory/utils/handling_events.c \
			mandatory/utils/init.c \
			mandatory/utils/parse_map.c

B_SRC =		bonus/utils/check_ber_bonus.c \
			bonus/utils/check_collision_bonus.c \
			bonus/utils/check_map_bonus.c \
			bonus/utils/draw_bonus.c \
			bonus/utils/draw_utils2_bonus.c \
			bonus/utils/draw_utils_bonus.c \
			bonus/utils/handling_events_bonus.c \
			bonus/utils/init_bonus.c \
			bonus/utils/parse_map_bonus.c \
			bonus/utils/player_move_bonus.c \
			bonus/utils/skel_move_bonus.c

G_SRC =		mandatory/g_utils/ft_itoa.c \
			mandatory/g_utils/ft_strlen.c \
			mandatory/g_utils/ft_join_strings.c \
			mandatory/g_utils/ft_realloc.c \
			mandatory/g_utils/ft_strchr.c \
			mandatory/g_utils/ft_strcmp.c \
			mandatory/g_utils/ft_strdup.c \
			mandatory/g_utils/ft_strjoin.c \
			mandatory/g_utils/ft_strlen_remove_newline.c \
			mandatory/g_utils/ft_substr.c \
			mandatory/g_utils/get_next_line.c 

B_G_SRC = 	bonus/g_utils//ft_strlen.c \
			bonus/g_utils/ft_itoa.c \
			bonus/g_utils/ft_join_strings.c \
			bonus/g_utils/ft_realloc.c \
			bonus/g_utils/ft_strchr.c \
			bonus/g_utils/ft_strcmp.c \
			bonus/g_utils/ft_strdup.c \
			bonus/g_utils/ft_strjoin.c \
			bonus/g_utils/ft_strlen_remove_newline.c \
			bonus/g_utils/ft_substr.c \
			bonus/g_utils/get_next_line.c 

OBJDIR = obj

NAME_OBJ =  $(addprefix ${OBJDIR}/, ${NAME_SRC:so_long.c=so_long.o})

B_NAME_OBJ =  $(addprefix ${OBJDIR}/, ${B_NAME_SRC:so_long_bonus.c=so_long_bonus.o})

OBJ = $(addprefix ${OBJDIR}/, ${SRC:%.c=%.o})

B_OBJ = $(addprefix ${OBJDIR}/, ${B_SRC:%.c=%.o})

G_OBJ = $(addprefix ${OBJDIR}/, ${G_SRC:%.c=%.o})

B_G_OBJ = $(addprefix ${OBJDIR}/, ${B_G_SRC:%.c=%.o})

all : ${NAME}

bonus : bonus_binary ${B_HEADER}

bonus_binary : ${B_NAME_OBJ} ${B_OBJ} ${B_G_OBJ}
	${CC} ${FLAGS} ${MLX_FLAGS} $^ -o ${NAME}

${NAME} : ${NAME_OBJ} ${OBJ} ${G_OBJ}
	${CC} ${FLAGS} ${MLX_FLAGS} $^ -o ${NAME}

$(OBJDIR)/%.o : %.c
	@mkdir -p $(dir $@)
	${CC} ${FLAGS} -c $< -o $@

clean : 
	rm -f ${NAME_OBJ} ${OBJ} ${G_OBJ}

fclean : clean
	rm -f ${NAME}
	rm -rf ${OBJDIR}

re : fclean all

.PHONY : bonus clean fclean all
