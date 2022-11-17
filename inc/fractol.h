/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:19:15 by nwattana          #+#    #+#             */
/*   Updated: 2022/11/17 18:21:31 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:35:06 by nwattana          #+#    #+#             */
/*   Updated: 2022/11/14 12:45:07 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include "tn_key.h"
# include "tn_nummeric.h"
# include "tn_const.h"
# include "ft_printf.h"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		llen;
	int		edn;
}			t_img;
/*
 mlx -> mlx lib
 mlx_win -> mlx_win init
 img -> mlx_new_img
*/


typedef struct s_prog
{
	t_err		error;
	t_flist		type;
}		t_prog;

void	check_input(t_prog *prog, int argc, char *argv[]);
void	put_fractol_list(void);
void	pix_put(t_img *img, int x, int y, int color);
int		create_color(int r, int g, int b);


#endif
