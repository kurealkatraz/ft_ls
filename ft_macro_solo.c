/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_macro_solo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 16:52:24 by mgras             #+#    #+#             */
/*   Updated: 2015/02/09 10:54:21 by mgras            ###   ########.fr       */
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
	ft_fill_off_all(off, nins, ops);
	ft_core_sorting(nins, ops);
	return (nins);
}

t_dirs	*ft_solo_init(t_dirs *dirs, t_op *ops, int head)
{
	t_dirs			*tmp;
	t_off			*off;

	if (dirs->file == 0)
	{
		off = (t_off*)malloc(sizeof(t_off));
		ft_init_off(off);
		if (dirs->file < 1)
			tmp = ft_solo_inst(dirs, ops, off);
		if (head == 1)
			ft_print_head(dirs->name, tmp, ops);
		else if (ops->l == 1)
			ft_print_total(tmp);
		while (tmp != NULL)
		{
			if (ops->a == 1)
				ft_print_file(ops, tmp->lsl, tmp, off);
			else if (ft_hidden(ft_end(tmp->name)) == 0)
				ft_print_file(ops, tmp->lsl, tmp, off);
			tmp = tmp->next;
		}
	}
	return (dirs->next);
}
