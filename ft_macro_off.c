/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_macro_off.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 15:53:43 by mgras             #+#    #+#             */
/*   Updated: 2015/02/09 10:56:21 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_off(t_off *off, t_dirs *tmp)
{
	if (off->link < get_nlink_off(tmp->lsl->hardlink))
		off->link = get_nlink_off(tmp->lsl->hardlink);
	if (off->uid < get_uid_off(tmp->lsl->uid))
		off->uid = get_uid_off(tmp->lsl->uid);
	if (off->gid < get_gid_off(tmp->lsl->gid))
		off->gid = get_gid_off(tmp->lsl->gid);
	if (off->size < get_size_off(tmp->lsl->size))
		off->size = get_size_off(tmp->lsl->size);
	if (S_ISBLK(tmp->lsl->mode) || S_ISCHR(tmp->lsl->mode))
		if (off->size < get_dev_off(tmp->lsl))
			off->size = get_dev_off(tmp->lsl);
}

void	ft_fill_off_file(t_off *off, t_dirs *dirs, t_op *ops)
{
	t_dirs	*tmp;

	tmp = dirs;
	while (tmp != NULL)
	{
		if (tmp->file == 1 && ops->a == 1)
			ft_off(off, tmp);
		else if (tmp->file == 1 && ft_hidden(ft_end(tmp->name)) == 0)
			ft_off(off, tmp);
		tmp = tmp->next;
	}
}

void	ft_fill_off_all(t_off *off, t_dirs *dirs, t_op *ops)
{
	t_dirs	*tmp;

	tmp = dirs;
	while (tmp != NULL)
	{
		if (ops->a == 1)
			ft_off(off, tmp);
		else if (ft_hidden(ft_end(tmp->name)) == 0)
			ft_off(off, tmp);
		tmp = tmp->next;
	}
}

void	ft_init_off(t_off *off)
{
	off->link = 0;
	off->uid = 0;
	off->gid = 0;
	off->size = 0;
}
