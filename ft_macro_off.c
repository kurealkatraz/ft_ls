/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_macro_off.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 15:53:43 by mgras             #+#    #+#             */
/*   Updated: 2015/01/28 16:04:39 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_fill_off_file(t_off *off, t_dirs *dirs)
{
	t_dirs	*tmp;

	tmp = dirs;
	while(tmp != NULL)
	{
		if (tmp->file == 1)
		{
			if (off->link < get_nlink_off(tmp->lsl->hardlink))
				off->link = get_nlink_off(tmp->lsl->hardlink);
			if (off->uid < get_uid_off(tmp->lsl->uid))
				off->uid = get_uid_off(tmp->lsl->uid);
			if (off->gid < get_gid_off(tmp->lsl->gid))
				off->gid = get_gid_off(tmp->lsl->gid);
			if (off->size < get_size_off(tmp->lsl->size))
				off->size = get_size_off(tmp->lsl->size);
		}
		tmp = tmp->next;
	}
}

void	ft_fill_off_all(t_off *off, t_dirs *dirs)
{
	t_dirs	*tmp;

	tmp = dirs;
	while(tmp != NULL)
	{
		if (off->link < get_nlink_off(tmp->lsl->hardlink))
			off->link = get_nlink_off(tmp->lsl->hardlink);
		if (off->uid < get_uid_off(tmp->lsl->uid))
			off->uid = get_uid_off(tmp->lsl->uid);
		if (off->gid < get_gid_off(tmp->lsl->gid))
			off->gid = get_gid_off(tmp->lsl->gid);
		if (off->size < get_size_off(tmp->lsl->size))
			off->size = get_size_off(tmp->lsl->size);
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