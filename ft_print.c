/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 11:22:27 by mgras             #+#    #+#             */
/*   Updated: 2015/02/05 14:38:16 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_file(t_op *ops, t_lsl *lsl, t_dirs *dirs, t_off *off)
{
	char	buff[256];
	t_dirs	*d_tmp;

	d_tmp = dirs;
	if (ops->l == 1)
	{
		ft_put_st_mode(lsl->mode);
		ft_put_restrict(lsl->mode);
		ft_put_st_nlinks(lsl->hardlink, off->link);
		ft_put_uid(lsl->uid, off->uid);
		ft_put_gid(lsl->gid, off->gid);
		ft_put_size(lsl->size, off->size);
		ft_put_modtime(lsl->st_mtimespec);
	}
	ft_putstr(ft_end(d_tmp->name));
	if (S_ISLNK(lsl->mode) && ops->l == 1)
	{
		ft_blank_out(buff, 256);
		ft_putstr(" -> ");
		readlink(d_tmp->name, buff, 256);
		ft_putstr(buff);
	}
	ft_putchar('\n');
}

void	ft_print_head(char *head, t_dirs *dirs, t_op *ops)
{
	int		total;
	t_dirs	*d_tmp;

	d_tmp = dirs;
	total = 0;
	ft_putchar('\n');
	ft_putstr(head);
	ft_putchar(':');
	ft_putchar('\n');
	if (ops->l == 1)
	{
		while (d_tmp != NULL)
		{
			total = total + d_tmp->lsl->block;
			d_tmp = d_tmp->next;
		}
		ft_putstr("total ");
		ft_putnbr(total);
		ft_putchar('\n');
	}
}

void	ft_print_total(t_dirs *dirs)
{
	t_dirs		*d_tmp;
	int			total;

	total = 0;
	d_tmp = dirs;
	while (d_tmp != NULL)
	{
		total = total + d_tmp->lsl->block;
		d_tmp = d_tmp->next;
	}
	ft_putstr("total ");
	ft_putnbr(total);
	ft_putchar('\n');
}
