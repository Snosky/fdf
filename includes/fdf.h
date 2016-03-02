/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:21:19 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/02 17:04:09 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <libft.h>
# include <get_next_line.h>
# include <stdlib.h>
# include <fcntl.h>

# define WIN_SX 1920
# define WIN_SY 1080
# define PX_SPACE 32

# define FDF_REFRESH 1
# define FDF_EXIT -1
# define FDF_WAIT 0

typedef struct	s_imgpx
{
	int	color;
	int	x;
	int	y;
}				t_imgpx;

typedef struct	s_px
{
	int	x;
	int	y;
	int	z;
}				t_px;

typedef struct	s_line
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	xinc;
	int	yinc;
}				t_line;

typedef struct	s_img
{
	void	*img;
	char	*data;
	int		bpx;
	int		sizeline;
	int		endian;
	int		clrline;
	int		pos_x;
	int		pos_y;
}				t_img;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	t_list	*map;
	t_px	px;
	t_line	line;
	t_img	img;
	int		max_y_map;
	int		max_x_map;
	int		status;
	int		pxspace;
}				t_env;

t_env			*init_env(char *filename);
void			get_map(char *filename, t_env *env);
void			draw_map(t_env *env);
void			draw_line(t_px px1, t_px px2, t_env *env);
void			ft_err_filename(char *filename, char *error);
void			ft_px_img(t_env *env, t_line line);
int				key_hook(int keycode, t_env *env);
int				loop_hook(t_env *env);
int				mouse_hook(int button, int x, int y, t_env *env);
void			ft_px_img(t_env *env, t_line line);
int				expose_hook(t_env *env);
#endif
