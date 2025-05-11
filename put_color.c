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

int interpolate_color(int color1, int color2, float fraction)
{
	int r1 = (color1 >> 16) & 0xFF;
	int g1 = (color1 >> 8) & 0xFF;
	int b1 = color1 & 0xFF;

	int r2 = (color2 >> 16) & 0xFF;
	int g2 = (color2 >> 8) & 0xFF;
	int b2 = color2 & 0xFF;

	int r = r1 + (r2 - r1) * fraction;
	int g = g1 + (g2 - g1) * fraction;
	int b = b1 + (b2 - b1) * fraction;

	return (r << 16 | g << 8 | b);
}

float get_fraction(int start, int end, int current)
{
	if (start == end)
		return (0.0);
	return ((float)(current - start) / (end - start));
}
