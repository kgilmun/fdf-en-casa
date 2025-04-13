/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgil-mun <kgil-mun@student.42barcelon>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 11:30:04 by kgil-mun          #+#    #+#             */
/*   Updated: 2025/01/05 16:06:51 by kgil-mun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *p, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)p;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}
