/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgil-mun <kgil-mun@student.42barcelo>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 11:27:50 by kgil-mun          #+#    #+#             */
/*   Updated: 2025/04/27 11:29:38 by kgil-mun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_image(t_vars *vars)
{
	int x, y;
	x = 0;
	while (x < 2000)
	{
		y = 0;
		while (y < 1500)
		{
			my_mlx_pixel_put(vars, x, y, 0x000000); // fondo negro
			y++;
		}
		x++;
	}
}

void apply_isometric(t_point *p)
{
	float z_scale = 0.1;
	int prev_x = p->x;
	int prev_y = p->y;

	p->x = (prev_x - prev_y) * cos(0.523599); // 30° en radianes
	p->y = (prev_x + prev_y) * sin(0.523599) - (p->z * z_scale);
}

void draw_line(t_vars *vars, t_point p0, t_point p1)
{
	t_line line;

	apply_isometric(&p0);
	apply_isometric(&p1);

	// Aplicar centrado
	p0.x += vars->offset_x;
	p0.y += vars->offset_y;
	p1.x += vars->offset_x;
	p1.y += vars->offset_y;

	line.dx = abs(p1.x - p0.x);
	line.dy = abs(p1.y - p0.y);
	line.sx = (p0.x < p1.x) ? 1 : -1;
	line.sy = (p0.y < p1.y) ? 1 : -1;
	line.err = line.dx - line.dy;

	draw_line_pixels(vars, p0, p1, &line);
}

void draw_line_pixels(t_vars *vars, t_point p0, t_point p1, t_line *line)
{
	int x = p0.x;
	int y = p0.y;
	float fraction;
	int color;

	while (x != p1.x || y != p1.y)
	{
		if (line->dx > line->dy)
			fraction = get_fraction(p0.x, p1.x, x);
		else
			fraction = get_fraction(p0.y, p1.y, y);

		color = interpolate_color(p0.color, p1.color, fraction);
		my_mlx_pixel_put(vars, x, y, color);

		line->e2 = 2 * line->err;
		if (line->e2 > -line->dy)
		{
			line->err -= line->dy;
			x += line->sx;
		}
		if (line->e2 < line->dx)
		{
			line->err += line->dx;
			y += line->sy;
		}
	}
	color = interpolate_color(p0.color, p1.color, 1.0);
	my_mlx_pixel_put(vars, x, y, color);
}


void draw_map(t_vars *vars)
{
	int i, j;

	clear_image(vars);

	i = 0;
	while (i < vars->height)
	{
		j = 0;
		while (j < vars->width)
		{
			if (j < vars->width - 1)
				draw_line(vars, vars->points[i][j], vars->points[i][j + 1]);
			if (i < vars->height - 1)
				draw_line(vars, vars->points[i][j], vars->points[i + 1][j]);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
