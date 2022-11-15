/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tn_compl.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 02:10:04 by nwattana          #+#    #+#             */
/*   Updated: 2022/11/13 02:28:38 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

typedef struct s_cpl
{
	double 	r;
	double im;
}		t_cpl;


t_cpl	*cpl_new(double r, double n);
t)cpl	*cpl_mul(t_cpl *sa, t_cdp *bd)
