/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_macro_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 11:08:26 by mgras             #+#    #+#             */
/*   Updated: 2015/02/09 10:47:30 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dirs	*ft_crea_inst(char *na, char *pa, t_dirs *ins)
{
	ins = ft_new_napa_next(ins, na, pa);
	ins->lsl = (t_lsl*)malloc(sizeof(t_lsl));
	ft_file_lsl(ins->lsl, ins->name);
	ft_set_file(ins);
	return (ins);
}

void	ft_process_inst(t_dirs *ins, t_op *ops)
{
	t_dirs	*d_tmp;
	t_off	*off;

	d_tmp = ins;
	off = (t_off*)malloc(sizeof(t_off));
	ft_init_off(off);
	ft_fill_off_all(off, d_tmp, ops);
	ft_core_sorting(d_tmp, ops);
	while (d_tmp != NULL)
	{
		if (ops->a == 1)
			ft_print_file(ops, d_tmp->lsl, d_tmp, off);
		else if (ft_hidden(ft_end(d_tmp->name)) == 0)
			ft_print_file(ops, d_tmp->lsl, d_tmp, off);
		d_tmp = d_tmp->next;
	}
	free(off);
}
