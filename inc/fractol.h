/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:35:06 by nwattana          #+#    #+#             */
/*   Updated: 2022/11/18 07:55:20 by nwattana         ###   ########.fr       */
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
	float	mag;
}			t_comp;


typedef struct s_plot
{
	unsigned int	max_iter;
	unsigned int	i;
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
	int		offset_x;
	int		offset_y;
	int		mlx_status;
	int		mlx_win_status;
	int		img_status;
	unsigned int	max_iter;
	unsigned int	zoom;
	unsigned int	high;
	unsigned int	width;
	unsigned int	*color;
}		t_prog;

void	check_input(t_prog *prog, int argc, char *argv[]);
void	put_fractol_list(void);
void	pix_put(t_img *img, int x, int y, unsigned int color);

int		create_color(int r, int g, int b);
int		mk_cdata(t_prog *prog);
int		hsltohex(int h, int l, int s);

int		init_prog_data(t_prog *prog);

int		key_hook(int keycode, t_prog *prog);

void	mk_img(t_prog *prog);
float	imap(float val, float st, float end, t_prog *prog);
float	imap_x(float val, float st, float end, t_prog *prog);
float	imap_y(float val, float st, float end, t_prog *prog);
unsigned int		mk_mandelbrot(float x, float y);
unsigned int		mk_julia(float x, float y);

// exit
void	pre_exit(t_prog *prog);	
int	close_win(int keycode, t_prog *prog);

#endif
