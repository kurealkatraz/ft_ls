/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_macro_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 12:22:45 by nowl              #+#    #+#             */
/*   Updated: 2015/01/07 13:39:46 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_op	*ft_init_ops(t_op *ops)
{
	ops->a = 0;
	ops->l = 0;
	ops->t = 0;
	ops->r = 0;
	ops->R = 0;
	ops->err = 0;
	return (ops);
}

t_op	*ft_check_ops(char c, t_op *ops)
{
	if (c != 'a' && c != 'R' && c != 't' &&
		c != 'r' && c != 'l')
	{
		ft_op_error(400, c);
		ops->err = 400;
		return (ops);
	}
	if (c == 'a')
		ops->a = 1;
	if (c == 'R')
		ops->R = 1;
	if (c == 'r')
		ops->r = 1;
	if (c == 'l')
		ops->l = 1;
	if (c == 't')
		ops->t = 1;
	return (ops);
}