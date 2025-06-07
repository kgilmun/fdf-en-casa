/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgil-mun <kgil-mun@student.42barcelo>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 08:40:51 by kgil-mun          #+#    #+#             */
/*   Updated: 2025/05/11 08:46:16 by kgil-mun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_arrow_move(int keycode, t_vars *vars)
{
	if (keycode == ARROW_LEFT)
		vars->offset_x -= 10;
	else if (keycode == ARROW_RIGHT)
		vars->offset_x += 10;
	else if (keycode == ARROW_DOWN)
		vars->offset_y += 10;
	else if (keycode == ARROW_UP)
		vars->offset_y -= 10;
	draw_map(vars);
}

int	ft_keypress(int keycode, void *params)
{
	t_vars	*vars;

	vars = (t_vars *)params;
	if (keycode == ARROW_LEFT || keycode == ARROW_RIGHT
		|| keycode == ARROW_DOWN || keycode == ARROW_UP)
		ft_arrow_move(keycode, vars);
	else if (keycode == ESC)
		close_window(vars);
	return (0);
}

void	ft_hook_controls(t_vars *var)
{
	mlx_hook(var->win, 2, 1L << 0, ft_keypress, var);
}
