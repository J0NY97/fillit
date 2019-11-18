# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/07 14:25:24 by jsalmi            #+#    #+#              #
#    Updated: 2019/11/14 13:44:23 by jsalmi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS = ./*.c
OBJS = yes
INCLUDES = ./libft/libft.a
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(FLAGS) $(SRCS) $(INCLUDES)

clean:
	/bin/rm -f $(NAME)

fclean: clean
	/bin/rm -f $(OBJS)

re: clean all

.PHONY: clean all re fclean
