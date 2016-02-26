/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 15:31:53 by tpayen            #+#    #+#             */
/*   Updated: 2016/02/26 16:32:35 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_err_filename(char *filename)
{
	ft_putstr_fd("fdf: ", 2);
	ft_putstr_fd(filename, 2);
	ft_putendl_fd(": No such file", 2);
	exit(EXIT_FAILURE);
}

static void	ft_err_readfile(char *filename)
{
	ft_putstr_fd("fdf: ", 2);
	ft_putstr_fd(filename, 2);
	ft_putendl_fd(": Read error", 2);
	exit(EXIT_FAILURE);
}

static void	ft_err_map(char *filename)
{
	ft_putstr_fd("fdf: ", 2);
	ft_putstr_fd(filename, 2);
	ft_putendl_fd(": Map invalid", 2);
	exit(EXIT_FAILURE);
}

void	get_map(char *filename, t_env *env)
{
	int	fd;
	int	gnl;
	char	*line;
	char	**split;
	int		max_line;

	if ((fd = open(filename, O_RDONLY)) == -1)
		ft_err_filename(filename);
	env->px.y = 0;
	max_line = -1;
	while ((gnl = get_next_line(fd, &line)))
	{
		if (gnl == -1)
			ft_err_readfile(filename);
		env->px.x = 0;
		split = ft_strsplit(line, ' ');
		while (*split)
		{
			env->px.z = ft_atoi(*split);
			ft_lstadd(&(env->map), ft_lstnew(&(env->px), sizeof(t_px)));
			env->px.x++;
			free(*split++);
		}
		if (max_line != -1 && max_line != env->px.x)
			ft_err_map(filename);
		max_line = env->px.x;
		env->px.y++;
		free(line);
	}
}
