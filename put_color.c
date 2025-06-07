/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgil-mun <kgil-mun@student.42barcelo>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 10:42:56 by kgil-mun          #+#    #+#             */
/*   Updated: 2025/05/11 10:44:32 by kgil-mun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	interpolate_color(int color1, int color2, float fraction)
{
	int	r1;
	int	g1;
	int	b1;
	int	r2;
	int	g2;
	int	b2;
	int	r;
	int	g;
	int	b;

	r1 = (color1 >> 16) & 0xFF;
	g1 = (color1 >> 8) & 0xFF;
	b1 = color1 & 0xFF;
	r2 = (color2 >> 16) & 0xFF;
	g2 = (color2 >> 8) & 0xFF;
	b2 = color2 & 0xFF;
	r = r1 + (r2 - r1) * fraction;
	g = g1 + (g2 - g1) * fraction;
	b = b1 + (b2 - b1) * fraction;
	return (r << 16 | g << 8 | b);
}

float	get_fraction(int start, int end, int current)
{
	if (start == end)
		return (0.0);
	return ((float)(current - start) / (end - start));
}
