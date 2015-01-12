/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 17:59:10 by mgras             #+#    #+#             */
/*   Updated: 2015/01/12 18:57:17 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_swap(t_dirs *b4p, t_dirs *b4s, t_dirs *p, t_dirs *s)
{
	t_dirs		*tmp;

	tmp = p;
	p->next = s->next;
	s->next = tmp->next;
	b4p->next = s;
	b4s->next = p;
	tmp = s;
	s = p;
	p = tmp;
}

void	ft_alprt_dirs(t_dirs *dirs)
{
	t_dirs	*place;
	t_dirs	*b4place;
	t_dirs	*b4swipe;
	t_dirs	*swipe;

	place = dirs->next;
	b4place = dirs;
	while (place != NULL)
	{
		if (swipe->usr == 1)
			b4place = place;
		if (swipe->usr == 1)
			place = place->next;
		swipe = place->next;
		b4swipe = place;
		while (swipe->usr != 1 && swipe != NULL)
		{
			if (ft_strcmp(swipe->name, place->name) < 0) //SHIT TO DO BITCH
				ft_swap(b4place, b4swipe, place, swipe);
			swipe = swipe->next;
		}
	}
}

void	ft_alpha_sort(t_all *all, t_dirs *dirs)
{
	if (dirs->name != NULL)
		ft_alprt_dirs(dirs);
	ft_alprt_files(all, dirs);
}