/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgil-mun <kgil-mun@student.42barcelo>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:24:36 by kgil-mun          #+#    #+#             */
/*   Updated: 2025/02/01 11:13:44 by kgil-mun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	conditional(char str, va_list args)
{
	int	num;

	num = 0;
	if (str == 'c')
		num += ft_print_char(va_arg(args, int));
	else if (str == 's')
		num += ft_print_str(va_arg(args, char *));
	else if (str == 'p')
		num += ft_print_dir_ptr(va_arg(args, void *));
	else if (str == 'd' || str == 'i')
		num += ft_print_nbr(va_arg(args, int));
	else if (str == 'u')
		num += ft_print_unsigned(va_arg(args, unsigned int));
	else if (str == 'x')
		num += ft_print_hex(va_arg(args, unsigned int));
	else if (str == 'X')
		num += ft_print_upper_hex(va_arg(args, unsigned int));
	else if (str == '%')
		num += ft_print_char('%');
	else
	{
		num += ft_print_char('%');
		num += ft_print_char(str);
	}
	return (num);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			count += conditional(str[i], args);
		}
		else
			count += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
