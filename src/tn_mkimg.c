/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tn_mkimg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:44:11 by nwattana          #+#    #+#             */
/*   Updated: 2022/11/19 02:17:40 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mk_img(t_prog *prog)
{
	t_pl	pl;

	init_pl(&pl, prog);
	while (pl.y_plot < prog->high)
	{
		pl.x_plot = 0;
		while (pl.x_plot < prog->width)
		{
			pl.x_cal = pl.x_cmin + (pl.x_plot * pl.x_range);
			pl.y_cal = pl.y_cmin + (pl.y_plot * pl.y_range);
			get_depth(prog->type, &pl, prog);
			pix_put(prog->img_data, pl.x_plot, \
				pl.y_plot, prog->color[pl.i]);
			pl.x_plot++;
		}
		pl.y_plot++;
	}
	mlx_put_image_to_window(prog->mlx, \
		prog->mlx_win, prog->img_data->img, 0, 0);
}

void	init_pl(t_pl *pl, t_prog *prog)
{
	pl->i = 0;
	pl->x_plot = 0;
	pl->y_plot = 0;
	pl->x_cal = 0;
	pl->y_cal = 0;
	pl->x_range = ((4 * (prog->zoom_cal)) / (prog->width));
	pl->y_range = ((4 * (prog->zoom_cal)) / (prog->high));
	pl->x_cmin = (prog->shift_x * prog->zoom_cal) / prog->width - \
		2 * (prog->zoom_cal);
	pl->y_cmin = (prog->shift_y * prog->zoom_cal) / prog->high - \
		2 * (prog->zoom_cal);
}

void	get_depth(t_flist type, t_pl *pl, t_prog *prog)
{
	if (type == MANDELBROT)
		mandelbrot(pl, prog);
	else if (type == JULIA1)
		julia(pl, prog);
	else if (type == JULIA2)
		julia1(pl, prog);
	else if (type == JULIA3)
		julia2(pl, prog);
	else if (type == JULIA4)
		julia3(pl, prog);
	else if (type == JULIA5)
		julia4(pl, prog);
	else if (type == JULIA6)
		julia5(pl, prog);
}

void	mandelbrot(t_pl *pl, t_prog *prog)
{
	t_comp			comp;
	unsigned int	i;

	i = 0;
	prog->max_iter = 300;
	comp.r = pl->x_cal;
	comp.i = pl->y_cal;
	comp.cr = comp.r;
	comp.ci = comp.i;
	comp.mag = comp.r * comp.r + comp.i * comp.i;
	while (i < prog->max_iter && comp.mag <= 4)
	{
		comp.tmp = comp.r;
		comp.r = (comp.r * comp.r) - (comp.i * comp.i) + comp.cr;
		comp.i = comp.i * comp.tmp * 2 + comp.ci;
		i++;
		comp.mag = comp.r * comp.r + comp.i * comp.i;
	}
	pl->i = i;
}
