NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

DIRO = obj

DIRS = src

HEADER = header

SRC = char_string.c \
		check_nothing.c \
		compare.c \
		constructor.c \
		convert_8_16.c \
		count_digits.c \
		decimal.c \
		fill_struct.c \
		float_1.c \
		float_2.c \
		ft_printf.c \
		pointer_percent.c \
		print_nothing.c \
		specif_modif.c \
		type.c \

OBJ = *.o

FO = $(addprefix $(DIRO)/, $(OBJ))

OBJPRINT = $(addprefix $(DIRO)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): lib $(OBJPRINT)
	@ar -rc $(NAME) $(FO)
	@ranlib $(NAME)

$(DIRO)/%.o: $(DIRS)/%.c
	gcc $(FLAGS) -I $(HEADER) -o $@ -c $<

lib:
	@make -C libft
	@make copy -C libft

clean:
	make clean -C libft
	rm -rf $(FO)
	rm -rf $(DIRO)

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

re: fclean all
