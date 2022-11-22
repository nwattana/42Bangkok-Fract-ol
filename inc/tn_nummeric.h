/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tn_nummeric.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 00:05:56 by nwattana          #+#    #+#             */
/*   Updated: 2022/11/19 01:11:13 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TN_NUMMERIC_H
# define TN_NUMMERIC_H

/*
Error List
Program_OK Not error show
Malloc_Fail Some mulloc in program fail
WRONG_INPUT input dose not matah to flist
MLX_?? - init mlx asset
*/
typedef enum s_err
{
	PROGRAM_OK,
	MALLOC_FAIL,
	WRONG_INPUT,
	WRONG_INPUT_AMOUNT,
	MLX_ALLOCATE_ERROR,
	MLX_WIN_ALLOCATE_ERROR,
	MLX_IMG_ALLOC_FAIL
}			t_err;

/*
Fractol List
*/
typedef enum e_flist
{
	DEFAULT,
	MANDELBROT,
	JULIA1,
	JULIA2,
	JULIA3,
	JULIA4,
	JULIA5,
	JULIA6
}		t_flist;

#endif
