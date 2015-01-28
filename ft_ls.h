/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 11:58:16 by nowl              #+#    #+#             */
/*   Updated: 2015/01/28 17:41:21 by mgras            ###   ########.fr       */
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

typedef struct	s_off
{
	int	link;
	int	uid;
	int	gid;
	int	size;
}				t_off;

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
	t_lsl	*lsl;
	t_dirs	*next;
}				t_dirs;


//MECHA SWAP
void	ft_swap_afile_name(t_dirs *a);
void	ft_swap_core(t_dirs *a, t_op *ops);

//SORTING
void	ft_alphasort(t_dirs *a, t_op *ops);
void	time_stamp_sort(t_dirs *a, t_op *ops);
void	ft_core_sorting(t_dirs *all, t_op *ops);

//FILE PRINT
void	ft_print_file(t_op *ops, t_lsl *lsl, char *file_name, t_off	*off);
void	ft_print_head(char *head);

//OFF MACROS
void	ft_init_off(t_off *off);
void	ft_fill_off_file(t_off *off, t_dirs *dirs);
void	ft_fill_off_all(t_off *off, t_dirs *dirs);

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
void	ft_put_modtime(struct timespec st_mtimespec);
void	ft_put_st_mode(mode_t mode);
void	ft_put_restrict(mode_t mode);

//ERROR PRINT
void	ft_op_error(int index, char err);
void	ft_usr_dirs_err(char *erred_dir);
void	ft_forbiden_access(char *erred_dir);

//LCS MACROS
t_all	*ft_get_lsl(t_all* all, char *path);
void	ft_file_lsl(t_lsl *dirs, char *name);

//CORE
t_op	*ft_get_options(char **argv, int argc, t_op *ops);
t_dirs	*ft_get_dirs(char **argv, int argc, t_dirs *dirs);
void	ft_test_usr_dirs(t_dirs *dirs);
void	ft_mecha_init(t_op *ops, t_dirs *dirs);

//MECHA

//OP MACROS
t_op	*ft_get_options(char **argv, int argc, t_op *ops);
t_op	*ft_init_ops(t_op *ops);
t_op	*ft_check_ops(char c, t_op *ops);

//DIRS MACROS
t_dirs	*ft_init_napa_chain(char *file_name, char *path_name);
t_dirs	*ft_new_napa_next(t_dirs *dirs, char *file_name, char *path_name);
t_dirs	*ft_del_curr(t_dirs *get_prev, t_dirs *dirs);
t_dirs	*ft_del_files(t_dirs *get_prev, t_dirs *dirs)
t_dirs	*ft_new_na_next(t_dirs *dirs, char *name);

//UTILITY
char	*ft_strclip(char *path, char *name, char *new_dirs);
char	*ft_strcpy(char *dest, const char *src);
void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int n);
size_t	ft_strlen(const char *s);
int		ft_get_digit(int n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_check_if_dirs(t_dirs	*dirs);
int		ft_name(char *str);
int		ft_hidden(char *str);
char	*ft_end(char *str);
void	ft_set_file(t_dirs *dirs, const char type);

#endif
