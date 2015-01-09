/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 11:58:16 by nowl              #+#    #+#             */
/*   Updated: 2015/01/09 16:52:30 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/types.h>

typedef struct	s_op
{
	int	R;
	int	t;
	int	r;
	int	l;
	int	a;
	int	err;
}				t_op;

typedef struct	s_dirs t_dirs;
typedef struct	s_dirs
{
	char	*name;
	t_dirs	*next;	
}				t_dirs;

void	ft_op_error(int index, char err);

//CORE
t_op	*ft_get_options(char **argv, int argc, t_op *ops);
t_dirs	*ft_get_dirs(char **argv, int argc, t_dirs *dirs);

//-R Init
void	ft_mecha_init(int argc, char **argv, t_op *ops, t_dirs *dirs);

//-R Mecha
void	ft_get_recursive(t_dirs *dirs);

//OP MACROS
t_op	*ft_get_options(char **argv, int argc, t_op *ops);
t_op	*ft_init_ops(t_op *ops);
t_op	*ft_check_ops(char c, t_op *ops);

//DIRS MACROS
t_dirs	*ft_new_name_end(t_dirs *dirs, char	*str);
t_dirs	*ft_del_curr(t_dirs *prev, t_dirs *curr);
t_dirs	*ft_new_napa_next(t_dirs *dirs, char *name);

//UTILITY
char	*ft_strclip(char *path, char *name, char *new_dirs);
char	*ft_strcpy(char *dest, const char *src);
void	ft_putstr(char *str);
void	ft_putchar(char c);
size_t	ft_strlen(const char *s);


#endif