/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 17:59:10 by mgras             #+#    #+#             */
/*   Updated: 2015/01/19 13:25:18 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(const unsigned char*)s1 - *(const unsigned char*)s2);
}

void	ft_swap(t_all *a)
{
	char	*tmp;

	tmp = (char*)malloc(sizeof(char) * ft_strlen(a->full) + 1);
	ft_strcpy(tmp, a->full);
	free(a->full);
	a->full = (char*)malloc(sizeof(char) * ft_strlen(a->next->full) + 1);
	ft_strcpy(a->full, a->next->full);
	free(a->next->full);
	a->next->full = (char*)malloc(sizeof(char) * ft_strlen(tmp) + 1);
	ft_strcpy(a->next->full, tmp);
	free(tmp);
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
