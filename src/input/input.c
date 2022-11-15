/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:18:50 by nwattana          #+#    #+#             */
/*   Updated: 2022/11/10 16:04:14 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_input(t_prog *prog, int argc, char *argv[])
{
	if (argc == 2)
	{
		if (ft_strcmp("mandelbrot", argv[1]) == 0)
			prog->type = MANDELBROT;
		else
			prog->error = WRONG_INPUT;
	}
	else if (argc == 3)
	{
		if (!ft_strcmp("julia", argv[1]))
		{
			if (ft_strlen(argv[2]) == 1 && ft_isin(*argv[2], "123456", 6))
				prog->type = JULIA1 + *argv[2] - '1';
			else
				prog->error = WRONG_INPUT;
		}
	}
	else
		prog->error = WRONG_INPUT_AMOUNT;
	if (prog->error)
		put_fractol_list();
}

/*
	Message when no argument passed
	and Wrong argument passed
*/
void	put_fractol_list(void)
{
	ft_putstr_fd("\e[1;32m=======================", 1);
	ft_putstr_fd("===============================\033[0m\n", 1);
	ft_putstr_fd("\e[1;32m================\e[1;31mFRACTOL\e[1;33m", 1);
	ft_putstr_fd(" WORNG INPUT\e[1;32m===================\033[0m\n", 1);
	ft_putstr_fd("\e[1;32m======================", 1);
	ft_putstr_fd("================================\033[0m\n", 1);
	ft_putstr_fd("All Fractal I have\n", 1);
	ft_putstr_fd(" 1. Mandelbrot\n", 1);
	ft_putstr_fd(" 2. Julia [1 - 6]\n", 1);
	ft_putstr_fd("\nHow to run \e[1;31mMandelbrot\e[0m\n", 1);
	ft_putstr_fd("\t./fractol mandelbrot\n", 1);
	ft_putstr_fd("\nHow to run \e[1;31mJulia [1 - 6]\e[0m\n", 1);
	ft_putstr_fd("\t./fractol julia 1\n", 1);
	ft_putstr_fd("\t./fractol julia [just a number from 1 - 6]\n\n", 1);
	ft_putstr_fd("\e[1;32m========================", 1);
	ft_putstr_fd("==============================\033[0m\n", 1);
}
