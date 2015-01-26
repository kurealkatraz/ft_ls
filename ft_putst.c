/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 11:56:55 by mgras             #+#    #+#             */
/*   Updated: 2015/01/26 17:33:25 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_put_st_mode(mode_t mode)
{
	if (mode == S_IFDIR)
		ft_putchar('d');
	else if (mode == S_IFBLK)
		ft_putchar('b');
	else if (mode == S_IFCHR)
		ft_putchar('c');
	else if (mode == S_IFIFO)
		ft_putchar('p');
	else if (mode == S_IFLNK)
		ft_putchar('l');
	else if (mode == S_IFMT)
		ft_putchar('s');
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
	ft_putstr("  ");
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
	len = ft_strlen(med->pw_name);
	ft_putstr(med->pw_name);
	while (len++ < offset)
		ft_putchar(' ');
	ft_putstr("  ");
}
