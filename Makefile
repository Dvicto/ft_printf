NAME = libftprintf.a
SRC = ./final_putstr.c ./sw_i_flag.c ./ft_printf.c ./prntf2.c ./prntf3.c ./sw_additional.c \
./sw_o_flag.c ./sw_p_flag.c ./sw_s_flag.c ./sw_x_flag.c 
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME):
	make -C libft
	cp libft/libft.a libftprintf.a
	gcc  -c $(SRC) -I ft_printf.h -I libft/libft.h
	ar -rc $(NAME) $(OBJ)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

clean:
	make -C libft clean
	rm -f $(OBJ)

re: fclean all