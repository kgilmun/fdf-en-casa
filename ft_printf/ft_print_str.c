/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgil-mun <kgil-mun@student.42barcelo>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:41:34 by kgil-mun          #+#    #+#             */
/*   Updated: 2025/02/01 12:41:39 by kgil-mun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *s)
{
	int	num;

	if (!s)
		return (ft_print_str("(null)"));
	num = 0;
	while (s[num] != '\0')
	{
		ft_print_char(s[num]);
		num++;
	}
	return (num);
}
