/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_macro_dirs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 17:36:16 by nowl              #+#    #+#             */
/*   Updated: 2015/01/26 16:56:53 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dirs	*ft_new_napa_next(t_dirs *dirs, char *name)
{
	t_dirs	*new_dirs;

	new_dirs = (t_dirs*)malloc(sizeof(t_dirs));
	new_dirs->name = (char*)malloc(sizeof(char) * (ft_strlen(dirs->name) + ft_strlen(name)) + 2);
	new_dirs->name = ft_strclip(dirs->name, name, new_dirs->name);
	new_dirs->next = NULL;
	new_dirs->file = 0;
	dirs->next = new_dirs;
	return (new_dirs);
}

t_dirs	*ft_del_curr(t_dirs *prev, t_dirs *curr)
{
	if (curr != NULL && curr->name != NULL)
		free(curr->name);
	prev->next = curr->next;
	if (curr != NULL)
		free(curr);
	return (prev);
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