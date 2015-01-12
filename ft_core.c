/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 11:52:25 by nowl              #+#    #+#             */
/*   Updated: 2015/01/12 17:45:35 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dirs	*ft_get_dirs(char **argv, int argc, t_dirs *dirs)
{
	int		ts;

	ts = 1;
	while (ts < argc && argv[ts][0] == '-')
		ts++;
	if (ts < argc)
	{
		dirs->name = (char*)malloc(sizeof(char) * (ft_strlen(argv[ts])));
		ft_strcpy(dirs->name, argv[ts]);
		ts++;
	}
	while (ts < argc && argv[ts])
		dirs = ft_new_name_end(dirs, argv[ts++]);
	return (dirs);
}

void	ft_test_usr_dirs(t_dirs *dirs)
{
	DIR				*cont;
	t_dirs			*tmp;

	tmp = dirs;
	while (tmp != NULL)
	{
		cont = opendir(tmp->name);
		if (cont == NULL)
			ft_usr_dirs_err(tmp->name);
		if (cont != NULL)
			closedir(cont);
		tmp = tmp->next;
	}
}

t_op	*ft_get_options(char **argv, int argc, t_op *ops)
{
	int		ts;
	int		ss;

	ts = 1;
	while (ts < argc && argv[ts][0] == '-')
	{
		ss = 1;
		while (argv[ts][ss])
		{
			ops = ft_check_ops(argv[ts][ss], ops);
			if (ops->err == 400)
				return (ops);
			ss++;
		}
		ts++;
	}
	return (ops);
}

int		main(int argc, char **argv)
{
	t_op	*ops;
	t_dirs	*dirs;

	ops = (t_op*)malloc(sizeof(t_op));
	dirs = (t_dirs*)malloc(sizeof(t_dirs));
	dirs->next = NULL;
	ops = ft_init_ops(ops);
	if (argc > 1)
		ops = ft_get_options(argv, argc, ops);
	if (argc > 1 && ops->err == 400)
	{
		free (ops);
		return (0);
	}
	if (argc > 1)
	{
		dirs = ft_get_dirs(argv, argc, dirs);
		ft_test_usr_dirs(dirs);
	}
	ft_mecha_init(argc, argv, ops, dirs);
	return (0);
}