/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_px_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@studio.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 16:09:28 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/02 16:45:41 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_px_img(t_env *env, t_line line)
{
	t_imgpx	imgpx;

	if (line.x > 0 && line.x < WIN_SX && line.y > 0 && line.y < WIN_SY)
	{
		imgpx.color = 0x00FFFFFF;
		imgpx.x = line.x;
		imgpx.y = line.y;
		ft_memcpy(&env->img.data[(line.x * 4) + (line.y * env->img.sizeline)],\
			&(imgpx), (size_t)(sizeof(int)));
	}
}
