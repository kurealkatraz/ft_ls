/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mecha_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 13:40:54 by mgras             #+#    #+#             */
/*   Updated: 2015/01/12 17:02:10 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_fetch_local(t_all *all, t_op *ops)
{
	DIR				*cont;
	struct dirent	*in;

	cont = opendir(".");
	if (cont != NULL)
	{
		while ((in = readdir(cont)) != NULL)
		{
			all = ft_new_local_next(all, in->d_name);
			if (ops->l == 1)
				all = ft_get_lsl(all, all->file_name);
			if (all->next != NULL)
				all = all->next;
		}
	}
}

void	ft_fetch_dirs(t_all *all, t_dirs *dirs, t_op *ops)
{
	DIR				*cont;
	struct dirent	*in;

	while (dirs != NULL)
	{
		cont = opendir(dirs->name);
		if (cont != NULL)
		{
			while ((in = readdir(cont)) != NULL)
			{
				all = ft_new_fina_next(all, in->d_name, dirs);
				if (ops->l == 1)
					all = ft_get_lsl(all, all->file_name);
				if (all->next != NULL)
					all = all->next;
			}
			closedir(cont);
		}
		dirs = dirs->next;
	}
}

void	ft_get_all(t_all *all, t_dirs *dirs, t_op *ops)
{
	if (dirs->name == NULL)
		ft_fetch_local(all, ops);
	else
		ft_fetch_dirs(all, dirs, ops);
}

void	ft_mecha_init(int argc, char **argv, t_op *ops, t_dirs *dirs)
{
	t_all	*all;

	if (ops->R == 1 && argv && argc)
		ft_get_recursive(dirs);
	all = (t_all*)malloc(sizeof(t_all));
	ft_get_all(all, dirs, ops);
}