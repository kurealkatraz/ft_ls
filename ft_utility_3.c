/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 12:37:47 by mgras             #+#    #+#             */
/*   Updated: 2015/02/06 15:18:55 by mgras            ###   ########.fr       */
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
	else if (ft_strlen(str) == 3)
	{
		if (str[0] == '.' && str[1] == '.' && str[2] == '/' && str[3] == '\0')
			return (1);
	}
	else if (ft_strlen(str) == 2)
	{
		if (str[0] == '.' && str[1] == '/' && str[2] == '\0')
			return (1);
	}
	return (0);
}

void	ft_set_file(t_dirs *dirs)
{
	if (dirs->file != 2)
	{
		if (S_ISDIR(dirs->lsl->mode))
			dirs->file = 0;
		else
			dirs->file = 1;
		if ((ft_name(ft_end(dirs->name))) == 1)
			dirs->file = 1;
	}
}

char	*ft_end(char *str)
{
	char	*end;
	int		endlen;
	int		str_s;
	int		str_e;

	str_s = 0;
	str_e = 0;
	while (str[str_s])
		str_s++;
	while (str[str_s] != '/' && str_s >= 0)
		str_s--;
	if (str_s == 0)
		return (str);
	endlen = ft_strlen(str) - str_s;
	end = (char*)malloc((sizeof(char) * (1 + endlen)));
	str_s++;
	while (str[str_s])
		end[str_e++] = str[str_s++];
	end[str_e] = '\0';
	return (end);
}

int		ft_blank_out(char *str, int size)
{
	int		ss;

	ss = 0;
	while (ss <= size)
		str[ss++] = 0;
	return (0);
}

int		ft_hidden(char *str)
{
	if (str[0] == '.')
		return (1);
	return (0);
}
