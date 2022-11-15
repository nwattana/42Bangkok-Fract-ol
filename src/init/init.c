/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:04:01 by nwattana          #+#    #+#             */
/*   Updated: 2022/11/11 21:00:44 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
static void		tn_init_mlx_2(t_prog *prog);
static void		tn_init_win(t_prog *prog);
static void		tn_init_image(t_prog *prog);

/*
	mal prog->mlx   t_mlx
*/
void	tn_init_mlx(t_prog *prog)
{
	prog->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!prog->mlx)
	{
		prog->error = MALLOC_FAIL;
		return ;
	}
	prog->mlx->mlx_init = 0;
	prog->mlx->win_init = 0;
	prog->mlx->img_init = 0;
	ft_printf("Done gen mlx storage\t error = %d\n",prog->error);
	tn_init_mlx_2(prog);
	ft_printf("MLX initiated\t error = %d\n",prog->error);
	tn_init_win(prog);
	ft_printf("MLX init Windown\t error = %d \n", prog->error);
	tn_init_image(prog);
	ft_printf("MLX init image\t error = %d \n", prog->error);
}

static void		tn_init_mlx_2(t_prog *prog)
{
	t_mlx *mlx;

	mlx = prog->mlx;
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
	{
		prog->error = MLX_ALLOCATE_ERROR;
		return ;
	}
	mlx->mlx_init = 1;
}

static void		tn_init_win(t_prog *prog)
{
	t_mlx *mlx;

	mlx = prog->mlx;
	if (prog->error)
		return ;
	mlx->win = mlx_new_window(mlx->mlx, \
		WIN_WIDTH, WIN_HEIGH, "FRACTOL");
	if (!mlx->win)
	{
		prog->error = MLX_WIN_ALLOCATE_ERROR;
		return ;
	}
	printf("init Window size %d x %d\n", WIN_HEIGH, WIN_WIDTH);
	mlx->win_init = 1;

}

static void		tn_init_image(t_prog *prog)
{
	t_mlx *mlx;

	mlx = prog->mlx;
	if (prog->error)
		return ;
	mlx->img = malloc(sizeof(t_img));
	if (!mlx->img)
		prog->error = MALLOC_FAIL;
	else
	{
		ft_printf("Generate img WxH  %d x %d\n", WIN_WIDTH, WIN_HEIGH);
		mlx->img->img = mlx_new_image(\
			mlx->mlx, WIN_WIDTH, WIN_HEIGH);
		if (!mlx->img->img)
			prog->error = MLX_IMG_ALLOC_FAIL;
		else
		{
			mlx->img->addr = mlx_get_data_addr(mlx->img->img,\
				&mlx->img->bpp,&mlx->img->llen, &mlx->img->edn);
		}
		mlx->img_init = 1;
	}
}
