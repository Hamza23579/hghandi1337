# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hghandi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/11 21:27:25 by hghandi           #+#    #+#              #
#    Updated: 2019/02/11 18:01:26 by mel-jadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAG = -Wall -Wextra -Werror

all:$(NAME)

$(NAME):
	@gcc $(FLAG) -c ./libft/*.c \
	additionnal_functions.c data_structure.c \
	form.c main.c place_tetriminos.c voisins.c
	@gcc *.o $(FLAG) -o $(NAME)

clean:
	@/bin/rm -f *.o

fclean: clean
	@/bin/rm -f fillit

re: fclean all
