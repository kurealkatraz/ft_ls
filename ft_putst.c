/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 11:56:55 by mgras             #+#    #+#             */
/*   Updated: 2015/01/20 17:17:18 by mgras            ###   ########.fr       */
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
	mode & S_IRUSR ? ft_putchar('r') : ft_putchar('-');
	mode & S_IWUSR ? ft_putchar('w') : ft_putchar('-');
	mode & S_IXUSR ? ft_putchar('x') : ft_putchar('-');
	mode & S_IRGRP ? ft_putchar('r') : ft_putchar('-');
	mode & S_IWGRP ? ft_putchar('w') : ft_putchar('-');
	mode & S_IXGRP ? ft_putchar('x') : ft_putchar('-');
	mode & S_IROTH ? ft_putchar('r') : ft_putchar('-');
	mode & S_IWOTH ? ft_putchar('w') : ft_putchar('-');
	mode & S_IXOTH ? ft_putchar('x') : ft_putchar('-');
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
