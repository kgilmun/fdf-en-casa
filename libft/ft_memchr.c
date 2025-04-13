/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgil-mun <kgil-mun@student.42barcelon>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:28:40 by kgil-mun          #+#    #+#             */
/*   Updated: 2025/01/05 16:11:59 by kgil-mun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			count;
	unsigned char	value;

	p = (unsigned char *)s;
	value = (unsigned char)c;
	count = 0;
	while (count < n)
	{
		if (*p == value)
			return (p);
		p++;
		count++;
	}
	return (NULL);
}
