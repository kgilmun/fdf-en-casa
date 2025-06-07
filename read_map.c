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
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

static void	fill_matrix_row(int *row, char **split, int width)
{
	int	j;

	j = 0;
	while (j < width)
	{
		row[j] = ft_atoi(split[j]);
		j++;
	}
}

int	**create_matrix(int width, int height, int fd)
{
	int		**matrix;
	char	*line;
	char	**split;
	int		i;

	i = 0;
	matrix = (int **)malloc(height * sizeof(int *));
	if (!matrix)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		split = ft_split(line, ' ');
		matrix[i] = (int *)malloc(width * sizeof(int));
		fill_matrix_row(matrix[i], split, width);
		free_split(split);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	return (matrix);
}

void	free_matrix(int **matrix, int height)
{
	int	i;

	i = 0;
	while (i < height)
		free(matrix[i++]);
	free(matrix);
}
