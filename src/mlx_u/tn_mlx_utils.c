/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tn_mlx_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 22:45:53 by nwattana          #+#    #+#             */
/*   Updated: 2022/10/28 03:02:33 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_mlx_u		*mlx_u_init(t_prog *prog)
{
	t_mlx_u	*res;

	res = mulloc(sizeof(t_mlx_u));
	if (!res)
	{
		prog->error = malloc_fail;
		return (NULL);
	}
	res->mlx = mlx_init();
	res->mlx_win = mlx_new_window(mlx, prog->window_width, \
		prog->window_height, "~fractal~");
	res->img = malloc(sizeof(t_img));
	if (!(res->img))
	{
		prog->error = malloc_fail;
		return (res);
	}
	init_plan(res->img, prog);
	return (res);
}
