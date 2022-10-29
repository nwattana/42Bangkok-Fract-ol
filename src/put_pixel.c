/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:52:24 by nwattana          #+#    #+#             */
/*   Updated: 2022/10/28 02:55:30 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	mlx_put_p(t_img *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y *data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
