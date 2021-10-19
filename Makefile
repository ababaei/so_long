# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ababaei <ababaei@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/05 01:57:11 by ababaei           #+#    #+#              #
#    Updated: 2021/10/12 20:58:41 by ababaei          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

SOLONG_SRC = main.c \
			 parser.c \
			 checker.c \
			 controls.c \
			 renderer.c \
			 utils.c \
			 game_loop.c \
			 texture.c \
			 clean_exit.c

SOLONG_OBJ = $(SOLONG_SRC:.c=.o)

DIROBJ = objs/

DIROBJS = $(addprefix $(DIROBJ), $(SOLONG_OBJ))

FLAGS = -Wall -g -Wextra -Werror
NAME = so_long

all:MLX LIBFT $(NAME)

MLX:
	@echo making mlx
	@make -C mlx/

LIBFT:
	@echo making libft
	@make -C libft/ 

$(DIROBJ)%.o: %.c
	@mkdir -p $(DIROBJ)
	@echo compiling: $<
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME):$(DIROBJS)
	@echo Creating executable $(NAME)	
	@$(CC) $(DIROBJ)*.o $(FLAGS) -Llibft/ -lft -Lmlx/ -lmlx_Linux -lX11 -lXext -o $(NAME)

clean:
	rm -rf $(DIROBJ)

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean
	make -C mlx/ clean

re: fclean all

.PHONY: all clean fclean re LIBFT
