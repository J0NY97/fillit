# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/07 14:25:24 by jsalmi            #+#    #+#              #
#    Updated: 2019/11/28 10:40:27 by nneronin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS = ./insertblocktomap.c\
	   ./main.c\
	   ./recursion_solver.c\
	   ./arraymaker.c\
	   ./get_next_line.c\
	   ./validitychecks.c\
	   ./char_delet.c\
	   ./help.c\
	   ./getxandy.c
OBJS = ./*.o
INCLUDES = ./libft/libft.a
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C libft/
	gcc -o $(NAME) $(FLAGS) $(SRCS) $(INCLUDES)

clean:
	/bin/rm -f $(OBJS)
	make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean

re: fclean all

.PHONY: clean, all, re, fclean
