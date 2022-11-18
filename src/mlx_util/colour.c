/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 01:51:03 by nwattana          #+#    #+#             */
/*   Updated: 2022/11/18 07:43:13 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	hsltohex(int h, int l, int s)
{
	int		d;
	int		m;
	int		x;
	int		color;
	
	color = 0;
	d = s * (1 - abs(2*l - 1));
	m = 255 * (l - (d>>1));
	x = d * (1 - abs((h/60) % 2 - 1));
	if (h >= 0 && h < 60)
		color = create_color(255 * d + m, 255 * x + m, m);
	else if (h >= 60 && h < 120)
		color = create_color(255 * x + m, 255 * d + m, m);
	else if (h >= 120 && h < 180)
		color = create_color(m, 255 * d + m, 255 * x + m);
	else if (h >= 180 && h < 240)
		color = create_color(m, 255 * x + m, 255 * d + m);
	else if (h >= 240 && h < 300)
		color = create_color(255 * x + m,  m, 255 * d + m);
	else if (h >= 300 && h < 360)
		color = create_color(255 * d + m,  m, 255 * x + m);
	return (color);
}

int		mk_cdata(t_prog *prog)
{
	unsigned int	i;
	unsigned int	h;
	unsigned int	l;
	unsigned int	s;

	i = 0;
	s = 100;
	prog->color = malloc(sizeof(int) * (prog->max_iter));
	if (!prog->color)
		return (MALLOC_FAIL);
	while (i < prog->max_iter)
	{
		l = ((100 - (i * 100) / prog->max_iter));
		h = ((i * 360) / prog->max_iter);
		prog->color[i] = hsltohex(h, l, s);
		i++;
	}
	return (PROGRAM_OK);
}
