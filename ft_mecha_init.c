/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mecha_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 13:40:54 by mgras             #+#    #+#             */
/*   Updated: 2015/02/03 17:30:31 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dirs	*ft_init_r(t_dirs *new_instance, char *d_name, char *name)
{
	new_instance = ft_init_napa_chain(d_name, name);
	new_instance->lsl = (t_lsl*)malloc(sizeof(t_lsl));
	ft_file_lsl(new_instance->lsl, new_instance->name);
	ft_set_file(new_instance);
	return (new_instance);
}

t_dirs	*ft_process_r(t_dirs *dirs, t_dirs *nins, t_dirs *save, t_op *ops)
{
	DIR				*cont;
	struct dirent	*in;

	cont = opendir(dirs->name);
	if (cont != NULL)
	{
		in = readdir(cont);
		save = ft_init_r(nins, in->d_name, dirs->name);
		nins = save;
		while ((in = readdir(cont)) != NULL)
			nins = ft_crea_inst(in->d_name, dirs->name, nins);
		closedir(cont);
		ft_print_head(dirs->name, save, ops);
		ft_process_inst(save, ops);
		while (save != NULL)
		{
			if (save->file != 1)
				ft_get_recursive(save, ops);
			save = save->next;
		}
	}
	else if (cont == NULL && dirs->file != 2)
		ft_error_head(dirs);
	return (save);
}

void	ft_get_recursive(t_dirs *dirs, t_op *ops)
{
	t_dirs			*new_instance;
	t_dirs			*save;

	if (dirs != NULL)
	{
		new_instance = NULL;
		save = NULL;
		save = ft_process_r(dirs, new_instance, save, ops);
	}
}

void	ft_disp_files(t_op *ops, t_dirs *dirs)
{
	t_off	*off;
	t_dirs	*d_tmp;

	off = (t_off*)malloc(sizeof(t_off));
	d_tmp = dirs;
	ft_init_off(off);
	while (d_tmp != NULL)
	{
		d_tmp->lsl = (t_lsl*)malloc(sizeof(t_lsl));
		ft_file_lsl(d_tmp->lsl, d_tmp->name);
		d_tmp = d_tmp->next;
	}
	while (dirs != NULL)
	{
		if (dirs->file == 1)
		{
			if (off->link == 0)
				ft_core_sorting(dirs, ops);
			if (off->link == 0)
				ft_fill_off_file(off, dirs);
			ft_print_file(ops, dirs->lsl, dirs, off);
		}
		dirs = dirs->next;
	}
	free(off);
}

void	ft_mecha_init(t_op *ops, t_dirs *dirs)
{
	t_dirs	*d_tmp;

	ft_disp_files(ops, dirs);
	d_tmp = dirs;
	while (d_tmp != NULL)
	{
		if (ft_name(d_tmp->name) == 0)
			ft_set_file(d_tmp);
		d_tmp = d_tmp->next;
	}
	if (ops->R == 1)
		while (dirs != NULL)
		{
			ft_get_recursive(dirs, ops);
			dirs = dirs->next;
		}
	else
	{
		while (dirs != NULL)
		{
			ft_solo_init(dirs, ops);
			ft_putchar('\n');
			dirs = dirs->next;
		}
	}
}
