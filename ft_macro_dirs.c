/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_macro_dirs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 17:36:16 by nowl              #+#    #+#             */
/*   Updated: 2015/01/28 13:00:35 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dirs	*ft_init_napa_chain(char *file_name, char *path_name)
{
	t_dirs	*new_dirs;

	new_dirs = (t_dirs*)malloc(sizeof(t_dirs));
	new_dirs->name = (char*)malloc(sizeof(char) * (ft_strlen(file_name) + ft_strlen(path_name)) + 2);
	new_dirs->name = ft_strclip(path_name, file_name, new_dirs->name);
	new_dirs->next = NULL;
	return(new_dirs);
}

t_dirs	*ft_new_napa_next(t_dirs *dirs, char *file_name, char *path_name)
{
	t_dirs	*new_dirs;

	new_dirs = (t_dirs*)malloc(sizeof(t_dirs));
	new_dirs->name = (char*)malloc(sizeof(char) * (ft_strlen(file_name) + ft_strlen(path_name)) + 2);
	new_dirs->name = ft_strclip(path_name, file_name, new_dirs->name);
	new_dirs->next = NULL;
	dirs->next = new_dirs;
	return (new_dirs);
}

t_dirs	*ft_del_curr(t_dirs *get_prev, t_dirs *dirs)
{
	get_prev->next = dirs->next;
	free(dirs->name);
	if (dirs->lsl != NULL)
		free(dirs->lsl);
	free(dirs);
	dirs = get_prev->next;
	return (dirs);
}

t_dirs	*ft_del_files(t_dirs *dirs)
{
	t_dirs	*get_prev;

	get_prev = dirs;
	dirs = dirs->next;
	while (get_prev->file == 1 && dirs != NULL)
	{
		free(get_prev->name);
		if (get_prev->lsl != NULL)
			free (get_prev->lsl);
		free (get_prev);
		get_prev = dirs;
		dirs = dirs->next;
	}
	while (dirs != NULL)
	{
		if (dirs->file == 1)
			dirs = ft_del_curr(get_prev, dirs);
		else
		{
			get_prev = get_prev->next;
			dirs = dirs->next;
		}
	}
	return (get_prev);
}

t_dirs	*ft_new_na_next(t_dirs *dirs, char *name)
{
	t_dirs	*new_dirs;

	new_dirs = (t_dirs*)malloc(sizeof(t_dirs));
	new_dirs->name = (char*)malloc(sizeof(char) * (ft_strlen(name)) + 1);
	new_dirs->name = ft_strcpy(new_dirs->name, name);
	new_dirs->next = NULL;
	new_dirs->file = 0;
	dirs->next = new_dirs;
	return (new_dirs);	
}