/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mecha_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 15:32:10 by mgras             #+#    #+#             */
/*   Updated: 2015/01/23 10:57:57 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
# include <string.h>

void	ft_swap_afull(t_all *a)
{
	char	*str_swap;

	str_swap = (char*)malloc(sizeof(char) * ft_strlen(a->full) + 1);
	strcpy(str_swap, a->full);
	free(a->full);
	a->full = (char*)malloc(sizeof(char) * ft_strlen(a->next->full) + 1);
	strcpy(a->full, a->next->full);
	free(a->next->full);
	a->next->full = (char*)malloc(sizeof(char) * ft_strlen(str_swap) + 1);
	strcpy(a->next->full, str_swap);
	free(str_swap);
}

void	ft_swap_afile_name(t_all *a)
{
	char	*str_swap;

	str_swap = (char*)malloc(sizeof(char) * ft_strlen(a->file_name)+ 1);
	ft_strcpy(str_swap, a->file_name);
	free(a->file_name);
	a->file_name = (char*)malloc(sizeof(char) * ft_strlen(a->next->file_name) + 1);
	ft_strcpy(a->file_name, a->next->file_name);
	free(a->next->file_name);
	a->next->file_name = (char*)malloc(sizeof(char) * ft_strlen(str_swap) + 1);
	ft_strcpy(a->next->file_name, str_swap);
	free(str_swap);
}

void	ft_swap_apath(t_all *a)
{
	char	*str_swap;

	str_swap = (char*)malloc(sizeof(char) * ft_strlen(a->path) + 1);
	ft_strcpy(str_swap, a->path);
	free(a->path);
	a->path = (char*)malloc(sizeof(char) * ft_strlen(a->next->path) + 1);
	ft_strcpy(a->path, a->next->path);
	free(a->next->path);
	a->next->path = (char*)malloc(sizeof(char) * ft_strlen(str_swap) + 1);
	ft_strcpy(a->next->path, str_swap);
	free(str_swap);
}

void	ft_swap_ablock(t_all *a)
{
	blkcnt_t	tmp;

	tmp = a->blocks;
	a->blocks = a->next->blocks;
	a->next->blocks = tmp;
}

void	ft_swap_core(t_all *a, t_op *ops)
{
	time_t	tmp;

	ft_swap_afull(a);
	ft_swap_afile_name(a);
	ft_swap_apath(a);
	ft_swap_ablock(a);
	if (ops->l == 1 || ops->t == 1)
	{
		tmp = a->lsl->st_mtimespec.tv_sec;
		a->lsl->st_mtimespec.tv_sec = a->next->lsl->st_mtimespec.tv_sec;
		a->next->lsl->st_mtimespec.tv_sec = tmp;
	}
}