/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgil-mun <kgil-mun@student.42barcelon>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:42:13 by kgil-mun          #+#    #+#             */
/*   Updated: 2025/01/05 16:07:46 by kgil-mun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*initial;
	unsigned char	*final;

	initial = (unsigned char *)src;
	final = (unsigned char *)dest;
	if (final > initial)
	{
		while (len > 0)
		{
			len--;
			final[len] = initial[len];
		}
	}
	else
	{
		ft_memcpy(final, initial, len);
	}
	return (final);
}
