/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgil-mun <kgil-mun@student.42barcelo>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 10:49:17 by kgil-mun          #+#    #+#             */
/*   Updated: 2025/04/26 10:49:41 by kgil-mun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>
#include "get_next_line.h"
#include "libft.h"
#include "fdf.h"

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	int offset = (y * vars->line_length) + (x * (vars->bpp / 8));
	*(unsigned int *)(vars->addr + offset) = color;
}

void	draw_horizontal_line(t_vars *vars, int y, int color, int width)
{
	int x = 0;
	while (x < width)
	{
		my_mlx_pixel_put(vars, x, y, color);
		x++;
	}
}

void	draw_vertical_line(t_vars *vars, int x, int color, int height)
{
	int y = 0;
	while (y < height)
	{
		my_mlx_pixel_put(vars, x, y, color);
		y++;
	}
}

int	close_window(void *param)
{
	t_vars *vars = (t_vars *)param;
	if (vars->img)
		mlx_destroy_image(vars->mlx, vars->img);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

void	open_window (t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return ;

	vars->win = mlx_new_window(vars->mlx, 2000, 1500, "Mi primera ventana");
	if (!vars->win)
		return ;
		
	vars->img = mlx_new_image(vars->mlx, 2000, 1500);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bpp, &vars->line_length, &vars->endian);

	// Dibuja
	my_mlx_pixel_put(vars, 100, 100, 0xFFFFFF);
	draw_horizontal_line(vars, 200, 0xFF0000, 2000); // rojo
	draw_vertical_line(vars, 400, 0x00FF00, 1500);   // verde

	// Muestra imagen
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);

	// Hook de cierre
	mlx_hook(vars->win, 17, 0, close_window, vars);

	// Bucle de eventos
	mlx_loop(vars->mlx);
}


