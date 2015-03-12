/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mendelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 13:54:47 by gmp               #+#    #+#             */
/*   Updated: 2015/03/12 16:04:56 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

static void		tab_color(int tab[5])
{
	tab[0] = 0x006699;
	tab[1] = 0x006699;
	tab[2] = 0xCC99FF;
	tab[3] = 0xFF99CC;
	tab[4] = 0xFF9999;
}

void			check_set(t_dpnt point, double x, double y, int iteration)
{
	int			color[5];

	if (iteration >= MAX_ITER_MEDELBROT)
	{
		img_pixel_put(point.col, point.row, 0xffffff);
		return ;
	}
	if (x * x + y * y > 4)
	{
		tab_color(color);
		img_pixel_put(point.col, point.row, color[iteration % 10]);
		return ;
	}
	check_set(point, x * x - y * y + point.c_re, \
		2 * x * y + point.c_im, iteration + 1);
}

void			mendelbrot(t_env *e)
{
	t_dpnt		point;
	double		x;
	double		y;
	int			iteration;

	point.row = 0;
	point.col = 0;
	while (point.row < HEIGTH)
	{
		while (point.col < WIDTH)
		{
			point.c_re = (point.col - (WIDTH + 500 + e->scale) / 2.0) \
			* (4) / (WIDTH + e->scale);
			point.c_im = (point.row - HEIGTH / 2.0) * 4 / (WIDTH + e->scale);
			x = 0;
			y = 0;
			iteration = 0;
			check_set(point, x, y, iteration);
			point.col++;
		}
		point.col = 0;
		point.row++;
	}
}
