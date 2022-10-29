/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:14:21 by nwattana          #+#    #+#             */
/*   Updated: 2022/10/29 20:12:41 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include "ft_printf.h"

int	main(void)
{

	void	*mlx;
	void	*mlx_win;
	t_data	img;

	/// handle on fail
	// handle on fail
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	

	int i;
	int max_x = 1920;
	int max_y = 1080;
	int offset = 100;
	while (i <= max_x - (2 * offset))
	{

		mlx_put_p(&img, offset + i, max_y - offset, 0x00FF0000);
		i++;
	}

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0 , 0);
	mlx_loop(mlx);
}
