/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mecha_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 13:40:54 by mgras             #+#    #+#             */
/*   Updated: 2015/01/07 16:10:56 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_mecha_init(int argc, char **argv, t_op *ops, t_dirs *dirs)
{
	if (ops->R == 1 && argv && argc)
		ft_get_recursive(dirs);
}