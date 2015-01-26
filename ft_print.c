/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 11:22:27 by mgras             #+#    #+#             */
/*   Updated: 2015/01/26 16:21:04 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_file(t_op *ops, t_lsl *lsl, char *file_name, t_off	*off)
{
	if (ops->l != 1)
	{
		ft_putstr(file_name);
		ft_putchar('\n');
	}
	else
	{
		ft_put_st_mode(lsl->mode);
		ft_put_restrict(lsl->mode);
		ft_put_st_nlinks(lsl->hardlink, off->link);
		ft_put_uid(lsl->uid, off->uid);
		ft_put_gid(lsl->gid, off->gid);
		ft_put_size(lsl->size, off->size);
		ft_put_modtime(lsl->st_mtimespec);
		ft_putstr(file_name);
		ft_putstr("\n");
	}
}
