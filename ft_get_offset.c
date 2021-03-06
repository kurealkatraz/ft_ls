/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_offset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 15:21:42 by mgras             #+#    #+#             */
/*   Updated: 2015/02/06 16:00:41 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		get_nlink_off(nlink_t links)
{
	int		offset;

	offset = ft_get_digit((int)links);
	return (offset + 1);
}

int		get_uid_off(uid_t uid)
{
	struct passwd	*med;
	int				offset;

	med = getpwuid(uid);
	if (med != NULL)
		offset = ft_strlen(med->pw_name);
	else
		offset = ft_get_digit((int)uid);
	return (offset + 2);
}

int		get_gid_off(gid_t gid)
{
	struct group	*med;
	int				offset;

	med = getgrgid(gid);
	if (med != NULL)
		offset = ft_strlen(med->gr_name);
	else
		offset = ft_get_digit((int)gid);
	return (offset + 1);
}

int		get_size_off(size_t size)
{
	int		offset;

	offset = ft_get_digit((int)size);
	return (offset + 1);
}

int		get_dev_off(t_lsl *lsl)
{
	int		size;

	size = ft_get_digit(lsl->major);
	size = size + ft_get_digit(lsl->minor);
	if (size < 9)
		size = 9;
	return (size);
}
