/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mecha_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 13:40:54 by mgras             #+#    #+#             */
/*   Updated: 2015/01/23 14:22:54 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_all	*ft_fetch_all(t_all *a_tmp, t_op *ops, t_dirs *path)
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
}

void	ft_mecha_init(t_op *ops, t_dirs *dirs)
{
	t_all	*all;

	if (ops->R == 1)
		ft_get_recursive(dirs);
	all = (t_all*)malloc(sizeof(t_all));
	all->next = NULL;
	ft_get_all(all, dirs, ops);
	all = all->next;
	ft_core_sorting(all, ops);
	while(dirs != NULL)
	{
		ft_putstr(dirs->name);
		ft_putchar('\n');
		dirs = dirs->next;
	}
	//ft_core_print(all, ops);
	ft_free_all(all, dirs, ops);
}
