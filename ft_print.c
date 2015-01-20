/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 11:22:27 by mgras             #+#    #+#             */
/*   Updated: 2015/01/20 17:53:29 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_isolation(struct stat ss, char *file_name, t_op *ops)
{
	if (ops->l != 1)
	{
		ft_putstr(file_name);
		ft_putstr("\n\n");
	}
	else
	{
		ft_put_st_mode(ss.st_mode);
		ft_put_restrict(ss.st_mode);
		ft_put_st_nlinks(ss.st_nlink, get_nlink_off(ss.st_nlink));
		ft_put_uid(ss.st_uid, get_uid_off(ss.st_uid));
		ft_put_gid(ss.st_gid, get_gid_off(ss.st_gid));
		ft_put_size(ss.st_size, get_size_off(ss.st_size));
		ft_put_modtime(ss);
		ft_putstr(file_name);
		ft_putstr("\n");
	}
}
