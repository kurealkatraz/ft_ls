/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 11:52:25 by nowl              #+#    #+#             */
/*   Updated: 2015/02/06 15:48:49 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dirs	*ft_get_dirs(char **argv, int argc, t_dirs *dirs)
{
	int		ts;
	t_dirs	*save;

	ts = 1;
	while (ts < argc && argv[ts][0] == '-')
		ts++;
	if (ts < argc)
	{
		dirs->name = (char*)malloc(sizeof(char) * (ft_strlen(argv[ts])));
		ft_strcpy(dirs->name, argv[ts]);
		ts++;
	}
	else
	{
		dirs->name = (char*)malloc(sizeof(char) * (ft_strlen(".")) + 1);
		ft_strcpy(dirs->name, ".");
	}
	save = dirs;
	while (ts < argc && argv[ts])
		save = ft_new_na_next(save, argv[ts++]);
	return (dirs);
}

void	ft_test_usr_dirs(t_dirs *dirs)
{
	t_dirs			*tmp;
	struct stat		ss;

	tmp = dirs;
	errno = 0;
	while (tmp != NULL)
	{
		lstat(tmp->name, &ss);
		if (S_ISDIR(ss.st_mode))
			tmp->file = 0;
		else
			tmp->file = 1;
		if (errno == 2)
		{
			ft_usr_dirs_err(tmp->name);
			tmp->file = 2;
		}
		listxattr(tmp->name, NULL, 0, XATTR_NOFOLLOW);
		if (errno == 13 && S_ISDIR(ss.st_mode))
			tmp->file = 3;
		tmp = tmp->next;
		errno = 0;
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

	errno = 0;
	ops = (t_op*)malloc(sizeof(t_op));
	dirs = (t_dirs*)malloc(sizeof(t_dirs));
	dirs->next = NULL;
	ops = ft_init_ops(ops);
	if (argc > 1)
		ops = ft_get_options(argv, argc, ops);
	if (argc > 1 && ops->err == 400)
	{
		free(ops);
		free(dirs);
		return (0);
	}
	dirs = ft_get_dirs(argv, argc, dirs);
	if (dirs->name != NULL)
		ft_test_usr_dirs(dirs);
	ft_mecha_init(ops, dirs);
	ft_free_all(dirs);
	free(ops);
	return (0);
}
