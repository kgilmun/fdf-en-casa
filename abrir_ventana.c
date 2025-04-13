/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgil-mun <kgil-mun@student.42barcelo>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 10:17:44 by kgil-mun          #+#    #+#             */
/*   Updated: 2025/04/12 10:25:36 by kgil-mun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>

void	my_mlx_pixel_put(char *addr, int x, int y, int color, int line_length, int bpp)
{
	int	offset = (y * line_length) + (x * (bpp / 8));
	*(unsigned int *)(addr + offset) = color;
}

int	close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	// Inicializa la conexión con el servidor gráfico
	mlx = mlx_init();
	if (!mlx)
		return (1);

	// Crea una ventana
	win = mlx_new_window(mlx, 2000, 1500, "Mi primera ventana");
	if (!win)
		return (1);

	// Crea una imagen de 2000x1500 píxeles
	img = mlx_new_image(mlx, 2000, 1500);

	// Obtiene la dirección de memoria de la imagen para poder modificarla
	addr = mlx_get_data_addr(img, &bits_per_pixel, &line_length, &endian);

	// Pinta un píxel rojo en la posición (100, 100)
	my_mlx_pixel_put(addr, 100, 100, 0x00FF0000, line_length, bits_per_pixel); // rojo

	// Muestra la imagen en la ventana
	mlx_put_image_to_window(mlx, win, img, 0, 0);

	// Maneja el evento de cerrar la ventana
	mlx_hook(win, 17, 0, close_window, mlx);

	// Entra en el bucle de eventos
	mlx_loop(mlx);

	return (0);
}

