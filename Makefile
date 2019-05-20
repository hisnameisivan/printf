NAME = libftprintf.a
SRC = ft_printf.c \
		char_string.c \
		check_nothing.c \
		compare.c \
		constructor.c \
		convert_8_16.c \
		count_digits.c \
		decimal.c \
		fill_struct.c \
		float_1.c \
		float_2.c \
		pointer_percent.c \
		print_nothing.c \
		specif_modif.c \
		type.c
OBJ = $(SRC:.c=.o)
INCLUDES = ft_printf.h
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

lib:
	make -C ./libft/

$(OBJ): $(SRC)
	gcc $(FLAGS) -c -I.$(INCLUDES) $(SRC)

$(NAME): lib $(OBJ)
	cp ./libft/libft.a $(NAME)
	ar rc $(NAME) $(OBJ)
clean:
	/bin/rm -f $(OBJ)
	make clean -C ./libft/

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C ./libft/

re: fclean all

.PHONY : all, clean, flcean, re
