/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:21:19 by tpayen            #+#    #+#             */
/*   Updated: 2016/02/26 16:16:40 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
#include <mlx.h>
#include <libft.h>
#include <get_next_line.h>
#include <stdlib.h>

#define WIN_SX 1920
#define WIN_SY 1080

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
	t_list	*map;
	t_px	px;
}				t_env;

t_env	*init_env(char *filename);
void	get_map(char *filename, t_env *env);

#endif
