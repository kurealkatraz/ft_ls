/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 11:22:27 by mgras             #+#    #+#             */
/*   Updated: 2015/01/28 12:26:37 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_file(t_op *ops, t_lsl *lsl, char *file_name, t_off	*off)
{
	if (ops->l != 1)
		ft_putstr(file_name);
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
	}
	ft_putchar('\n');
}

void	ft_print_head(char *head)
{
	ft_putstr(head);
	ft_putchar(':');
	ft_putchar('\n');
	ft_putchar('\n');
}

void	ft_print(char *path, char *name)
{

}