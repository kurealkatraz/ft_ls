/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 11:56:55 by mgras             #+#    #+#             */
/*   Updated: 2015/02/06 14:35:49 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_put_st_mode(mode_t mode)
{
	if (S_ISDIR(mode))
		ft_putchar('d');
	else if (S_ISBLK(mode))
		ft_putchar('b');
	else if (S_ISCHR(mode))
		ft_putchar('c');
	else if (S_ISFIFO(mode))
		ft_putchar('p');
	else if (S_ISLNK(mode))
		ft_putchar('l');
	else
		ft_putchar('-');
}

void	ft_put_restrict(mode_t mode)
{
	ft_putchar(mode & S_IRUSR ? 'r' : '-');
	ft_putchar(mode & S_IWUSR ? 'w' : '-');
	ft_putchar(mode & S_IXUSR ? 'x' : '-');
	ft_putchar(mode & S_IRGRP ? 'r' : '-');
	ft_putchar(mode & S_IWGRP ? 'w' : '-');
	ft_putchar(mode & S_IXGRP ? 'x' : '-');
	ft_putchar(mode & S_IROTH ? 'r' : '-');
	ft_putchar(mode & S_IWOTH ? 'w' : '-');
	ft_putchar(mode & S_IXOTH ? 'x' : '-');
	ft_putchar(' ');
}

void	ft_put_st_nlinks(nlink_t links, int offset)
{
	int		ln_len;

	ln_len = ft_get_digit((int)links);
	if (ln_len < offset)
		while (offset-- > ln_len)
			ft_putchar(' ');
	ft_putnbr((int)links);
	ft_putchar(' ');
}

void	ft_put_uid(uid_t uid, int offset)
{
	struct passwd	*med;
	int				len;

	med = getpwuid(uid);
	if (med != NULL)
	{
		len = ft_strlen(med->pw_name);
		ft_putstr(med->pw_name);
		while (len++ < offset)
			ft_putchar(' ');
	}
	else
	{
		len = ft_get_digit((int)uid);
		ft_putnbr((int)uid);
		while (len++ < offset)
			ft_putchar(' ');
	}
}

void	ft_put_st_dev(int major, int minor, int offset)
{
	int		majoff;
	int		minoff;

	majoff = ft_get_digit(major);
	minoff = ft_get_digit(minor);
	while (majoff++ < ((offset - 1) / 2))
		ft_putchar(' ');
	ft_putnbr(major);
	ft_putchar(',');
	while (minoff++ < ((offset - 1) / 2))
		ft_putchar(' ');
	ft_putnbr(minor);
	ft_putchar(' ');
}
