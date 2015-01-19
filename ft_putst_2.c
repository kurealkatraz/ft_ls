/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putst_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 16:33:39 by mgras             #+#    #+#             */
/*   Updated: 2015/01/19 18:13:26 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_put_gid(gid_t gid, int offset)
{
	struct group	*med;
	int				len;

	med = getgrgid(gid);
	len = ft_strlen(med->gr_name);
	ft_putstr(med->gr_name);
	while (len++ < offset)
		ft_putchar(' ');
	ft_putstr("   ");
}

void	ft_put_size(size_t size, int offset, int len)
{
	len = ft_get_digit((int)size);
	if (len < 6)
	{
		while (len++ < offset)
			ft_putchar(' ');
		ft_putnbr((int)size);
	}
	else if (len >= 6 && len <= 9)
	{
		while ((-5 + len++ < offset)
			ft_putchar(' ');
		ft_putnbr((int)(size / 100));
		ft_putchar('K')
	}
	else if (len >= 9 && len <=12)
	{
		while ((-8 + len++ < offset)
			ft_putchar(' ');
		ft_putnbr((int)(size / 100000));
	}
	else
		ft_big_size(size, offset, len);
}