
MAKE = make
FLAGS = -Wall -Wextra -Werror
SRCS = printf.h final_putstr.c ints.c sw_additional.c sw_o_flag.c sw_p_flag.c sw_s_flag.c sw_x_flag.c ./libft/libft.a
OBJS = $(SRCS:.c=.o)
LIBFT = ./libft/libft.a
all: $(NAME)

$(NAME): $(LIBFT)
	@gcc -c $(SRCS) $(FLAGS)

g:
	@gcc -g $(SRCS) -o $(NAME)

clean:
	$(MAKE) -C ./libft clean

fclean: clean
	rm -f $(NAME)
	rm -f ./libft/libft.a

re: fclean all

$(LIBFT):
	$(MAKE) -C ./libft all