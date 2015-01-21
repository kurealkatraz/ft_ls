/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 17:59:10 by mgras             #+#    #+#             */
/*   Updated: 2015/01/21 12:40:16 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_swap_core(t_all *a)
{

}

void	ft_alphasort(t_all *a)
{
	t_all	*save;

	save = a;
	while (a->next != NULL)
	{
		if (ft_strcmp(a->full, a->next->full) > 0)
		{
			ft_swap(a);
			a = save;
		}
		else
			a = a->next;
	}
}

void	time_stamp_sort(t_all *a)
{
	t_all	*save;

	save = a;
	while (a->next != NULL)
	{
		if (a->lsl->st_mtimespec.tv_sec < a->next->lsl->st_mtimespec.tv_sec)
		{
			ft_swap(a);
			a = save;
		}
		else
			a = a->next;
	}
}

void	ft_core_sorting(t_all *all, t_op *ops)
{
	t_all	*tmp;

	tmp = all;
	if (ops->t == 0)
		ft_alphasort(tmp);
	else
		time_stamp_sort(tmp);
}