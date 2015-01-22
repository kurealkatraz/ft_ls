/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mecha_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 17:00:23 by mgras             #+#    #+#             */
/*   Updated: 2015/01/22 17:34:25 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_free_all(t_all *all, t_dirs *dirs, t_op *ops)
{
	t_all	*a_tmp;
	t_dirs	*d_tmp;

	while (all->next != NULL)
	{
		a_tmp = all;
		free(all->file_name);
		free(all->path);
		free(all->full);
		all = all->next;
		free(a_tmp);
	}
	while (dirs != NULL)
	{
		d_tmp = dirs;
		free(dirs->name);
		dirs = dirs->next;
		free(d_tmp);
	}
	free (ops);
}