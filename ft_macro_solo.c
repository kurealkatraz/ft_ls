/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_macro_solo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 16:52:24 by mgras             #+#    #+#             */
/*   Updated: 2015/02/03 17:34:12 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dirs	*ft_solo_inst(t_dirs *dirs, t_op *ops, t_off *off)
{
	DIR				*cont;
	struct dirent	*in;
	t_dirs			*nins;
	t_dirs			*tmp;

	cont = opendir(dirs->name);
	in = readdir(cont);
	nins = (t_dirs*)malloc(sizeof(t_dirs));
	nins = ft_init_napa_chain(in->d_name, dirs->name);
	tmp = nins;
	while ((in = readdir(cont)) != NULL)
		nins = ft_new_napa_next(nins, in->d_name, dirs->name);
	closedir(cont);
	nins = tmp;
	while (tmp != NULL)
	{
		tmp->lsl = (t_lsl*)malloc(sizeof(t_lsl));
		ft_file_lsl(tmp->lsl, tmp->name);
		tmp = tmp->next;
	}
	ft_fill_off_all(off, nins);
	ft_core_sorting(nins, ops);
	return (nins);
}

void	ft_solo_init(t_dirs *dirs, t_op *ops)
{
	t_dirs			*tmp;
	t_off			*off;

	off = (t_off*)malloc(sizeof(t_off));
	ft_init_off(off);
	if (dirs->file < 1)
		tmp = ft_solo_inst(dirs, ops, off);
	while (tmp != NULL)
	{
		if (ops->a == 1)
			ft_print_file(ops, tmp->lsl, tmp, off);
		else if (ft_hidden(ft_end(tmp->name)) == 0)
			ft_print_file(ops, tmp->lsl, tmp, off);
		tmp = tmp->next;
	}
}
