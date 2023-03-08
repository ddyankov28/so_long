# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddyankov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 13:02:45 by ddyankov          #+#    #+#              #
#    Updated: 2023/03/08 17:45:10 by ddyankov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = main.c get_map.c convert.c key_events.c move_player.c check_path.c \
		check.c free.c help_move.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g

MLX = -I ./mlx -L ./mlx -lmlx -lXext -lX11

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@make -C mlx
	@make -C libft
	@cc $(CFLAGS) $(OBJ) $(MLX) $(LIBFT) -o so_long

clean:
	@rm -f $(OBJ)
	@make clean -C libft

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

.PHONY:		all clean fclean re
