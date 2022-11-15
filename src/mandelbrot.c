/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 02:36:22 by nwattana          #+#    #+#             */
/*   Updated: 2022/11/14 13:02:12 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void	ploting(t_prog *prog)
{
	int 	x_win;
	int		y_win;
	int		depth;

	x_win = 0;
	y_win = 0;
	depth = 0;
	while (x_win < WIN_HEIGH)
	{
		while (y_win < WIN_WIDTH)
		{
			//ft_printf("Enter ploting (%d, %d)\n", x_win, y_win);
			depth = get_depth(x_win, y_win);
			ft_printf("depth = %d %d\n",depth, 25 * depth);
			pix_put(prog->mlx->img->img, x_win, y_win, 25*depth);
			y_win++;
		}
		y_win = 0;
		x_win++;
	}
	ft_printf("finish plot\n");
}

float		hard_map(float val, int x)
{
	float		start;

	if (x == 1)
	{
		start = -2;
	//	printf("Hard map return 1 %f \n",(4 * (val / 800) - 2));
		return ((val * (4 / 400)) + start);
	}
	start = 2;
	//printf("Hard map return 2 %f \n",(2 - 4 * (val / 800)));
	return (start - (val * ( 4 / 400)));
}

int		get_depth(int x_win, int y_win)
{
	t_plot	pl;
	float pow2;
	int		dep;

	dep = 0;
	pl_init(&pl, x_win, y_win);
	while (dep < 10)
	{
//		printf("px , py (%f , %f)\n", pl.x, pl.y);
		pow2 = pl.x * pl.x + pl.y * pl.y;
		printf("%f\n", pow2);
		if (pow2 > 6)
			return (dep);
		pl.prx = pl.x;
		pl.pry = pl.y;
		pl.x = pow(pl.prx, 2) - pow(pl.pry, 2);
		pl.y = pl.prx * pl.pry * 2;
		dep++;
	}
	return (dep);
}

void	pl_init(t_plot *pl, int x_win, int y_win)
{
	pl->x = hard_map(x_win, 1);
	pl->y = hard_map(y_win, 2);
	printf("px = %f, py = %f, x_win = %d, y_win = %d\n", pl->x, pl->y, x_win, y_win);
	pl->iter = 0;
}

int	color_depth(int i)
{
	ft_printf("%d\n", create_color(i * 10, 5, 20));
	return (120*i);
}
