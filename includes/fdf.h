/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:21:19 by tpayen            #+#    #+#             */
/*   Updated: 2016/02/27 18:27:46 by tpayen           ###   ########.fr       */
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
# define PX_SPACE 64

typedef struct	s_px
{
	int	x;
	int	y;
	int	z;
}				t_px;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	t_list	**map;
	t_px	px;
	void	*map_img;
	int		max_y_map;
	int		max_x_map;
	int		ratio;
}				t_env;

t_env	*init_env(char *filename);
void	get_map(char *filename, t_env *env);
void	draw_map(t_env *env);
void	draw_line(int xi, int yi, int xf, int yf, void *mlx, void *win);
void	ft_err_filename(char *filename, char *error);
#endif
