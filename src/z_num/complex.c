/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 02:16:37 by nwattana          #+#    #+#             */
/*   Updated: 2022/11/13 02:35:42 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_cpl	*cpl_new(double r, double n);
{
	t_cpl *res;

	res = malloc(sizeof(t_dat));
	if (!res)
		return (NULL);
	res->r = 0;
	img->im = 0;
}

t_cpl	*cpl_mul(t_cpl *cpl1, t_clp cpl2)
{
	t_cpl	*res;

	res = malloc(sizeof(t_cpl));
	if (!res)
		return ;
	res->real = cpll->
}
