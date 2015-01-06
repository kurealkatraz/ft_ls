/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nowl <nowl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 11:58:16 by nowl              #+#    #+#             */
/*   Updated: 2015/01/06 19:00:47 by nowl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdlib.h>
# include <unistd.h>

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
	char	*path;
	char	*name;
	t_dirs	*next;
	
}				t_dirs;

void	ft_op_error(int index, char err);

//CORE
t_op	*ft_get_options(char **argv, int argc, t_op *ops);
t_dirs	*ft_get_dirs(char **argv, int argc, t_dirs *dirs);

//OP MACROS
t_op	*ft_get_options(char **argv, int argc, t_op *ops);
t_op	*ft_init_ops(t_op *ops);
t_op	*ft_check_ops(char c, t_op *ops);

//DIRS MACROS
t_dirs	*ft_new_name_end(t_dirs *dirs, char	*str);

//UTILITY
char	*ft_strncpy(char *dest, const char *src, size_t n);
void	ft_putstr(char *str);
void	ft_putchar(char c);
size_t	ft_strlen(const char *s);

#endif