/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 12:27:06 by nowl              #+#    #+#             */
/*   Updated: 2015/01/12 17:42:18 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_op_error(int index, char err)
{
	if (index == 400)
	{
		ft_putstr("ls: invalid option -- '");
		ft_putchar(err);
		ft_putstr("'\n");
	}
}

void	ft_usr_dirs_err(char *erred_dir)
{
	ft_putstr("ls: ");
	ft_putstr(erred_dir);
	ft_putstr(": No such file or directory\n");
}