/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgil-mun <kgil-mun@student.42barcelo>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 11:44:38 by kgil-mun          #+#    #+#             */
/*   Updated: 2025/04/26 11:49:28 by kgil-mun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>
#include "get_next_line.h"
#include "libft.h"
#include "fdf.h"

void	free_split(char **split)
{
	int	i = 0;

	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	**create_matrix(int width, int height, int fd)
{
	int	**matriz;
	char	**split;
	char	*line;
	int	i = 0;
	int	j;

	line = get_next_line(fd);
	matriz = (int **)malloc(height * sizeof(int *));
	if (!matriz)
		return (NULL);
	while (line)
	{
		split = ft_split(line, ' ');
		matriz[i] = (int *)malloc(width * sizeof(int));
		j = 0;
		while (j < width)
		{
			matriz[i][j] = ft_atoi(split[j]);
			j++;
		}
		free_split(split);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	return (matriz);
}

int	count_map_dimensions(char *filename, t_vars *vars)
{
	int		fd;
	char	*line;
	char	**split;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (1);
	vars->height = 0;
	vars->width = 0;
	line = get_next_line(fd);
	while (line)
	{
		vars->height++;
		split = ft_split(line, ' ');
		if (vars->width == 0)
		{
			while (split[vars->width])
				vars->width++;
		}
		free_split(split);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (0);
}

void	print_matrix(int **matrix, int width, int height)
{
	int	i, j;

	i = 0;
	while (i < height)
	{
		printf("Fila %d:\n", i);
		j = 0;
		while (j < width)
		{
			printf("%d ", matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	free_matrix(int **matrix, int height)
{
	int	i = 0;

	while (i < height)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

