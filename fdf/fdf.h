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
#define FDF_H

#define SCALE 50
#include <math.h>

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
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
	int		height;
	int		width;
	t_point	**points;
	int offset_x;
	int offset_y;
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
void	draw_vertical_line(t_vars *vars, int x, int color, int height);
void	draw_horizontal_line(t_vars *vars, int y, int color, int width);
void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
int	close_window(void *param);
int	**create_matrix(int width, int height, int fd);
void free_split(char **split);
void	free_matrix(int **matrix, int height);
void	print_matrix(int **matrix, int width, int height);
int	count_map_dimensions(char *filename, t_vars *vars);
int	**create_matrix(int width, int height, int fd);
void	free_split(char **split);
t_point	**store_points(int **matriz, int height, int width);
void draw_line(t_vars *vars, t_point p0, t_point p1);
void draw_map(t_vars *vars);
void apply_isometric(t_point *p);

#endif
