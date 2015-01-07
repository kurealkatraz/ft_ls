/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 13:48:59 by mgras             #+#    #+#             */
/*   Updated: 2015/01/07 14:45:01 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_get_path(t_dirs *tmp, struct dirent *in)
{
	if (in->d_type == DT_DIR)
		ft_new_napa_next(tmp, in->d_name, tmp->path);
}

void	ft_get_recursive(t_dirs *dirs)
{
	DIR *cont;
	t_dirs	tmp;
	struct dirent *in;

	tmp = dirs
	if (dirs->name != NULL)
		while (tmp->next != NULL)
		{
			cont = opendir (tmp->name);
			while ((in = readdir(cont)) == 1)
				ft_get_path(tmp, in);
			tmp = tmp->next;
		}
}