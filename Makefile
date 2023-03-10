# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 23:46:21 by bbenidar          #+#    #+#              #
#    Updated: 2023/03/10 17:49:43 by bbenidar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

CC = cc
FLAGS = -Wall -Wextra -Werror -g

SRC = main.c ft_check.c ft_sort_onehunder.c short_sort.c sorting_five.c \
parcing.c swapers.c util.c ft_sort_fivehndr.c

OBJ = ${SRC:.c=.o}

FT_LIB = ./libft/libft.a

%.o : %.c push_swap.h
	${CC} ${FLAGS} -c $<

${NAME} : ${OBJ} $(FT_LIB)
	ar -rc ${NAME} ${OBJ}
	${CC} ${FLAGS} ${NAME} $(FT_LIB) -o push_swap

$(FT_LIB) :
	make -C ./libft

all : ${NAME}

fclean : clean
	rm -rf ${NAME}
	make fclean -C ./libft

clean : 
	rm -rf ${OBJ}
	make clean -C ./libft

re : fclean all