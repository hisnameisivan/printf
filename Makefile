NAME = libftprintf.a
OBJ = ft_printf.o
INCLUDES = ft_printf.h
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(OBJ): %.o : %.c
		make -C libft
		gcc $(FLAGS) -c -I.$(INCLUDES) $< -o $@

$(NAME): $(OBJ)
		cp libft/libft.a $(NAME)
		ar rc $(NAME) $(OBJ)
clean:
		/bin/rm -f $(OBJ)
		make clean -C ./libft/

fclean: clean
		/bin/rm -f $(NAME)
		make fclean -C ./libft/

re: fclean all

.PHONY : all, clean, flcean, re
