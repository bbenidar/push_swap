# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 23:46:21 by bbenidar          #+#    #+#              #
#    Updated: 2023/03/13 02:35:17 by bbenidar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

NAME_BNS=checker

CC = cc
FLAGS = -g

SRC = main.c ft_check.c ft_sort_onehunder.c short_sort.c sorting_five.c \
parcing.c parcing2.c swapers.c swapers_2.c swapers_3.c util.c ft_sort_fivehndr.c\

SRC_B = parcing.c sorting_five.c ft_check.c short_sort.c parcing2.c swapers.c swapers_2.c swapers_3.c util.c \
bonus/checker.c bonus/get_next_line/get_next_line.c bonus/get_next_line/get_next_line_utils.c \

OBJ = ${SRC:.c=.o}

OBJ_b = ${SRC_B:.c=.o}

FT_LIB = ./libft/libft.a
   
all : ${NAME}

${NAME} : ${OBJ} $(FT_LIB)
	ar -rc ${NAME} ${OBJ}
	${CC} ${FLAGS} ${NAME} $(FT_LIB) -o push_swap

manda/%.o : manda/%.c push_swap.h ./bonus/get_next_line/get_next_line.h
	${CC} ${FLAGS} -c $<

bonus/%.o : bonus/%.c push_swap.h ./bonus/get_next_line/get_next_line.h
	${CC} ${FLAGS} -c $< -o $@

$(FT_LIB) :
	make -C ./libft


bonus: $(OBJ_b) $(FT_LIB)
		${CC} $(OBJ_b) $(FT_LIB) -o checker
		
fclean : clean
	rm -rf ${NAME} push_swap checker
	make fclean -C ./libft

clean : 
	rm -rf ${OBJ} ${OBJ_b}
	make clean -C ./libft

re : fclean all