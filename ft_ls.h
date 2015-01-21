/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 11:58:16 by nowl              #+#    #+#             */
/*   Updated: 2015/01/21 11:46:54 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/errno.h>
# include <sys/xattr.h>
# include <uuid/uuid.h>

typedef struct	s_dirs t_dirs;
typedef struct	s_all t_all;

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
	mode_t			mode;
	nlink_t			hardlink;
	uid_t			uid;
	gid_t			gid;
	off_t			size;
	struct timespec	st_mtimespec;
}				t_lsl;

typedef struct	s_dirs
{
	char	*name;
	int		file;
	t_dirs	*next;
}				t_dirs;

typedef struct	s_all
{
	char		*file_name;
	char		*path;
	char		*full;
	blkcnt_t	blocks;
	t_lsl		*lsl;
	t_all		*next;
}				t_all;

//SORTING
void	time_stamp_sort(t_all *a);
void	ft_core_sorting(t_all *all, t_op *ops);

//FILE PRINT


//GET OFFSET
int		get_nlink_off(nlink_t links);
int		get_uid_off(uid_t uid);
int		get_gid_off(gid_t gid);
int		get_size_off(size_t size);

//PUTST
void	ft_put_gid(gid_t gid, int offset);
void	ft_put_size(size_t size, int offset);
void	ft_put_st_nlinks(nlink_t links, int offset);
void	ft_put_uid(uid_t uid, int offset);
void	ft_put_modtime(struct stat ss);
void	ft_put_st_mode(mode_t mode);
void	ft_put_restrict(mode_t mode);

//ERROR PRINT
void	ft_op_error(int index, char err);
void	ft_usr_dirs_err(char *erred_dir);
void	ft_forbiden_access(char *erred_dir);

//ALPHA SORT
void	ft_alphasort(t_all *a);
void	ft_swap(t_all *a);

//ALL MACROS
t_all	*ft_new_fina_next(t_all *a, char *file_name, char *path);

//LSL MACROS
t_all	*ft_get_lsl(t_all* all, char *path);

//CORE
t_op	*ft_get_options(char **argv, int argc, t_op *ops);
t_dirs	*ft_get_dirs(char **argv, int argc, t_dirs *dirs);
void	ft_test_usr_dirs(t_dirs *dirs);

//-R Init
void	ft_mecha_init(int argc, char **argv, t_op *ops, t_dirs *dirs);

//Mecha
void	ft_get_recursive(t_dirs *dirs);
t_all	*ft_fetch_local(t_all *all, t_op *ops);
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
void	ft_putnbr(int n);
size_t	ft_strlen(const char *s);
int		ft_get_digit(int n);
int		ft_strcmp(const char *s1, const char *s2);

#endif
