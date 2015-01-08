/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nowl <nowl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 13:48:59 by mgras             #+#    #+#             */
/*   Updated: 2015/01/08 17:10:44 by nowl             ###   ########.fr       */
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
	DIR *cont;
	t_dirs	*tmp;
	t_dirs	*save;
	struct dirent *in;

	tmp = dirs;
	if (dirs->name != NULL)
	{
		while (tmp != NULL)
		{
			save = tmp;
			cont = opendir (tmp->name);
			while (((in = readdir(cont)) != NULL))
			{
				if (in->d_type == DT_DIR)
				{
					if (ft_check_dir_name(in->d_name) == 0)
						ft_new_napa_next(tmp, in->d_name);
				}
			}
			ft_putstr(tmp->name);
			ft_putchar('\n');
			tmp = save;
			tmp = tmp->next;
			closedir(cont);
		}
	}
}