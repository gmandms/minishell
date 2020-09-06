NAME = minishell

SRC = *.c

LIB = FT_PRINTF/libftprintf.a

all: $(NAME)


$(NAME):
	gcc $(SRC) $(LIB) -o $(NAME)

re:
	rm $(NAME)
	gcc $(SRC) $(LIB) -o $(NAME)

