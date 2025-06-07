/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgil-mun <kgil-mun@student.42barcelo>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 10:08:27 by kgil-mun          #+#    #+#             */
/*   Updated: 2025/05/17 10:08:41 by kgil-mun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

float	calculate_scale(t_vars *vars)
{
	int		map_width;
	int		map_height;
	float	projected_width;
	float	projected_height;
	float	scale_x;
	float	scale_y;

	map_width = vars->width;
	map_height = vars->height;
	projected_width = (map_width + map_height) * cos(ISO_ANGLE);
	projected_height = (map_width + map_height) * sin(ISO_ANGLE);
	scale_x = 2000.0 / projected_width;
	scale_y = 1500.0 / projected_height;
	if (scale_x < scale_y)
		return (scale_x);
	else
		return (scale_y);
}

void	draw_connections(t_vars *vars, float scale, int i, int j)
{
	t_point	p;
	t_point	p_right;
	t_point	p_down;

	p = vars->points[i][j];
	p.x *= scale;
	p.y *= scale;
	p.z *= scale;
	if (j < vars->width - 1)
	{
		p_right = vars->points[i][j + 1];
		p_right.x *= scale;
		p_right.y *= scale;
		p_right.z *= scale;
		draw_line(vars, p, p_right);
	}
	if (i < vars->height - 1)
	{
		p_down = vars->points[i + 1][j];
		p_down.x *= scale;
		p_down.y *= scale;
		p_down.z *= scale;
		draw_line(vars, p, p_down);
	}
}

void	init_offsets(t_vars *vars)
{
	float	projected_width;
	float	projected_height;
	float	scale;

	projected_width = (vars->width + vars->height) * cos(ISO_ANGLE);
	projected_height = (vars->width + vars->height) * sin(ISO_ANGLE);
	scale = calculate_scale(vars);
	vars->offset_x = (2000 - projected_width * scale) / 2;
	vars->offset_y = (1500 - projected_height * scale) / 2;
}
