/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:41:13 by nwattana          #+#    #+#             */
/*   Updated: 2022/11/18 03:49:14 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook(int keycode, t_prog *prog)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(prog->mlx, prog->mlx_win);
		pre_exit(prog);
		exit(0);
	}
	if (keycode == KEY_PLUS)
	{
		mlx_clear_window(prog->mlx, prog->mlx_win);
		prog->zoom += 10;
		ft_printf("Zoom in = 1000/%d\n", prog->zoom);
		mk_img(prog);
	}
	ft_printf("Hello from key hook\n");
	return (0);
}
