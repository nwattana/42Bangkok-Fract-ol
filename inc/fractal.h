/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:51:42 by nwattana          #+#    #+#             */
/*   Updated: 2022/10/30 00:55:57 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

#include <mlx.h>

typedef enum e_error
{
	ok,
	malloc_fail,
	invalid_window_size,

}		t_error;

typedef struct s_coor
{
	int		b_x_po;
	int		b_y_po;
	int		b_x_ng;
	int		b_t_ng;
	int		w_width;
	int		w_height;
	int		a_x;
	int		a_y;
	int		offset;
}			t_coor;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_mlx_utils
{
	void	*mlx;
	void	*mlx_win;
	t_img	*img;
}			t_mlx_u;

typedef struct s_point
{
	int		x;
	int		y;
}		t_point;

typedef struct s_prog
{
	int			error;
	t_mlx_u		*mlx_u;
	t_coor		*coor;
	int			window_width;
	int			window_height;
}			t_prog;

void	prog_init(int width, int height, t_prog *prog);
t_mlx_u	mlx_u_init(int width, int height, t_prog *prog);
t_coor	*coor_init(int width, int height, t_prog *prog);
void	mlx_put_p(t_img *data, int x, int y, int color);
#endif
