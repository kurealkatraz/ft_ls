/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 13:48:59 by mgras             #+#    #+#             */
/*   Updated: 2015/01/23 14:21:41 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_name(char *str)
{
	if (ft_strlen(str) == 2)
	{
		if (str[0] == '.' && str[1] == '.' && str[2] == '\0')
			return (1);
	}
	else if (ft_strlen(str) == 1)
	{
		if (str[0] == '.' && str[1] == '\0')
			return (1);
	}
	return (0);
}

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
				if (ft_name(in->d_name) == 0 && in->d_type & DT_DIR)
					dirs = ft_new_napa_next(dirs, in->d_name);
				closedir(cont);
			}
			dirs->next = save;
			ft_get_recursive(save);
		}
	}
}
