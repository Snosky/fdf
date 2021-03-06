/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 15:31:53 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/02 16:47:02 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	open_file(char *filename)
{
	int	fd;

	if ((fd = open(filename, O_RDONLY)) == -1)
		ft_err_filename(filename, "No such file");
	return (fd);
}

static void	do_split(char *line, t_env *env)
{
	char	**split;

	split = ft_strsplit(line, ' ');
	env->px.x = 0;
	while (*split)
	{
		env->px.z = ft_atoi(*split);
		ft_lstadd(&(env->map), ft_lstnew(&(env->px), sizeof(t_px)));
		env->px.x++;
		free(*split++);
	}
}

void		get_map(char *filename, t_env *env)
{
	int		fd;
	int		gnl;
	char	*line;

	fd = open_file(filename);
	env->max_x_map = -1;
	while ((gnl = get_next_line(fd, &line)))
	{
		if (gnl == -1)
			ft_err_filename(filename, "Read error");
		do_split(line, env);
		if (env->max_x_map != -1 && env->max_x_map != env->px.x)
			ft_err_filename(filename, "Map invalid");
		env->max_x_map = env->px.x;
		env->px.y++;
	}
	env->max_y_map = env->px.y;
}
