/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgil-mun <kgil-mun@student.42barcelon>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:53:15 by kgil-mun          #+#    #+#             */
/*   Updated: 2025/01/05 16:13:31 by kgil-mun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	printnum(const char *str, int *result, int i)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		*result = *result * 10 + (str[i] - '0');
		i++;
	}
}

int	ft_atoi(const char *str)
{
	int	i;
	int	signo;
	int	result;

	i = 0;
	signo = 1;
	result = 0;
	if (str[i] != '\0')
	{
		while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
			i++;
		if (str[i] == '\0')
			return (0);
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				signo = -1;
			i++;
		}
		if (str[i] < '0' || str[i] > '9')
			return (0);
		printnum(str, &result, i);
		return (result * signo);
	}
	return (0);
}
