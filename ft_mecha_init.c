/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mecha_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 13:40:54 by mgras             #+#    #+#             */
/*   Updated: 2015/01/26 17:30:49 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*t_all	*ft_fetch_all(t_all *a_tmp, t_op *ops, t_dirs *path)
{
	DIR				*cont;
	struct dirent	*in;

	cont = opendir(path->name);
	if (cont != NULL)
	{
		while ((in = readdir(cont)) != NULL)
		{
			a_tmp = ft_new_fina_next(a_tmp, in->d_name, path->name);
			a_tmp = a_tmp->next;
			if (ops->l == 1 || ops->t == 1)
				ft_get_lsl(a_tmp, a_tmp->full);
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
	while (d_tmp != NULL)
	{
		a_tmp = ft_fetch_all(a_tmp, ops, d_tmp);
		d_tmp = d_tmp->next;
	}
}*/

void	ft_disp_files(t_op *ops, t_dirs *dirs)
{
	t_off	*off;
	t_dirs	*d_tmp;

	off = (t_off*)malloc(sizeof(t_off));
	d_tmp = dirs;
	ft_init_off(off);
	while (dirs != NULL)
	{
		if (dirs->file == 1)
		{
			while (d_tmp != NULL)
			{
				d_tmp->lsl = (t_lsl*)malloc(sizeof(t_lsl));
				ft_file_lsl(d_tmp->lsl, d_tmp->name);
				d_tmp = d_tmp->next;
			}
			if (off->link == 0 && ops->l == 1)
				ft_fill_off(off, dirs);
			ft_print_file(ops, dirs->lsl, dirs->name, off);
		}
		dirs = dirs->next;
	}
}

void	ft_mecha_init(t_op *ops, t_dirs *dirs)
{
	ft_disp_files(ops, dirs);
}
