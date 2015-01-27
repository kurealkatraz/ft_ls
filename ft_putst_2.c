/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putst_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 16:33:39 by mgras             #+#    #+#             */
/*   Updated: 2015/01/27 11:11:48 by mgras            ###   ########.fr       */
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
	char	*timestamp;
	int		i;

	timestamp = (char*)malloc(sizeof(char) * ft_strlen(ctime(&(st_mtimespec.tv_sec))));
	ft_strcpy(timestamp, ctime(&(st_mtimespec.tv_sec)));
	i = 0;
	while (timestamp[i] != ' ')
		i++;
	i++;
	while (timestamp[i] != ':')
		ft_putchar(timestamp[i++]);
	i++;
	ft_putchar(':');
	while (timestamp[i] != ':')
		ft_putchar(timestamp[i++]);
	while (timestamp[i] != ' ')
		i++;
	i++;
	ft_putchar(' ');
	while(timestamp[i] != '\n')
		ft_putchar(timestamp[i++]);
	ft_putchar(' ');
}