/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_px_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@studio.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 16:09:28 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/01 16:20:48 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_px_img(t_env *env, t_line line)
{
(void)env;
(void)line;
	//ft_memcpy(&env->img.data[(line.x * 4) + (line.y * env->img.sizeline)],\
	//	&(env->img.clrline), (size_t)(sizeof(int)));
}
