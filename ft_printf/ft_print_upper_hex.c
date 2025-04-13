/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_upper_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgil-mun <kgil-mun@student.42barcelo>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:47:07 by kgil-mun          #+#    #+#             */
/*   Updated: 2025/02/01 16:50:01 by kgil-mun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_upper_hex(unsigned int num)
{
	int		count;
	char	digit;

	count = 0;
	if (num >= 16)
		count += ft_print_upper_hex(num / 16);
	if (num % 16 >= 0 && num % 16 <= 9)
		digit = num % 16 + '0';
	if (num % 16 >= 10 && num % 16 <= 15)
		digit = num % 16 + 55;
	count += ft_print_char(digit);
	return (count);
}
