/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 17:59:10 by mgras             #+#    #+#             */
/*   Updated: 2015/02/08 16:30:02 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_alphasort(t_dirs *a)
{
	t_dirs	*save;

	save = a;
	while (a->next != NULL)
	{
		if (ft_strcmp(a->name, a->next->name) > 0)
		{
			ft_swap_core(a);
			a = save;
		}
		else
			a = a->next;
	}
}

void	time_stamp_sort(t_dirs *a)
{
	t_dirs	*save;

	save = a;
	while (a->next != NULL)
	{
		if (a->lsl->st_mtimespec.tv_sec < a->next->lsl->st_mtimespec.tv_sec)
		{
			ft_swap_core(a);
			a = save;
		}
		else
			a = a->next;
	}
}

void	rev_time_stamp_sort(t_dirs *a)
{
	t_dirs	*save;

	save = a;
	while (a->next != NULL)
	{
		if (a->lsl->st_mtimespec.tv_sec > a->next->lsl->st_mtimespec.tv_sec)
		{
			ft_swap_core(a);
			a = save;
		}
		else
			a = a->next;
	}
}

void	rev_alphasort(t_dirs *a)
{
	t_dirs	*save;

	save = a;
	while (a->next != NULL)
	{
		if (ft_strcmp(a->name, a->next->name) < 0)
		{
			ft_swap_core(a);
			a = save;
		}
		else
			a = a->next;
	}
}

void	ft_core_sorting(t_dirs *all, t_op *ops)
{
	t_dirs	*tmp;

	tmp = all;
	if (ops->t == 0 && ops->r == 0)
		ft_alphasort(tmp);
	else if (ops->t == 1 && ops->r == 0)
		time_stamp_sort(tmp);
	else if (ops->t == 0 && ops->r == 1)
		rev_alphasort(tmp);
	else if (ops->t == 1 && ops->r == 1)
		rev_time_stamp_sort(tmp);
}
