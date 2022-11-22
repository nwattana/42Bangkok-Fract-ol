/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 01:21:14 by nwattana          #+#    #+#             */
/*   Updated: 2022/11/19 02:12:12 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	imouse_hook(int key, int x, int y, t_prog *prog)
{

	printf("x =%d, y =%d\n", x ,y);
	mlx_clear_window(prog->mlx, prog->mlx_win);
	if (key == M_SCROLL_UP)
	{
		prog->shift_x += (400 - x) / 5;
		prog->shift_y += (400 - y) / 5;
		if (prog->zoom_cal > 0.021)
			prog->zoom_cal += 0.02;
		else if (prog->zoom_cal > 0.0021)
			prog->zoom_cal += 0.002;
		else
			prog->zoom_cal += 0.0005;
	}
	else if (key == M_SCROLL_DOWN)
	{
		prog->shift_x -= (400 - x) / 5;
		prog->shift_y -= (400 - y) / 5;
		if (prog->zoom_cal > 0.021)
			prog->zoom_cal -= 0.02;
		else if (prog->zoom_cal > 0.0021)
			prog->zoom_cal -= 0.002;
		else if (prog->zoom_cal > 0.0001)
			prog->zoom_cal -= 0.0001;
	}
	mk_img(prog);
	printf("keycode = %d  zoom = %f \n", key, prog->zoom_cal);
	printf("shift = %d shift = %d\n", prog->shift_x, prog->shift_y);
	return (0);
}
