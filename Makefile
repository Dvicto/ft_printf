NAME = libftprintf.a
SRC = ./final_putstr.c ./sw_i_flag_ll.c ./ft_printf.c ./prntf2.c ./prntf3.c ./sw_additional.c \
./sw_p_flag.c ./sw_s_flag.c ./sw_x_flag.c ./c_flag.c ./sw_arif.c ./sw_f_add1.c \
./sw_f_add2.c ./sw_f_flag.c ./all_lets_go.c \
./sw_0if_zero.c \
./sw_i_flag_l.c \
./sw_i_flag.c \
./sw_u_flag_ll.c \
./sw_o_flag_ll.c \
./sw_o_flag_l.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME):
	make -C libft
	cp libft/libft.a libftprintf.a
	gcc  -c -g $(SRC) -I ft_printf.h -I libft/libft.h
	ar -rc $(NAME) $(OBJ)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

clean:
	make -C libft clean
	rm -f $(OBJ)

re: fclean all