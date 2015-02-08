/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 12:27:06 by nowl              #+#    #+#             */
/*   Updated: 2015/02/06 16:20:04 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_op_error(int index, char err)
{
	if (index == 400)
	{
		ft_putstr_fd("ls: invalid option -");
		ft_putchar_err(err);
		ft_putchar_err('\n');
	}
}

void	ft_usr_dirs_err(char *erred_dir)
{
	ft_putstr_fd("ls: ");
	ft_putstr_fd(erred_dir);
	ft_putstr_fd(": No such file or directory\n");
}

void	ft_forbiden_access(char *erred_dir)
{
	ft_putstr_fd("ls: ");
	ft_putstr_fd(erred_dir);
	ft_putstr_fd(": Forbiden Access\n");
}

void	ft_error_head(t_dirs *dirs)
{
	ft_putchar_err('\n');
	ft_putstr_fd(dirs->name);
	ft_putchar_err(':');
	ft_putchar_err('\n');
	ft_forbiden_access(dirs->name);
}

void	ft_cycle_errors(t_dirs *dirs, int head)
{
	while (dirs != NULL)
	{
		if (dirs->file == 3)
		{
			if (head == 1)
			{
				ft_putchar_err('\n');
				ft_putstr_fd(dirs->name);
				ft_putstr_fd(" :\n");
			}
			ft_forbiden_access(dirs->name);
			if (ft_search_err(dirs) == 0)
				ft_putchar_err('\n');
		}
		dirs = dirs->next;
	}
}
