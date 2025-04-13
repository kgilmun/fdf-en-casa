/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgil-mun <kgil-mun@student.42barcelon>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 12:09:01 by kgil-mun          #+#    #+#             */
/*   Updated: 2025/01/05 16:10:14 by kgil-mun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int				i;
	unsigned char	value;

	i = 0;
	value = (unsigned char)c;
	while (str[i])
	{
		if (str[i] == value)
			return ((char *)(str + i));
		i++;
	}
	if (value == '\0')
		return ((char *)str);
	return (NULL);
}
