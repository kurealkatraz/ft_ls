/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 13:48:59 by mgras             #+#    #+#             */
/*   Updated: 2015/01/28 12:38:27 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"



void	ft_get_recursive(t_dirs *dirs)
{
	DIR				*cont;
	struct dirent	*in;
	t_dirs			*save;

	if (dirs != NULL)
	{
		cont = opendir(dirs->name);
		save = dirs->next;
		if (cont != NULL)
		{
			while ((in = readdir(cont)) != NULL)
			{
				if (ft_name(in->d_name) == 0)
					dirs = ft_new_napa_next(dirs, in->d_name);
				if (in->d_type & DT_DIR)
					dirs->file = 0;
				else
					dirs->files = 1;
			}
			closedir(cont);
			dirs->next = save;
			ft_get_recursive(save);
		}
	}
}
