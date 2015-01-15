/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mecha_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 13:40:54 by mgras             #+#    #+#             */
/*   Updated: 2015/01/15 16:12:44 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_all	*ft_fetch_all(t_all *a_tmp, t_op *ops, t_dirs *path)
{
	DIR				*cont;
	struct dirent	*in;
	//char			*str_lsl;

	if (path->name == NULL)
		cont = opendir(".");
	else
		cont = opendir(path->name);
	if (cont != NULL && ops)
	{
		while ((in = readdir(cont)) != NULL)
		{
			a_tmp = ft_new_fina_next(a_tmp, in->d_name, path->name);
			a_tmp = a_tmp->next;
		}
		closedir(cont);
	}
	return (a_tmp);
}

void	ft_get_all(t_all *all, t_dirs *dirs, t_op *ops)
{
	t_dirs	*d_tmp;
	t_all	*a_tmp;

	a_tmp = all;
	d_tmp = dirs;
	if (d_tmp->name == NULL)
		ft_fetch_all(a_tmp, ops, d_tmp);
	else
	{
		while(d_tmp != NULL)
		{
			a_tmp = ft_fetch_all(a_tmp, ops, d_tmp);
			d_tmp = d_tmp->next;
		}
	}
}

void	ft_mecha_init(int argc, char **argv, t_op *ops, t_dirs *dirs)
{
	t_all	*all;
	t_dirs	*d_tmp;

	d_tmp = dirs;
	if (ops->R == 1 && argv && argc)
		ft_get_recursive(dirs);
	while(d_tmp != NULL)
	{
		ft_putstr(d_tmp->name);
		ft_putchar('\n');
		d_tmp = d_tmp->next;
	}
	all = (t_all*)malloc(sizeof(t_all));
	all->next = NULL;
	ft_get_all(all, dirs, ops);
	all = all->next;
	while (all != NULL)
	{
		ft_putstr(all->path);
		ft_putchar('/');
		ft_putstr(all->file_name);
		ft_putchar('\n');
		all = all->next;
	}
}
