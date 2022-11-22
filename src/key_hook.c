/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:41:13 by nwattana          #+#    #+#             */
/*   Updated: 2022/11/19 02:30:07 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	move(int key, t_prog *prog);

int	key_hook(int keycode, t_prog *prog)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(prog->mlx, prog->mlx_win);
		pre_exit(prog);
		exit(0);
	}
	else if (keycode <= 160)
	{
		mlx_clear_window(prog->mlx, prog->mlx_win);
		move(keycode, prog);
	}
	return (0);
}

static void	move(int key, t_prog *prog)
{
	if (key == KEY_PLUS)
	{
		if (prog->zoom_cal > 0.021)
			prog->zoom_cal -= 0.02;
		else if (prog->zoom_cal > 0.0021)
			prog->zoom_cal -= 0.002;
		else if (prog->zoom_cal > 0.0001)
			prog->zoom_cal -= 0.0001;
	}
	if (key == KEY_MINUS)
		prog->zoom_cal += 0.02;
	if (key == KEY_TOP || key == KEY_A_W)
		prog->shift_y += 40;
	if (key == KEY_BOT || key == KEY_A_S)
		prog->shift_y -= 40;
	if (key == KEY_LEFT || key == KEY_A_A)
		prog->shift_x += 40;
	if (key == KEY_RIGHT || key == KEY_A_D)
		prog->shift_x -= 40;
	mk_img(prog);
}

int	close_win(int keycode, t_prog *prog)
{
	prog->zoom = 1;
	if (keycode)
		exit(0);
	return (0);
}
