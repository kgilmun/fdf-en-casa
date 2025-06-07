/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgil-mun <kgil-mun@student.42barcelo>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 15:33:54 by kgil-mun          #+#    #+#             */
/*   Updated: 2025/06/07 15:35:04 by kgil-mun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_words(char **split)
{
	int	count;

	count = 0;
	while (split[count])
		count++;
	return (count);
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
			vars->width = count_words(split);
		free_split(split);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (0);
}

static int	line_width_invalid(char **split, int expected_width)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i != expected_width);
}

int	invalid_map(char *filename, t_vars *vars)
{
	int		fd;
	char	*line;
	char	**split;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		split = ft_split(line, ' ');
		if (line_width_invalid(split, vars->width))
		{
			free_split(split);
			free(line);
			close(fd);
			return (1);
		}
		free_split(split);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
