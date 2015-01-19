/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 12:34:49 by mgras             #+#    #+#             */
/*   Updated: 2015/01/19 16:45:14 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_get_digit(int n)
{
	int		count;

	count  = 0;
	while (n =/ 10 > 10)
		count++;
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