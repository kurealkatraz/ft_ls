/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putst_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 16:33:39 by mgras             #+#    #+#             */
/*   Updated: 2015/01/26 16:15:24 by mgras            ###   ########.fr       */
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
	ft_putstr("  ");
}

void	ft_put_size(size_t size, int offset)
{
	int		len;

	len = ft_get_digit((int)size);
	while (len++ < offset)
		ft_putchar(' ');
	ft_putnbr((int)size);
	ft_putchar(' ');
}

void	ft_put_modtime(struct timespec st_mtimespec)
{

	if (st_mtimespec.tv_sec)
		return;
}