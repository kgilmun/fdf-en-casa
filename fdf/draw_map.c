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

#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>
#include "get_next_line.h"
#include "libft.h"
#include "fdf.h"

void draw_line(t_vars *vars, t_point p0, t_point p1)
{
    t_line line;

    line.dx = abs(p1.x - p0.x);
    line.dy = abs(p1.y - p0.y);
    line.sx = (p0.x < p1.x) ? 1 : -1;
    line.sy = (p0.y < p1.y) ? 1 : -1;
    line.err = line.dx - line.dy;

    while (1)
    {
        mlx_pixel_put(vars->mlx, vars->win, p0.x, p0.y, 0xFFFFFF);
        if (p0.x == p1.x && p0.y == p1.y)
            break;
        line.e2 = 2 * line.err;
        if (line.e2 > -line.dy)
        {
            line.err -= line.dy;
            p0.x += line.sx;
        }
        if (line.e2 < line.dx)
        {
            line.err += line.dx;
            p0.y += line.sy;
        }
    }
}

void draw_map(t_vars *vars)
{
    int i;
    int j;

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
}
