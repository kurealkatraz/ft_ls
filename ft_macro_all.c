/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_macro_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 14:38:16 by mgras             #+#    #+#             */
/*   Updated: 2015/01/15 15:10:38 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_all	*ft_new_fina_next(t_all *a, char *file_name, char *path)
{
	t_all	*new_a;

	if (a->file_name == NULL)
	{
		a->file_name = (char*)malloc(sizeof(char) * ft_strlen(file_name));
		a->path = (char*)malloc(sizeof(char) * ft_strlen(path));
		ft_strcpy(a->file_name, file_name);
		ft_strcpy(a->path, path);
		a->next = NULL;
	}
	else
	{
		new_a = (t_all*)malloc(sizeof(t_all));
		new_a->file_name = (char*)malloc(sizeof(char) * ft_strlen(file_name));
		new_a->path = (char*)malloc(sizeof(char) * ft_strlen(path));
		ft_strcpy(new_a->file_name, file_name);
		ft_strcpy(new_a->path, path);
		a->next = new_a;
		new_a->next = NULL;
	}
	return (a);
}