/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_macro_lsl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 15:01:52 by mgras             #+#    #+#             */
/*   Updated: 2015/02/03 17:22:05 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_file_lsl(t_lsl *dirs, char *name)
{
	struct stat	ss;

	lstat(name, &ss);
	dirs->block = (int)ss.st_blocks;
	dirs->mode = ss.st_mode;
	dirs->hardlink = ss.st_nlink;
	dirs->uid = ss.st_uid;
	dirs->gid = ss.st_gid;
	dirs->size = ss.st_size;
	dirs->st_mtimespec = ss.st_mtimespec;
}
