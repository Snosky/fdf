/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@studio.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 23:42:56 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/02 17:00:18 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_hook(int button, int x, int y, t_env *env)
{
	(void)x;
	(void)y;
	if (button == 5)
	{
		if (env->pxspace - 1 > 0)
		{
			env->pxspace--;
			env->status = FDF_REFRESH;
		}
	}
	else if (button == 4)
	{
		env->pxspace++;
		env->status = FDF_REFRESH;
	}
	else if (button == 2)
	{
		env->pxspace = PX_SPACE;
		env->status = FDF_REFRESH;
	}
	return (0);
}
