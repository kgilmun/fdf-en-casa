/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgil-mun <kgil-mun@student.42barcelon>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:49:23 by kgil-mun          #+#    #+#             */
/*   Updated: 2025/01/05 16:13:54 by kgil-mun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void			*p;

	if (num == 0 || size == 0)
	{
		p = malloc(0);
		if (p == NULL)
			return (NULL);
		return (p);
	}
	if (num > SIZE_MAX / size)
		return (NULL);
	p = malloc(num * size);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, size * num);
	return (p);
}
