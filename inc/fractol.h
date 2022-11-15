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

typedef struct s_plot
{
	float	x;
	float	y;
	double	prx;
	double	pry;
	double	cx;
	double	cy;
	int		iter;

}			t_plot;

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
typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	*img;
	int		mlx_init;
	int		win_init;
	int		img_init;
}			t_mlx;


typedef struct s_prog
{
	t_err		error;
	t_mlx		*mlx;
	t_flist		type;
}		t_prog;

void	check_input(t_prog *prog, int argc, char *argv[]);
int		key_active(int key, t_mlx *var);
void	put_fractol_list(void);
void	tn_init_mlx(t_prog *prog);
void	pix_put(t_img *img, int x, int y, int color);


int		create_color(int r, int g, int b);

int		get_depth(int x_win, int y_win);
void	pl_init(t_plot *pl, int x_win, int y_win);
float	hard_map(float val, int x);

void	ploting(t_prog *prog);
int		color_depth(int i);

#endif
