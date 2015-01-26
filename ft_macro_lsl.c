/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_macro_lsl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 15:01:52 by mgras             #+#    #+#             */
/*   Updated: 2015/01/26 17:22:17 by mgras            ###   ########.fr       */
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
	free(lsl);
	return (all);
}

void	ft_file_lsl(t_lsl *dirs, char *name)
{
	struct stat	ss;

	lstat(name, &ss);
	dirs->mode = ss.st_mode;
	dirs->hardlink = ss.st_nlink;
	dirs->uid = ss.st_uid;
	dirs->gid = ss.st_gid;
	dirs->size = ss.st_size;
	dirs->st_mtimespec = ss.st_mtimespec;
}