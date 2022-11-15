/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pix_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:05:53 by nwattana          #+#    #+#             */
/*   Updated: 2022/11/13 01:47:47 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pix_put(t_img *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->llen + x * (data->bpp>>3));
	*(unsigned int *)dst = color;
}
