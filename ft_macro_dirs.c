/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_macro_dirs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 17:36:16 by nowl              #+#    #+#             */
/*   Updated: 2015/01/07 15:44:19 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dirs	*ft_new_napa_next(t_dirs *dirs, char *name, char *path)
{
	t_dirs	*new_dirs;

	new_dirs = (t_dirs*)malloc(sizeof(t_dirs));
	new_dirs->name = (char*)malloc(sizeof(char) * (ft_strlen(name)));
	ft_strncpy(new_dirs->name, name, ft_strlen(name));
	if (dirs->path == NULL)
	{
		new_dirs->path = (char*)malloc(sizeof(char) * ft_strlen(dirs->name) + 1);
		ft_strncpy(new_dirs->path, dirs->name, ft_strlen(dirs->name));
		new_dirs->path[ft_strlen(dirs->name) + 1] = '\0';
		new_dirs->path[ft_strlen(dirs->name)] = '/';
		new_dirs->next = dirs->next;
		dirs->next = new_dirs;
		return (dirs);
	}
	else
	{
		new_dirs->path = (char*)malloc(sizeof(char) * ft_strlen(dirs->path) + ft_strlen(dirs->name) + 1);
		new_dirs->path = ft_strclip(dirs->path, dirs->name); //DO IT FAGGIT
		new_dirs->path[ft_strlen(dirs->path) + ft_strlen(dirs->name) + 1] = '\0';
		new_dirs->path[ft_strlen(dirs->path) + ft_strlen(dirs->name)] = '/';
	}
}

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
