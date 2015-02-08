# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgras <mgras@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/19 10:44:57 by mgras             #+#    #+#              #
#    Updated: 2015/02/08 17:18:14 by mgras            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

C_FILES =	ft_macro_r.c\
			ft_macro_solo.c\
			ft_macro_off.c\
			ft_mecha_swap.c\
			ft_core.c\
			ft_macro_lsl.c\
			ft_macro_dirs.c\
			ft_macro_ops.c\
			ft_mecha_init.c\
			ft_print_error.c\
			ft_utility.c\
			ft_utility_2.c\
			ft_utility_3.c\
			ft_utility_4.c\
			ft_sorting.c\
			ft_print.c\
			ft_putst.c\
			ft_putst_2.c\
			ft_get_offset.c

O_FILES =	ft_macro_r.o\
			ft_macro_solo.o\
			ft_macro_off.o\
			ft_mecha_swap.o\
			ft_core.o\
			ft_macro_lsl.o\
			ft_macro_dirs.o\
			ft_macro_ops.o\
			ft_mecha_init.o\
			ft_print_error.o\
			ft_utility.o\
			ft_utility_2.o\
			ft_utility_3.o\
			ft_utility_4.o\
			ft_sorting.o\
			ft_print.o\
			ft_putst.o\
			ft_putst_2.o\
			ft_get_offset.o

NAME =		ft_ls

COMPI =		gcc

FLAGS =		-Wall -Werror -Wextra

$(NAME) : o_comp c_comp

o_comp :
	$(COMPI) $(FLAGS) -c $(C_FILES)

c_comp :
	$(COMPI) $(FLAGS) $(O_FILES) -o $(NAME)

clean :
	rm -rf $(O_FILES)

fclean : clean
	rm -rf $(NAME)

re : fclean o_comp c_comp