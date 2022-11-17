/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:08:18 by nwattana          #+#    #+#             */
/*   Updated: 2022/11/17 18:14:33 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_img(t_prog *prog);
int	main(int argc, char *argv[])
{
	t_prog		prog;

	if (argc > 0)
	{
		prog.error = 0;
		check_input(&prog ,argc, argv);
	}
/*	if (!prog.error)
		tn_init_mlx(&prog);
	ft_printf("prog->error = %d\n", prog.error);
	ft_printf("prog->type = %d\n", prog.type);
	if (!prog.error)
	{
		draw_img(&prog);
		mlx_loop(prog.mlx->mlx);
	}*/
}
/*
void	draw_img(t_prog *prog)
{
	t_img	*img;
	t_mlx	*mlx;
	int		i;

	mlx = prog->mlx;
	img = prog->mlx->img;
	ploting(prog);
	ft_printf("before put\n");
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 0, 0);
	ft_printf("finish put\n");
}*/
