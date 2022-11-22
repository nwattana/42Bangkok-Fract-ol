/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:35:06 by nwattana          #+#    #+#             */
/*   Updated: 2022/11/19 01:54:12 by nwattana         ###   ########.fr       */
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

typedef struct s_comp
{
	float	r;
	float	i;
	float	cr;
	float	ci;
	float	mag;
	float	tmp;
}			t_comp;


typedef struct s_plot
{
	unsigned int	max_iter;
	unsigned int	i;
	unsigned int	x_plot;
	unsigned int	y_plot;
	float			x_cal;
	float			y_cal;
	float			x_cmin;
	float			y_cmin;
	float			x_range;
	float			y_range;
}		t_pl;

/*
 mlx -> mlx lib
 mlx_win -> mlx_win init
 img -> mlx_new_img
*/


typedef struct s_prog
{
	t_err		error;
	t_flist		type;
	void	*mlx;
	void	*mlx_win;
	t_img	*img_data;
	int		shift_x;
	int		shift_y;
	unsigned int	max_iter;
	float			zoom;
	float			zoom_base;
	float			zoom_cal;
	unsigned int	high;
	unsigned int	width;
	unsigned int	*color;
}		t_prog;

void	check_input(t_prog *prog, int argc, char *argv[]);
void	put_fractol_list(void);
void	pix_put(t_img *img, int x, int y, unsigned int color);

int		create_color(int r, int g, int b);
int		mk_cdata(t_prog *prog);
int		hsltohex(float h, float l, float s);

int		init_prog_data(t_prog *prog);

int		key_hook(int keycode, t_prog *prog);

void	mk_img(t_prog *prog);
void	mandelbrot(t_pl *pl, t_prog *prog);
void	julia(t_pl *pl, t_prog *prog);
void	julia1(t_pl *pl, t_prog *prog);
void	julia2(t_pl *pl, t_prog *prog);
void	julia3(t_pl *pl, t_prog *prog);
void	julia4(t_pl *pl, t_prog *prog);
void	julia5(t_pl *pl, t_prog *prog);
void	get_depth(t_flist type, t_pl *pl, t_prog *prog);
void	init_pl(t_pl *pl, t_prog *prog);
int		imouse_hook(int key, int x, int y, t_prog *prog);


// exit
void	pre_exit(t_prog *prog);	
int		close_win(int keycode, t_prog *prog);
#endif
