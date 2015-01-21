/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 13:48:59 by mgras             #+#    #+#             */
/*   Updated: 2015/01/21 12:23:20 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_check_dir_name(char *str)
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
	t_dirs			*tmp;
	t_dirs			*save;
	struct dirent	*in;

	tmp = dirs;
	save = tmp;
	while (tmp != NULL)
	{
		cont = opendir (tmp->name);
		if (cont != NULL)
		{
			save = tmp;
			while ((in = readdir(cont)) != NULL)
				if (ft_check_dir_name(in->d_name) == 0 &&
					in->d_type == DT_DIR)
					tmp = ft_new_napa_next(tmp, in->d_name);
		}
		else
			tmp = ft_del_curr(save, tmp);
		tmp = save;
		tmp = tmp->next;
		if (cont != NULL)
			closedir(cont);
	}
}
