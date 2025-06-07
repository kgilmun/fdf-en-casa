/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgil-mun <kgil-mun@student.42barcelo>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 11:07:30 by kgil-mun          #+#    #+#             */
/*   Updated: 2025/04/26 16:03:58 by kgil-mun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 1500
# define HEIGHT 1500
# define SCALE 700
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define ARROW_DOWN 65364
# define ARROW_UP 65362
# define ESC 65307
# define ISO_ANGLE 0.523599f
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include "get_next_line.h"
# include "libft.h"

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		offset_x;
	int		offset_y;
	int		width;
	int		height;
	t_point	**points;
}	t_vars;

typedef struct s_line
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}	t_line;

void	open_window(t_vars *vars);
void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
int		close_window(void *param);
int		**create_matrix(int width, int height, int fd);
void	free_split(char **split);
void	free_matrix(int **matrix, int height);
int		count_map_dimensions(char *filename, t_vars *vars);
int		**create_matrix(int width, int height, int fd);
void	free_split(char **split);
t_point	**store_points(int **matriz, int height, int width);
void	draw_line(t_vars *vars, t_point p0, t_point p1);
void	draw_map(t_vars *vars);
void	apply_isometric(t_point *p);
void	ft_arrow_move(int keycode, t_vars *vars);
int		ft_keypress(int keycode, void *params);
void	ft_hook_controls(t_vars *var);
void	clear_image(t_vars *vars);
float	get_fraction(int start, int end, int current);
int		interpolate_color(int color1, int color2, float fraction);
void	draw_line_pixels(t_vars *vars, t_point p0, t_point p1, t_line *line);
float	calculate_scale(t_vars *vars);
void	draw_connections(t_vars *vars, float scale, int i, int j);
void	init_offsets(t_vars *vars);
void	calculate_offsets(t_vars *vars);
int		invalid_map(char *filename, t_vars *vars);

#endif
