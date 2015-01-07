NAME = ft_ls

C_FILES = ft_core.c  ft_macro_ops.c ft_macro_dirs.c  ft_print_error.c  ft_utility.c

all : fclean compile

clean :
	rm -rf $(NAME)

fclean : clean
	rm -rf $(NAME).dSYM

compile :
	gcc -Wall -Werror -Wextra -g $(C_FILES) -o $(NAME)