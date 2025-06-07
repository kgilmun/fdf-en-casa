/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgil-mun <kgil-mun@student.42barcelo>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 16:02:25 by kgil-mun          #+#    #+#             */
/*   Updated: 2025/06/07 16:02:59 by kgil-mun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_image(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	while (x < 2000)
	{
		y = 0;
		while (y < 1500)
		{
			my_mlx_pixel_put(vars, x, y, 0x000000);
			y++;
		}
		x++;
	}
}

void	apply_isometric(t_point *p)
{
	float	z_scale;
	int		prev_x;
	int		prev_y;

	z_scale = 0.2;
	prev_x = p->x;
	prev_y = p->y;
	p->x = (prev_x - prev_y) * cos(0.523599);
	p->y = (prev_x + prev_y) * sin(0.523599) - (p->z * z_scale);
}
