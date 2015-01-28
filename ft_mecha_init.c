/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mecha_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 13:40:54 by mgras             #+#    #+#             */
/*   Updated: 2015/01/28 17:41:54 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dirs	*ft_crea_inst(char *na, unsigned char ty, char *pa, t_dirs *ins)
{
	ins = ft_new_napa_next(ins, na, pa);
	ft_set_file(ins, ty);
	ins->lsl = (t_lsl*)malloc(sizeof(t_lsl));
	ft_file_lsl(ins->lsl, ins->name);
	return (ins);
}

void	ft_process_inst(t_dirs *ins, t_op *ops)
{
	t_dirs	*d_tmp;
	t_off	*off;

	d_tmp = ins;
	off = (t_off*)malloc(sizeof(t_off));
	ft_init_off(off);
	ft_core_sorting(d_tmp, ops);
	if (ops->l == 1)
		ft_fill_off_all(off, d_tmp);
	while (d_tmp != NULL)
	{
		ft_print_file(ops, d_tmp->lsl, ft_end(d_tmp->name), off);
		d_tmp = d_tmp->next;
	}
	free(off);
}

void	ft_get_recursive(t_dirs *dirs, t_op *ops)
{
	DIR				*cont;
	struct dirent	*in;
	t_dirs			*new_instance;
	t_dirs			*save;

	while (dirs != NULL)
	{
		ft_print_head(dirs->name);
		cont = opendir(dirs->name);
		in = readdir(cont);
		new_instance = ft_init_napa_chain(in->d_name, dirs->name);
		ft_set_file(new_instance, in->d_type);
		new_instance->lsl = (t_lsl*)malloc(sizeof(t_lsl));
		ft_file_lsl(new_instance->lsl, new_instance->name);
		save = new_instance;
		while((in = readdir(cont)) != NULL)
			new_instance = ft_crea_inst(in->d_name, in->d_type, dirs->name, new_instance);
		closedir(cont);
		ft_process_inst(save, ops);
		save = ft_del_files(save, save->next);
		if (save != NULL)
		ft_get_recursive(save, ops);
		dirs = dirs->next;
	}
}

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
				ft_fill_off_file(off, dirs);
			ft_print_file(ops, dirs->lsl, dirs->name, off);
		}
		dirs = dirs->next;
	}
	free(off);
}

void	ft_mecha_init(t_op *ops, t_dirs *dirs)
{
	ft_disp_files(ops, dirs);
	dirs = ft_del_files(dirs, dirs->next);
	if (ops->R == 1)
		ft_get_recursive(dirs, ops);
}
