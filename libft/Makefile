# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddyankov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/09 13:14:30 by ddyankov          #+#    #+#              #
#    Updated: 2023/01/16 14:13:31 by ddyankov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libft.a

SOURCES = *.c

OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Werror -Wextra

$(NAME): all

all:
	@cc $(CFLAGS) -c $(SOURCES)
	@ar rcs $(NAME) $(OBJECTS)

clean:
	@/bin/rm -f $(OBJECTS)
fclean: clean
	@/bin/rm -f $(NAME)
re: fclean all
