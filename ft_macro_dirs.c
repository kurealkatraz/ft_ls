/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_macro_dirs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nowl <nowl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 17:36:16 by nowl              #+#    #+#             */
/*   Updated: 2015/01/06 19:00:46 by nowl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dirs	*ft_new_name_end(t_dirs *dirs, char	*str)
{
	t_dirs	*new_dirs;
	t_dirs	*tmp;

	new_dirs = (t_dirs*)malloc(sizeof(t_dirs));
	new_dirs->name = (char*)malloc(sizeof(char) * (ft_strlen(str)));
	if (dirs->next == NULL)
	{
		new_dirs->name = (char*)malloc(sizeof(char) * (ft_strlen(str)));
		ft_strncpy(new_dirs->name, str, ft_strlen(str));
		dirs->next = new_dirs;
	}
	else
	{
		tmp = dirs;
		while (tmp->next != NULL)
			tmp = tmp->next;
		ft_strncpy(new_dirs->name, str, ft_strlen(str));
		tmp->next = new_dirs;
	}
	new_dirs->next = NULL;
	return (dirs);
}
