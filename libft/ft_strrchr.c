/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgil-mun <kgil-mun@student.42barcelon>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 13:22:50 by kgil-mun          #+#    #+#             */
/*   Updated: 2025/01/05 16:10:39 by kgil-mun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char			*fletter;
	int				i;
	unsigned char	value;

	fletter = NULL;
	value = (unsigned char)c;
	if (value == '\0')
		return ((char *)(str + ft_strlen(str)));
	i = 0;
	while (str[i])
	{
		if (str[i] == value)
			fletter = (char *)&str[i];
		i++;
	}
	return (fletter);
}
