/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 22:06:36 by nwattana          #+#    #+#             */
/*   Updated: 2022/11/19 02:56:25 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia3(t_pl *pl, t_prog *prog)
{
	t_comp			comp;
	unsigned int	i;

	i = 0;
	comp.r = pl->x_cal;
	comp.i = pl->y_cal;
	comp.cr = 0.355;
	comp.ci = 0.355;
	comp.mag = comp.r * comp.r + comp.i * comp.i;
	while (i < prog->max_iter && comp.mag <= 4)
	{
		comp.tmp = comp.r;
		comp.r = (comp.r * comp.r) - (comp.i * comp.i) + comp.cr;
		comp.i = comp.i * comp.tmp * 2 + comp.ci;
		i++;
		comp.mag = comp.r * comp.r + comp.i * comp.i;
	}
	pl->i = i;
}

void	julia4(t_pl *pl, t_prog *prog)
{
	t_comp			comp;
	unsigned int	i;

	i = 0;
	comp.r = pl->x_cal;
	comp.i = pl->y_cal;
	comp.cr = -0.54;
	comp.ci = 0.54;
	comp.mag = comp.r * comp.r + comp.i * comp.i;
	while (i < prog->max_iter && comp.mag <= 4)
	{
		comp.tmp = comp.r;
		comp.r = (comp.r * comp.r) - (comp.i * comp.i) + comp.cr;
		comp.i = comp.i * comp.tmp * 2 + comp.ci;
		i++;
		comp.mag = comp.r * comp.r + comp.i * comp.i;
	}
	pl->i = i;
}

void	julia5(t_pl *pl, t_prog *prog)
{
	t_comp			comp;
	unsigned int	i;

	i = 0;
	prog->max_iter = 500;
	comp.r = pl->x_cal;
	comp.i = pl->y_cal;
	comp.cr = 0.355534;
	comp.ci = 0.337292;
	comp.mag = comp.r * comp.r + comp.i * comp.i;
	while (i < prog->max_iter && comp.mag <= 4)
	{
		comp.tmp = comp.r;
		comp.r = (comp.r * comp.r) - (comp.i * comp.i) + comp.cr;
		comp.i = comp.i * comp.tmp * 2 + comp.ci;
		i++;
		comp.mag = comp.r * comp.r + comp.i * comp.i;
	}
	pl->i = i;
}
