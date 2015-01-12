/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_macro_dirs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 17:36:16 by nowl              #+#    #+#             */
/*   Updated: 2015/01/12 14:31:51 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dirs	*ft_new_napa_next(t_dirs *dirs, char *name)
{
	t_dirs	*new_dirs;

	new_dirs = (t_dirs*)malloc(sizeof(t_dirs));
	new_dirs->name = (char*)malloc(sizeof(char) * (ft_strlen(dirs->name) + ft_strlen(name)) + 2);
	new_dirs->name = ft_strclip(dirs->name, name, new_dirs->name);
	new_dirs->usr = 0;
	new_dirs->next = dirs->next;
	dirs->next = new_dirs;
	return (dirs);
}

t_dirs	*ft_del_curr(t_dirs *prev, t_dirs *curr)
{
	if (curr != NULL && curr->name != NULL)
		free(curr->name);
	prev->next = curr->next;
	if (curr != NULL)
		free(curr);
	return(prev);
}

t_dirs	*ft_new_name_end(t_dirs *dirs, char	*str)
{
	t_dirs	*new_dirs;
	t_dirs	*tmp;

	new_dirs = (t_dirs*)malloc(sizeof(t_dirs));
	new_dirs->name = (char*)malloc(sizeof(char) * (ft_strlen(str)));
	new_dirs->usr = 1;
	if (dirs->next == NULL)
	{
		new_dirs->name = (char*)malloc(sizeof(char) * (ft_strlen(str)));
		ft_strcpy(new_dirs->name, str);
		dirs->next = new_dirs;
	}
	else
	{
		tmp = dirs;
		while (tmp->next != NULL)
			tmp = tmp->next;
		ft_strcpy(new_dirs->name, str);
		tmp->next = new_dirs;
	}
	new_dirs->next = NULL;
	return (dirs);
}
