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


int	main(int argc, char **argv)
{
	t_vars	vars;
	t_point	**points;
	int		**matrix;
	int		fd;

	if (argc != 2)
		return (1);
	if (count_map_dimensions(argv[1], &vars))
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	matrix = create_matrix(vars.width, vars.height, fd);
	close(fd);
	if (!matrix)
		return (1);
	print_matrix(matrix, vars.width, vars.height);
	points = store_points(matrix, vars.height, vars.width);
	free_matrix(matrix, vars.height);
	open_window(&vars);
	return (0);
}


