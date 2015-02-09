/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/08 19:12:02 by mgras             #+#    #+#             */
/*   Updated: 2015/02/09 11:08:34 by mgras            ###   ########.fr       */
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

typedef struct		s_off
{
	int				link;
	int				uid;
	int				gid;
	int				size;
}					t_off;

typedef struct		s_op
{
	int				rr;
	int				t;
	int				r;
	int				l;
	int				a;
	int				err;
}					t_op;

typedef struct		s_lsl
{
	int				block;
	int				major;
	int				minor;
	mode_t			mode;
	nlink_t			hardlink;
	uid_t			uid;
	gid_t			gid;
	off_t			size;
	struct timespec	st_mtimespec;
}					t_lsl;

typedef struct		s_dirs
{
	char			*name;
	int				file;
	struct s_lsl	*lsl;
	struct s_dirs	*next;
}					t_dirs;

t_dirs				*ft_init_napa_chain(char *file_name, char *path_name);
t_dirs				*ft_new_napa_next(t_dirs *dirs,
	char *file_name, char *path_name);
t_dirs				*ft_new_na_next(t_dirs *dirs, char *name);
t_dirs				*ft_crea_inst(char *na, char *pa, t_dirs *ins);
t_dirs				*ft_solo_inst(t_dirs *dirs, t_op *ops, t_off *off);
t_dirs				*ft_solo_init(t_dirs *dirs, t_op *ops, int head);
t_dirs				*ft_init_r(t_dirs *new_instance, char *d_name, char *name);
t_dirs				*ft_process_r(t_dirs *dirs, t_dirs *nins,
	t_dirs *save, t_op *ops);
t_dirs				*ft_get_dirs(char **argv, int argc, t_dirs *dirs);
void				ft_del_curr(t_dirs *dirs);
void				ft_test_usr_dirs(t_dirs *dirs);
void				ft_process_inst(t_dirs *ins, t_op *ops);
void				ft_file_lsl(t_lsl *dirs, char *name);
void				ft_fill_off_file(t_off *off, t_dirs *dirs, t_op *ops);
void				ft_fill_off_all(t_off *off, t_dirs *dirs, t_op *ops);
void				ft_off(t_off *off, t_dirs *tmp);
void				ft_init_off(t_off *off);
void				ft_get_recursive(t_dirs *dirs, t_op *ops);
void				ft_disp_files(t_op *ops, t_dirs *dirs, t_dirs *last);
void				ft_mecha_init(t_op *ops, t_dirs *dirs);
void				ft_swap_afile_name(t_dirs *a);
void				ft_swap_core(t_dirs *a);
void				ft_print_file(t_op *ops, t_lsl *lsl,
	t_dirs *dirs, t_off *off);
void				ft_print_head(char *head, t_dirs *dirs, t_op *ops);
void				ft_print_total(t_dirs *dirs);
void				ft_op_error(int index, char err);
void				ft_usr_dirs_err(char *erred_dir);
void				ft_forbiden_access(char *erred_dir);
void				ft_error_head(t_dirs *dirs);
void				ft_cycle_errors(t_dirs *dirs, int head);
void				ft_put_st_mode(mode_t mode);
void				ft_put_restrict(mode_t mode);
void				ft_put_st_nlinks(nlink_t links, int offset);
void				ft_put_uid(uid_t uid, int offset);
void				ft_put_st_dev(int major, int minor, int offset);
void				ft_put_gid(gid_t gid, int offset);
void				ft_put_size(size_t size, int offset);
void				ft_oldfag(char *timestamp, int i);
void				ft_put_modtime(struct timespec st_mtimespec);
void				ft_alphasort(t_dirs *a);
void				time_stamp_sort(t_dirs *a);
void				rev_time_stamp_sort(t_dirs *a);
void				rev_alphasort(t_dirs *a);
void				ft_free_all(t_dirs *ins);
void				ft_dat_backn(t_off *off, t_dirs *dirs);
void				ft_putchar_err(char c);
void				ft_putstr_fd(char *str);
void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putnbr(int n);
void				ft_set_file(t_dirs *dirs);
void				ft_core_sorting(t_dirs *all, t_op *ops);
t_op				*ft_get_options(char **argv, int argc, t_op *ops);
t_op				*ft_init_ops(t_op *ops);
t_op				*ft_check_ops(char c, t_op *ops);
int					get_nlink_off(nlink_t links);
int					get_uid_off(uid_t uid);
int					get_gid_off(gid_t gid);
int					get_size_off(size_t size);
int					get_dev_off(t_lsl *lsl);
int					ft_check_if_dirs(t_dirs *dirs);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_get_digit(int n);
int					ft_name(char *str);
int					ft_blank_out(char *str, int size);
int					ft_search_err(t_dirs *dirs);
int					ft_hidden(char *str);
char				*ft_strclip(char *path, char *name, char *new_dirs);
char				*ft_end(char *str);
char				*ft_strcpy(char *dest, const char *src);
size_t				ft_strlen(const char *s);

#endif
