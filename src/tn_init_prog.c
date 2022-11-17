/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tn_init_prog.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:05:16 by nwattana          #+#    #+#             */
/*   Updated: 2022/11/18 03:49:16 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	initial_const(t_prog *prog);
static int	init_prog_asset(t_prog *prog);

int	init_prog_data(t_prog *prog)
{
	if (prog->error)
		return (prog->error);
	initial_const(prog);
	if (init_prog_asset(prog) == 0)
	{
		prog->mlx_status = 1;
		prog->mlx_win_status = 1;
		prog->img_status = 1;
	}
	return (PROGRAM_OK);
}

static int	init_prog_asset(t_prog *prog)
{
	t_img	*tmp;

	prog->mlx = mlx_init();
	if (!prog->mlx)
		return (MLX_ALLOCATE_ERROR);
	prog->mlx_win = mlx_new_window(prog->mlx,\
		prog->width, prog->high, "fractol");
	if (!prog->mlx_win)
		return (MLX_WIN_ALLOCATE_ERROR);
	prog->img_data = malloc(sizeof(t_img));
	if (!prog->img_data)
	{
		return (MALLOC_FAIL);
	}
	prog->img_data->img = mlx_new_image(prog->mlx, \
		prog->width + 1, prog->high + 1);
	if (!prog->img_data->img)
		return (MLX_IMG_ALLOC_FAIL);
	tmp = prog->img_data;
	tmp->addr = mlx_get_data_addr(tmp->img, \
		&(tmp->bpp), &(tmp->llen), &(tmp->edn));
	return (PROGRAM_OK);
}

static void	initial_const(t_prog *prog)
{
	if (prog->error)
		return ;
	prog->offset_x = 0;
	prog->offset_y = 0;
	prog->mlx_status = 0;
	prog->mlx_win_status = 0;
	prog->img_status = 0;
	prog->mlx = NULL;
	prog->mlx_win = NULL;
	prog->img_data = NULL;
	prog->high = 1200;
	prog->width = 1200;
	prog->zoom = 1000;
}
