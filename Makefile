# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgras <mgras@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/19 10:44:57 by mgras             #+#    #+#              #
#    Updated: 2015/01/20 17:05:33 by mgras            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

C_FILES = ft_core.c ft_macro_all.c ft_macro_lsl.c ft_macro_dirs.c ft_macro_ops.c ft_mecha_init.c ft_print_error.c ft_recursive.c ft_utility.c ft_utility_2.c ft_sorting.c ft_print.c ft_putst.c ft_putst_2.c ft_get_offset.c

all : fclean compile

clean :
	rm -rf $(NAME)

fclean : clean
	rm -rf $(NAME).dSYM

compile :
	gcc -Wall -Werror -Wextra -g $(C_FILES) -o $(NAME)