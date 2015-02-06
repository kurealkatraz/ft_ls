/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 14:56:39 by mgras             #+#    #+#             */
/*   Updated: 2015/02/06 16:16:20 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_search_err(t_dirs *dirs)
{
	t_dirs	*d_tmp;

	d_tmp = dirs;
	while (d_tmp != NULL)
	{
		if (d_tmp->file > 1)
			return (1);
		d_tmp = d_tmp->next;
	}
	return (0);
}

void	ft_free_all(t_dirs *ins)
{
	while (ins != NULL)
	{
		free (ins->name);
		free (ins->lsl);
		free (ins);
		ins = ins->next;
	}
}

void	ft_dat_backn(t_off *off, t_dirs *dirs)
{
	int		print;
	t_dirs	*d_tmp;

	print = 0;
	d_tmp = dirs;
	free (off);
	while (d_tmp != NULL)
	{
		if (d_tmp->file == 1)
			print = 1;
		d_tmp = d_tmp->next;
	}
	while (dirs != NULL)
	{
		if (dirs->file < 1 && print == 1)
		{
			ft_putchar('\n');
			return ;
		}
		dirs = dirs->next;
	}
}

void	ft_putchar_err(char c)
{
	write(2, &c, 1);
}

void	ft_putstr_fd(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		ft_putchar_err(str[i++]);
}
