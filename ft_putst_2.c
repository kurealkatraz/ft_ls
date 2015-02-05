/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putst_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 16:33:39 by mgras             #+#    #+#             */
/*   Updated: 2015/02/05 16:14:19 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_put_gid(gid_t gid, int offset)
{
	struct group	*med;
	int				len;

	med = getgrgid(gid);
	if (med != NULL)
	{
		len = ft_strlen(med->gr_name);
		ft_putstr(med->gr_name);
		while (len++ < offset)
			ft_putchar(' ');
	}
	else
	{
		len = ft_get_digit((int)gid);
		ft_putnbr((int)gid);
		while (len++ < offset)
			ft_putchar(' ');
	}
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

void	ft_oldfag(char *timestamp, int i)
{
	while (timestamp[i] != ' ')
		i++;
	i++;
	while (timestamp[i] != ' ')
		ft_putchar(timestamp[i++]);
	ft_putchar(timestamp[i++]);
	if (timestamp[i] == ' ')
		ft_putchar(timestamp[i++]);
	while (timestamp[i] != ' ')
		ft_putchar(timestamp[i++]);
	ft_putstr("  ");
	i++;
	while (timestamp[i] != ' ')
		i++;
	i++;
	while (timestamp[i] != '\n')
		ft_putchar(timestamp[i++]);
}

void	ft_put_modtime(struct timespec st_mtimespec)
{
	char	*timestamp;
	int		i;

	timestamp = (char*)malloc(sizeof(char)
		* ft_strlen(ctime(&(st_mtimespec.tv_sec))));
	ft_strcpy(timestamp, ctime(&(st_mtimespec.tv_sec)));
	i = 0;
	if (st_mtimespec.tv_sec + 15552000 >= time(NULL))
	{
		while (timestamp[i] != ' ')
			i++;
		i++;
		while (timestamp[i] != ':')
			ft_putchar(timestamp[i++]);
		i++;
		ft_putchar(':');
		while (timestamp[i] != ':')
			ft_putchar(timestamp[i++]);
	}
	else
		ft_oldfag(timestamp, i);
	ft_putchar(' ');
}
