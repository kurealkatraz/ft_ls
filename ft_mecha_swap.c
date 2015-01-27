/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mecha_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 15:32:10 by mgras             #+#    #+#             */
/*   Updated: 2015/01/27 11:05:24 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_swap_afile_name(t_dirs *a)
{
	char	*str_swap;

	str_swap = (char*)malloc(sizeof(char) * ft_strlen(a->name)+ 1);
	ft_strcpy(str_swap, a->name);
	free(a->name);
	a->name = (char*)malloc(sizeof(char) * ft_strlen(a->next->name) + 1);
	ft_strcpy(a->name, a->next->name);
	free(a->next->name);
	a->next->name = (char*)malloc(sizeof(char) * ft_strlen(str_swap) + 1);
	ft_strcpy(a->next->name, str_swap);
	free(str_swap);
}

void	ft_swap_core(t_dirs *a, t_op *ops)
{
	time_t	tmp;
	int		f_tmp;

	ft_swap_afile_name(a);
	f_tmp = a->file;
	a->file = a->next->file;
	a->next->file = f_tmp;
	if (ops->l == 1 || ops->t == 1)
	{
		tmp = a->lsl->st_mtimespec.tv_sec;
		a->lsl->st_mtimespec.tv_sec = a->next->lsl->st_mtimespec.tv_sec;
		a->next->lsl->st_mtimespec.tv_sec = tmp;
	}
}