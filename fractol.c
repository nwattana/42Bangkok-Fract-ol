/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:08:18 by nwattana          #+#    #+#             */
/*   Updated: 2022/11/19 01:33:22 by nwattana         ###   ########.fr       */
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
	mk_img(&prog);

	printf(" main %p\n", &prog);
	mlx_mouse_hook(prog.mlx_win, imouse_hook, &prog);
	mlx_key_hook(prog.mlx_win, key_hook, &prog);
	mlx_hook(prog.mlx_win, 17, 0, close_win, &prog);
	mlx_loop(prog.mlx);
}

