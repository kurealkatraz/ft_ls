/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 11:58:16 by nowl              #+#    #+#             */
/*   Updated: 2015/01/12 16:47:52 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct	s_op
{
	int	R;
	int	t;
	int	r;
	int	l;
	int	a;
	int	err;
}				t_op;

typedef struct	s_lsl
{
	nlink_t	hardlink;
	uid_t	uid;
	gid_t	gid;
	off_t	size;
	time_t	modtime;
}				t_lsl;

typedef struct	s_dirs t_dirs;
typedef struct	s_dirs
{
	char	*name;
	int		usr;
	t_dirs	*next;	
}				t_dirs;

typedef struct	s_all t_all;
typedef struct	s_all
{
	char	*file_name;
	t_lsl	*lsl;
	t_dirs	*path;
	t_all	*next;
}				t_all;

void	ft_op_error(int index, char err);

//ALL MACROS
t_all	*ft_new_local_next(t_all *all, char *filename);
t_all	*ft_new_fina_next(t_all *all, char *filename, t_dirs *path);

//LSL MACROS
t_all	*ft_get_lsl(t_all* all, char *path);

//CORE
t_op	*ft_get_options(char **argv, int argc, t_op *ops);
t_dirs	*ft_get_dirs(char **argv, int argc, t_dirs *dirs);

//-R Init
void	ft_mecha_init(int argc, char **argv, t_op *ops, t_dirs *dirs);

//Mecha
void	ft_get_recursive(t_dirs *dirs);
void	ft_fetch_local(t_all *all, t_op *ops);
void	ft_get_all(t_all *all, t_dirs *dirs, t_op *ops);

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