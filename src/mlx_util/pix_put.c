/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pix_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:05:53 by nwattana          #+#    #+#             */
/*   Updated: 2022/11/18 18:18:05 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/*
* If x or y more than or equal image_size
* just return
* data addr + y(row)*line_len + x * (data->bit per pixel / 8)?
*/
void	pix_put(t_img *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->addr + (y * data->llen + x * 4);
	*(unsigned int *)dst = color;
}
