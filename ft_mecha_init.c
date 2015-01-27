/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mecha_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 13:40:54 by mgras             #+#    #+#             */
/*   Updated: 2015/01/27 11:47:50 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_disp_dirs();

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
			if (off->link == 0)
				ft_core_sorting(dirs, ops);
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
	ft_del_files(dirs);
	if (ops->R == 1)
		ft_get_recursive(dirs, ops);
}
