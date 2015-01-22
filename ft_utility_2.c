/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 12:34:49 by mgras             #+#    #+#             */
/*   Updated: 2015/01/22 17:44:09 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_check_if_dirs(t_dirs	*dirs)
{
	while (dirs->next != NULL)
	{
		if (dirs->file == 0)
			return (1);
		dirs = dirs->next;
	}
	return (0);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	int		s1_swipe;
	int		s2_swipe;

	s1_swipe = 0;
	s2_swipe = 0;
	while (s1[s1_swipe] && (s1[s1_swipe] == s2[s2_swipe]))
	{
		s1_swipe++;
		s2_swipe++;
	}
	return (s1[s1_swipe] - s2[s1_swipe]);
}

int		ft_get_digit(int n)
{
	int		count;

	count  = 0;
	while (n > 10)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}