/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_macro_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 14:38:16 by mgras             #+#    #+#             */
/*   Updated: 2015/01/19 13:21:18 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_all	*ft_new_fina_next(t_all *a, char *file_name, char *path)
{
	t_all	*new_a;

	new_a = (t_all*)malloc(sizeof(t_all));
	new_a->file_name = (char*)malloc(sizeof(char) * ft_strlen(file_name));
	new_a->path = (char*)malloc(sizeof(char) * ft_strlen(path));
	a->full = (char*)malloc(sizeof(char) *
		(ft_strlen(path) + ft_strlen(file_name) + 2));
	ft_strclip(path, file_name, a->full);
	ft_strcpy(new_a->file_name, file_name);
	ft_strcpy(new_a->path, path);
	a->next = new_a;
	new_a->next = NULL;
	return (a);
}
