/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:14:21 by nwattana          #+#    #+#             */
/*   Updated: 2022/11/11 17:15:04 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_release(int key, t_vars *var);
void	pix_put(t_img *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->llen + x * (data->bpp>>3));
	*(unsigned int *)dst = color;
}

int	main(void)
{

	void	*mlx;
	void	*mlx_win;
	t_img	img;

	int		offset;
	int		max_x;
	int		max_y;
	t_vars mxx;


	max_y = 1080;
	max_x = 1920;
	mlx = mlx_init();
	offset = 100;
	mlx_win = mlx_new_window(mlx, max_x, max_y, "Hello World!");
	img.img = mlx_new_image(mlx, max_x + 1000, max_x + 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.llen, &img.edn);
	mxx.mlx = mlx;
	mxx.win = mlx_win;	
	int		i;

	i = 0;
	while (i <= 500)
	{
		pix_put(&img, 500 - i, i, 0x00FF0000);
		pix_put(&img, i, i, 0x00FF0000);
		pix_put(&img, 250, i, 0x00FF0000);
		pix_put(&img, i, 250, 0x00FF0000);
		pix_put(&img, 0, i, 0x00FF0000);
		pix_put(&img, i, 0, 0x00FF0000);
		pix_put(&img, 500, i, 0x00FF0000);
		pix_put(&img, i, 500, 0x00FF0000);
		i++;
	}
	// draw frame
	int		j;
	
	i = 0;
	while (i < max_x)
	{
		j = 0;
		while(j < 10)
		{
			pix_put(&img, i, j, 0x00EF0000);
			pix_put(&img, i, j+10, 0x000505FF);
			pix_put(&img, i, max_y - j, 0x00EF0000);
			pix_put(&img, i, max_y - j - 10, 0x00505FF);
			j++;
		}
		i++;
	}
	ft_printf("Last\n");
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0 , 0);
	mlx_hook(mxx.win,2,1L<<0, key_active, &mxx);
	mlx_hook(mxx.win,3,1L<<1, key_release, &mxx);
	printf("what is 1L<<0 value %ld   %ld\n",1L<<0, 1L<<1);
	mlx_loop(mlx);
}

int		key_release(int key, t_mlx *var)
{
	ft_printf("Key release %d\n", key);
	return (0);
}

int		key_active(int key, t_mlx *var)
{
	ft_printf("Some key was pressed!! %d\n",key);
	if (key == KEY_ENT)
		mlx_clear_window(var->mlx, var->win);
	else if (key == KEY_ESC)
		mlx_destroy_window(var->mlx, var->win);

	return (1);
}
