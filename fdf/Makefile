# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mderri <mderri@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/10 02:24:39 by mderri            #+#    #+#              #
#    Updated: 2019/02/10 02:24:41 by mderri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS1 = -Wextra -Wall -Werror -I /usr/local/include -I ./includes
CFLAGS2 = -I ./includes -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
EXEC = fdf

SRC1 = dessinligne.c dessinmap.c readmap.c keyhandle.c move_functions.c lastdraw.c
SRC2 = fdf.c
OBJ = $(SRC1:.c=.o) srcs/libft/*.o
		

all: $(EXEC)

$(EXEC):
	@make -C srcs/libft
	@$(CC)  $(CFLAGS1) -c $(SRC1)
	@$(CC) $(CFLAGS2) $(OBJ) $(SRC2) -o $(EXEC) 
	@echo "\033[0;31m ================================================================================"
	@echo "\033[0;31m|>>>>>>>>>>>>>\033[0;32m{MR.Derri, YOUR PROJECT HAS BEEN COMPILED SUCCESSFULLY}\033[0;31m<<<<<<<<<<<<|"
	@echo "\033[0;31m ================================================================================"
	@mkdir OBJTS
	@mv $(OBJ) OBJTS

clean:
	@rm -rf OBJTS
	@rm -f $(OBJ)
	@echo "\033[0;31m ================================================================================"
	@echo "\033[0;31m|>>>>>>>>>>>>>>\033[0;35m{MR.Derri, YOUR PROJECT HAS BEEN CLEANED SUCCESSFULLY}\033[0;31m<<<<<<<<<<<<|"
	@echo "\033[0;31m ================================================================================"

fclean: clean
		@rm -f $(EXEC)

re: fclean all