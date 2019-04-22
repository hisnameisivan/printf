NAME = libftprintf.a
#NAME = a.out
SRC = dot.c
INCLUDES = printf.h
FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
		@$(MAKE) -C libft
		@gcc $(FLAG) $(SRC) -I.$(INCLUDES) -c
		#gcc $(FLAG) -g $(SRC) libft/libft.a -I.$(INCLUDES)
		@ar rcs $(NAME) printf.o libft/libft.a
clean: # дописать
		#@$(MAKE) -C libft fclean
		@/bin/rm -f rm -f *.o

fclean: clean
		@/bin/rm -f $(NAME) # дописать

re: fclean $(NAME)
