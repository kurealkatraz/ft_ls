/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mecha_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 13:40:54 by mgras             #+#    #+#             */
/*   Updated: 2015/01/22 20:03:37 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_all	*ft_fetch_all(t_all *a_tmp, t_op *ops, t_dirs *path)
{
	DIR				*cont;
	struct dirent	*in;
	char			*str_lsl;

	cont = opendir(path->name);
	if (cont != NULL)
	{
		while ((in = readdir(cont)) != NULL)
		{
			a_tmp = ft_new_fina_next(a_tmp, in->d_name, path->name);
			if (ops->l == 1 || ops->t == 1)
			{
				str_lsl = (char*)malloc(sizeof(char) *
					(ft_strlen(in->d_name) + ft_strlen(path->name)));
				ft_strclip(path->name, in->d_name, str_lsl);
				ft_get_lsl(a_tmp, str_lsl);
				free(str_lsl);
			}
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
	while (d_tmp->next != NULL)
	{
		a_tmp = ft_fetch_all(a_tmp, ops, d_tmp);
		d_tmp = d_tmp->next;
	}
}

void	ft_mecha_init(int argc, char **argv, t_op *ops, t_dirs *dirs)
{
	t_all	*all;

	if (ops->R == 1 && argv && argc)
		ft_get_recursive(dirs);
	all = (t_all*)malloc(sizeof(t_all));
	all->next = NULL;
	ft_get_all(all, dirs, ops);
	all = all->next;
	ft_core_sorting(all, ops);
	while (all->next != NULL)
	{
		if (all->full)
		{
			ft_putstr(all->full);
			ft_putchar('\n');
		}
		all = all->next;
	}
	//ft_core_print(all, ops);
	ft_free_all(all, dirs, ops);
}
