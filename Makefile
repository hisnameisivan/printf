NAME = libftprintf.a
#NAME = a.out
SRC = ft_printf.c
INCLUDES = ft_printf.h
FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
		@$(MAKE) -C libft
		@gcc $(FLAG) $(SRC) -I.$(INCLUDES) -c
		#gcc $(FLAG) -g $(SRC) libft/libft.a -I.$(INCLUDES)
		@cp libft/libft.a $(NAME)
		@ar rc $(NAME) ft_printf.o
clean: # дописать
		#@$(MAKE) -C libft fclean
		@/bin/rm -f rm -f *.o

fclean: clean
		@/bin/rm -f $(NAME) # дописать

re: fclean $(NAME)
