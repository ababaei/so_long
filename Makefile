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

all:LIBFT $(NAME)

LIBFT:
	@echo making libft
	@make -C libft/ 

$(DIROBJ)%.o: %.c
	@mkdir -p $(DIROBJ)
	@echo compiling: $<
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME):$(DIROBJS)
	@echo Creating executable $(NAME)	
	@$(CC) $(DIROBJ)*.o $(FLAGS) -Llibft/ -lft -lX11 -lXext -lmlx -o $(NAME)

clean:
	rm -rf $(DIROBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re LIBFT
