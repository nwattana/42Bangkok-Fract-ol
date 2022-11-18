/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tn_makeimage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 02:21:19 by nwattana          #+#    #+#             */
/*   Updated: 2022/11/18 07:49:26 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tn_makeimage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:07:33 by nwattana          #+#    #+#             */
/*   Updated: 2022/11/18 02:21:04 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mk_img(t_prog *prog)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	i;
	unsigned int	color;
	unsigned int	max_iter;
	float		st;
	float		en;
	float		zoom;

	prog->offset_x = 0;
	prog->offset_y = 0;
	zoom = 1000;
	st = 2;
	en = -2;
	max_iter = 200;
	i = 0;
	x = 0;
	y = 0;
	if (!prog)
		return ;
	while (y < prog->high)
	{
		x = 0;
		while (x < prog->width)
		{
			i = mk_mandelbrot(imap_x(x + prog->offset_x, en, st, prog)*(zoom/prog->zoom), \
				imap_y(y + prog->offset_y, st, en, prog)*(zoom/prog->zoom));
//			i = mk_julia(imap_x(x + prog->offset_x, en/zoom, st/zoom, prog), \
//				imap_y(y + prog->offset_y, st/zoom, en/zoom, prog));
		/*	if (i%4 == 1)
				color = create_color(2 * (i+ 10), max_iter - i,  max_iter - i);
			else if (i%4 == 2)
				color = create_color(max_iter - i, max_iter - i, 2 * (i+ 10));
			else if (i%4 == 3)
				color = create_color(max_iter - i, 2 * (i+ 10), max_iter - i );
			else
				color = create_color(0,0,0);*/
			pix_put(prog->img_data, x, y, prog->color[i]);
			x++;
		}
	//	printf("\n");
		y++;
	}
	mlx_put_image_to_window(prog->mlx, prog->mlx_win, \
			prog->img_data->img, 0, 0);
	//printf("Incoming Co x=%f, y=%f\n", x, y);
}

float	imap(float val, float st, float end, t_prog *prog)
{
	return (((val/1600) * (end - st)) + st);
}

float	imap_x(float val, float st, float end, t_prog *prog)
{
	return (((val/prog->width) * (end - st)) + st);
}

float	imap_y(float val, float st, float end, t_prog *prog)
{
	return (((val/prog->high) * (end - st)) + st);
}

unsigned int		mk_mandelbrot(float x, float y)
{
	t_comp	num;
	t_pl	pl;
	float	tmp;

	pl = (t_pl){.max_iter=255, .i=0};
	num=(t_comp){.r=x, .i=y, .mag=0};
	num.mag = num.r * num.r + num.i * num.i;
	while (pl.i < pl.max_iter && num.mag < 4)
	{
		tmp = num.r;
		num.r = (num.r * num.r) - (num.i * num.i) + x;
		num.i = tmp * 2 * num.i + y;
		num.mag = num.r * num.r + num.i * num.i;
		pl.i++;
	}
	return (pl.i);
}

unsigned int		mk_julia(float x, float y)
{
	t_comp	num;
	t_pl	pl;
	float	tmp;

	pl = (t_pl){.max_iter=200, .i=0};
	num=(t_comp){.r=x, .i=y, .mag=0};
	num.mag = num.r * num.r + num.i * num.i;
	while (pl.i < pl.max_iter && num.mag < 4)
	{
		tmp = num.r;
		num.r = (num.r * num.r) - (num.i * num.i) - 0.70176;
		num.i = tmp * 2 * num.i - 0.3842;
		num.mag = num.r * num.r + num.i * num.i;
		pl.i++;
	}
	return (pl.i);
}
