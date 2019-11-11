# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvictor <dvictor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/07 00:15:02 by swedde            #+#    #+#              #
#    Updated: 2019/11/11 20:06:56 by dvictor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Werror -Wextra
NAME = libftprintf.a
SRC = ./final_putstr.c ./sw_i_flag_ll.c ./ft_printf.c ./prntf2.c ./prntf3.c ./sw_additional.c \
./sw_p_flag.c ./sw_s_flag.c \
./sw_x_flag_ll.c \
./sw_x_flag.c \
./sw_x_flag_l.c \
./sw_x_big_flag_ll.c \
./c_flag.c ./sw_arif.c ./sw_f_add1.c \
./sw_f_add2.c ./sw_f_flag.c ./all_lets_go.c ./colors.c\
./sw_0if_zero.c \
./sw_i_flag_l.c \
./sw_i_flag.c \
./sw_u_flag_ll.c \
./sw_o_flag_ll.c \
sw_i_flag_h.c \
sw_i_flag_hh.c \
sw_u_flag.c \
sw_u_flag_h.c \
sw_u_flag_hh.c \
sw_u_flag_l.c \
sw_i_norme_1.c \
sw_i_norme_2.c \
sw_u_add.c \
sw_x_big_add.c \
sw_x_add1.c \
sw_x_add2.c \
sw_if0_o.c \
sw_p_flag_norme.c \
sw_p_flag_norme2.c \
sw_if_zero_o.c \
sw_o_addion.c \
sw_addd.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(SRC)
	make -C libft
	cp libft/libft.a libftprintf.a
	gcc  -c -g $(SRC) -I ft_printf.h -I libft/libft.h
	ar -rc $(NAME) $(OBJ)

fclean: clean
	make -C libft fclean
	rm -f libft/libft.a
	rm -f libft.a
	rm -f libftprintf.a
	rm -f $(NAME)

clean:
	make -C libft clean
	rm -f $(OBJ)

re: fclean all