/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:08:18 by nwattana          #+#    #+#             */
/*   Updated: 2022/11/18 08:00:07 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_img	init_img(void)
{
	return ((t_img){.img = NULL, .addr = NULL, \
			.bpp = 0, .llen = 0, .edn = 0});
}

int	main(int argc, char *argv[])
{
	t_prog		prog;
//	t_img		img;

//	img = init_img();
//	prog.img_data = &img;
	prog.error = 0;
	prog.zoom = 200;
	if (argc < 2 && argc > 3)
		return (WRONG_INPUT_AMOUNT);
	check_input(&prog, argc, argv);
	if (prog.error)
		return (prog.error);
	if (init_prog_data(&prog))
		return (0);
	ft_printf("prog->error = %d\n", prog.error);
	ft_printf("prog->type = %d\n", prog.type);
	mk_img(&prog);
	mlx_key_hook(prog.mlx_win, key_hook, &prog);
//	mlx_hook(prog.mlx_win, 17,1L<<0, close_win, &prog);
//	mlx_expose_hook(prog.mlx_win, close_win, &prog);
	mlx_loop(prog.mlx);
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
