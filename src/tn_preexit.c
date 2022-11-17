/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tn_preexit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:02:39 by nwattana          #+#    #+#             */
/*   Updated: 2022/11/17 23:00:16 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pre_exit(t_prog *prog)
{
	if (prog->img_data)
	{
		ft_printf("Exit JA\n");
		free(prog->img_data);
		prog->img_data = NULL;
	}
}
