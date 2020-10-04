NAME = minishell

SRC =	cd.c \
		change_env.c \
		create_env.c \
		echo.c \
		find_arg.c \
		impl_cmds.c \
		main.c \
		pwd.c \
		read_cmdline.c \
		run_cmd.c \
		setenv.c \
		size_dac.c \
		source_cd.c \
		source_free.c \
		source_implcmds.c \
		source_myexe.c \
		source_runcmd.c \
		source_runcmd2.c \
		source_runcmd3.c \
		unsetenv.c

OBJ = $(SRC:.c=.o)

LIBD = FT_PRINTF/

LIB = $(LIBD)libftprintf.a

FLGS = -Wall -Wextra -Werror

all: make_lib $(NAME)

make_lib:
	@printf "1. Make printf_lib\n"
	@make -C $(LIBD)

%.o: %.c
	@printf "2. Create OBJ files\n"
	@gcc $(FLGS) -c $< -o $@

$(NAME): $(OBJ)
	@printf "3. Create shell\n"
	@gcc $(FLGS) $(OBJ) $(LIB) -o $(NAME)

clean:
	@printf "clean OBJ files\n clean lib files\n"
	@/bin/rm -f $(OBJ)
	@make -C $(LIBD) fclean

fclean: clean
	@printf "clean minishell\n"
	@/bin/rm -f $(NAME)

re: fclean all
