/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tn_nummeric.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 00:05:56 by nwattana          #+#    #+#             */
/*   Updated: 2022/11/11 19:56:40 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TN_NUMMERIC_H
# define TN_NUMMERIC_H

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
