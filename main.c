/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:14:21 by nwattana          #+#    #+#             */
/*   Updated: 2022/10/30 01:38:11 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include "ft_printf.h"

int	main(void)
{
	t_prog	prog;

	prog_init(500, 500, &prog);
	if (prog->error)
		return (1);



}

void	prog_init(int width, int height, t_prog *prog)
{
	prog->window_width = width;
	prog->window_height = height;
	prog->error = 0;
	prog->coor = coor_init(width, height, prog);
	prog->mlx_u = mlx_u_init(width, height, prog);


}

t_mlx_u	mlx_u_init(int width, int height, t_prog *prog)
{
	t_mlx_u	ret;

	if (prog->error)
			return (NULL);
	ret = ft_colloc(sizeof(t_mlx_u), 1);
	if(!ret)
	{
		prog->error = malloc_fail;
		return (NULL);
	}
	ret->mlx = mlx_init();
	ret->mlx_win = mlx_new_window(ret->mlx, width, height);
}

/*
initialize for coordinate
x-axis:(x, a_x) y-axis:(a_y, y) which x and y can be vary
Check for 0 width and 0 height

check 

*/

t_coor	*coor_init(int width, int height, t_prog *prog)
{
	t_coor	*ret;

	ret = ft_calloc(sizeof(t_coor), 1);
	if (!ret)
	{
		prog->error = malloc_fail;
		return (NULL);
	}
	if (width <= 0 || height <= 0)
		prog->error = invalid_windowsize;
	ret->w_width = width;
	ret->w_height = height;
	if (!prog->error)
	{
		ret->a_x = height >> 1;
		ret->a_y = width >> 1;
		ret->b_x_po = ret->a_x;
		ret->b_y_po = ret->a_y;
		ret->b_x_ng = -ret->a_x;
		ret->b_y_ng = -ret->a_y;
	}
	else
		free(ret);
	return (ret);
}

