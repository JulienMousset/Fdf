# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmousset <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/12 10:12:56 by jmousset          #+#    #+#              #
#    Updated: 2019/09/13 18:46:37 by jmousset         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Wextra -Werror

SRCS = main.c\
	   fdf.c\
	   parsing.c\
	   draw_parallel.c\
	   draw_iso.c\
	   draw_line.c\
	   events_1.c\
	   events_2.c\
	   events_3.c\
	   colors.c

HDR = fdf.h

LIB_PATH = ./libft/

LIB = ./libft/libft.a

MLX_PATH = ./minilibx/

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	make -C $(LIB_PATH)
	gcc $(FLAGS) -c $(SRCS) -I $(HDR)
	gcc $(FLAGS) $(OBJS) -o $(NAME) $(LIB) -L $(MLX_PATH) $(MLX_FLAGS)

clean:
	rm -f $(OBJS)
	make clean -C $(LIB_PATH)
	make clean -C $(MLX_PATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIB_PATH)

re: fclean all

.PHONY: all clean fclean re
