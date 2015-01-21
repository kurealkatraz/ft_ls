/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_macro_lsl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 15:01:52 by mgras             #+#    #+#             */
/*   Updated: 2015/01/21 11:19:01 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_all	*ft_get_lsl(t_all *all, char *path)
{
	struct stat ss;
	t_lsl		*lsl;

	lsl = (t_lsl*)malloc(sizeof(t_lsl));
	lstat(path, &ss);
	all->blocks = ss.st_blocks;
	lsl->mode = ss.st_mode;
	lsl->hardlink = ss.st_nlink;
	lsl->uid = ss.st_uid;
	lsl->gid = ss.st_gid;
	lsl->size = ss.st_size;
	lsl->st_mtimespec = ss.st_mtimespec;
	all->lsl = lsl;
	return (all);
}
