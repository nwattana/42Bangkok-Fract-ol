/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 22:06:36 by nwattana          #+#    #+#             */
/*   Updated: 2022/11/18 23:50:55 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_pl *pl, t_prog *prog)
{
	t_comp comp;
	unsigned int i;

	i = 0;
	comp.r = pl->x_cal;
	comp.i = pl->y_cal;
	comp.cr = 0.37;
	comp.ci = 0.1;
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

void	julia1(t_pl *pl, t_prog *prog)
{
	t_comp comp;
	unsigned int i;

	prog->max_iter = 500;
	i = 0;
	comp.r = pl->x_cal;
	comp.i = pl->y_cal;
	comp.cr = -0.8;
	comp.ci = 0.156;
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
void	julia2(t_pl *pl, t_prog *prog)
{
	t_comp comp;
	unsigned int i;

	i = 0;
	comp.r = pl->x_cal;
	comp.i = pl->y_cal;
	comp.cr = 0;
	comp.ci = 0.8;
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
