/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dir_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgil-mun <kgil-mun@student.42barcelo>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 19:08:25 by kgil-mun          #+#    #+#             */
/*   Updated: 2025/02/01 19:09:00 by kgil-mun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_hex_print(unsigned long num)
{
	int		count;
	char	digit;

	count = 0;
	if (num >= 16)
		count += ft_hex_print(num / 16);
	if (num % 16 >= 0 && num % 16 <= 9)
		digit = num % 16 + '0';
	if (num % 16 >= 10 && num % 16 <= 15)
		digit = num % 16 + 87;
	count += ft_print_char(digit);
	return (count);
}

int	ft_print_dir_ptr(void *p)
{
	int				count;
	unsigned long	dir;

	if (p == NULL)
	{
		write(1, "(nil)", 5);
		count = 5;
		return (count);
	}
	dir = (unsigned long)p;
	count = 2;
	write(1, "0x", 2);
	count += ft_hex_print(dir);
	return (count);
}
