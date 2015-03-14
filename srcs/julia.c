/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 22:10:31 by gmp               #+#    #+#             */
/*   Updated: 2015/03/14 14:51:27 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"
#include <stdio.h>

static void			tab_color(int tab[5])
{
	tab[0] = 0x006699;
	tab[1] = 0x006699;
	tab[2] = 0xCC99FF;
	tab[3] = 0xFF99CC;
	tab[4] = 0xFF9999;
}

void				check_julia_set(t_env *e, t_dpnt point, int iteration)
{
	double			re;
	double			im;
	int				color[5];

	if (point.c_re * point.c_re + point.c_im * \
		point.c_im > 4 || iteration >= MAX_ITER_JULIA)
	{
		tab_color(color);
		if (iteration >= MAX_ITER_JULIA)
			img_pixel_put(point.col, point.row, 0xeeeeee);
		else
			img_pixel_put(point.col, point.row, color[iteration % 50]);
		return ;
	}
	re = -0.74543 + (e->mousex / 1000);
	im = 0.011301 + (e->mousey / 1000);
	point.x = point.c_re;
	point.y = point.c_im;
	point.c_re = point.x * point.x - point.y * point.y + re;
	point.c_im = 2 * point.x * point.y + im;
	check_julia_set(e, point, iteration + 1);
}

void				julia(t_env *e)
{
	t_dpnt	point;

	point.col = 0;
	point.row = 0;
	while (point.row < HEIGTH)
	{
		while (point.col < WIDTH)
		{
			point.c_re = (point.col - (WIDTH + \
				e->scale) / 2.0) * (4) / (WIDTH + e->scale);
			point.c_im = (point.row - HEIGTH / 2.0) * 4 / (WIDTH + e->scale);
			point.x = 0;
			point.y = 0;
			check_julia_set(e, point, 0);
			point.col++;
		}
		point.col = 0;
		point.row++;
	}
}
