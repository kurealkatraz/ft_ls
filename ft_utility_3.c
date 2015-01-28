/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 12:37:47 by mgras             #+#    #+#             */
/*   Updated: 2015/01/28 13:39:03 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_name(char *str)
{
	if (ft_strlen(str) == 2)
	{
		if (str[0] == '.' && str[1] == '.' && str[2] == '\0')
			return (1);
	}
	else if (ft_strlen(str) == 1)
	{
		if (str[0] == '.' && str[1] == '\0')
			return (1);
	}
	return (0);
}

void	ft_set_file(t_dirs *dirs, const char type)
{
	if (type & DT_DIR)
		dirs->file = 0;
	else
		dirs->file = 1;
}

int		ft_hidden(char *str)
{
	if (str[0] == '.')
		return (1);
	return(0);
}