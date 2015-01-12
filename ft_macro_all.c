/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_macro_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 14:38:16 by mgras             #+#    #+#             */
/*   Updated: 2015/01/12 16:49:27 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_all	*ft_new_local_next(t_all *all, char *filename)
{
	t_all	*new_all;

	if (all->file_name == NULL)
	{
		all->file_name = (char*)malloc(sizeof(char) * ft_strlen(filename));
		ft_strcpy(all->file_name, filename);
		all->path = NULL;
	}
	else
	{
		new_all = (t_all*)malloc(sizeof(t_all));
		new_all->file_name = (char*)malloc(sizeof(char) * ft_strlen(filename));
		ft_strcpy(new_all->file_name, filename);
		new_all->path = NULL;
		all->next = new_all;
		new_all->next = NULL;
	}
	return (all);
}

t_all	*ft_new_fina_next(t_all *all, char *filename, t_dirs *path)
{
	t_all	*new_all;

	if (all->file_name == NULL)
	{
		all->file_name = (char*)malloc(sizeof(char) * ft_strlen(filename));
		ft_strcpy(all->file_name, filename);
		all->path = path;
	}
	else
	{
		new_all = (t_all*)malloc(sizeof(t_all));
		new_all->file_name = (char*)malloc(sizeof(char) * ft_strlen(filename));
		ft_strcpy(new_all->file_name, filename);
		new_all->path = path;
		all->next = new_all;
	}
	return (all);
}
