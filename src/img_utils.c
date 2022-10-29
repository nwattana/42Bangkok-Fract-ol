/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 00:02:16 by nwattana          #+#    #+#             */
/*   Updated: 2022/10/28 03:02:32 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"


void	init_plan(t_img *img, t_prog *prog)
{
	img->img = mlx_new_window(prog->mlx, \
				prog->window_width, window_height);
	img->addr = mlx_get_data_addr(img->img, img->bits_per_pixel, \
				img->line_lenght, img.endian);

}
