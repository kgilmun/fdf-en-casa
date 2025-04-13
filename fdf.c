/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgil-mun <kgil-mun@student.42barcelo>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:29:35 by kgil-mun          #+#    #+#             */
/*   Updated: 2025/04/05 11:40:47 by kgil-mun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
int main (int argc, char **argv)
{
	int fd;
	int rd;
	int *buff;

	if (argc == 2)
	{
		fd = open(argv[1], RD_ONLY);
		if (fd == -1)
		{
			printf("no se pudo abrir el archivo\n");
			return 1;
		}
		buff = (int *)malloc(sizeof(int));
		rd = 1;
		while (rd)
		{	
			rd = read(fd, buff, 1);
			if (rd < 0)
			{
				printf("No se pudo leer el archivo\n)"
				return (1);
			}
		}
	}
	return 0;
}
