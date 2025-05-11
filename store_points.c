/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_points.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgil-mun <kgil-mun@student.42barcelo>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:04:16 by kgil-mun          #+#    #+#             */
/*   Updated: 2025/04/26 16:27:41 by kgil-mun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

t_point	**store_points(int **matriz, int height, int width)
{
	t_point	**points;
	int	i;
	int	j;

	points = (t_point **)malloc(height * sizeof(t_point *));
	if (!points)
		return (NULL);
	i = 0;
	while (i < height)
	{
		points[i] = (t_point *)malloc(width * sizeof(t_point));
		if (!points[i])
			return (NULL);
		j = 0;
		while (j < width)
		{
			points[i][j].x = j * SCALE;
			points[i][j].y = i * SCALE;
			points[i][j].z = matriz[i][j] * SCALE;
			if (matriz[i][j] == 0)
				points[i][j].color = 0xFFFFFF; // blanco
			else if (matriz[i][j] < 0)
				points[i][j].color = 0x00FF00 + (matriz[i][j] * 1000);
			else
				points[i][j].color = 0xFF00FF + (matriz[i][j] * 1000);
			j++; 
			
		}
		i++;
	}
	/*i = 0;

	while (i < height)
	{
    		j = 0;
    		while (j < width)
    		{
        		printf("Punto (%d, %d): x=%d, y=%d, z=%d\n",
               		i, j,
               		points[i][j].x,
               		points[i][j].y,
               		points[i][j].z);
        		j++;
    		}
    		i++;
	}
*/
	return (points);	
}
