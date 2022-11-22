/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tn_preexit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:02:39 by nwattana          #+#    #+#             */
/*   Updated: 2022/11/19 01:04:36 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pre_exit(t_prog *prog)
{
	if (prog->img_data)
	{
		if (prog->img_data)
			free(prog->img_data);
		prog->img_data = NULL;
		if (prog->color)
			free(prog->color);
	}
}
