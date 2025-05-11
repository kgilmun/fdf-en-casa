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

#include "fdf.h"

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return;
	char	*dst = vars->addr + (y * vars->line_length + x * (vars->bpp / 8));
	*(unsigned int *)dst = color;
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

void	open_window(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return ;

	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "fdf");
	if (!vars->win)
		return ;

	vars->img = mlx_new_image(vars->mlx, 2000, 1500);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bpp, &vars->line_length, &vars->endian);

	draw_map(vars);  // ahora dibuja sobre la imagen

	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);  // muestra la imagen

	mlx_hook(vars->win, 17, 0, close_window, vars);
	ft_hook_controls(vars);
	mlx_loop(vars->mlx);
}



