/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 22:10:31 by gmp               #+#    #+#             */
/*   Updated: 2015/02/26 23:22:07 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void 	check_julia_set(t_env *e, int col, int row, double x, double y, double c_re, double c_im, int iteration, int max)
{
	if (c_re*c_re + c_im*c_im > 4 || iteration >= max)
	{
		int color[] = { 0x006699, 0xCC99FF, 0xFF99CC, 0xFF9999, 0xFFFF99};
		if (iteration >= max)
			img_pixel_put(e,col,row, 0xeeeeee);
		else
			img_pixel_put(e,col,row, color[iteration % 50]);
		return ;
	}
	double re = -0.74543;
	double im = 0.011301;

	x = c_re;
	y = c_im;
	c_re = x*x - y*y + re;
	c_im = 2*x*y + im;
	check_julia_set(e, col, row, x, y, c_re, c_im, iteration + 1, max);
}

void 	julia(t_env *e)
{
	int 	row;
	int 	col;
	double 	x;
	double 	y;
	double	c_re;
	double 	c_im;

	col = 0;
	row = 0;
	while (row < HEIGTH)
	{
		while (col < WIDTH)
		{
		    c_re = (col - (WIDTH + e->scale)/2.0) * (4) / (WIDTH + e->scale);
		    c_im = (row - HEIGTH/2.0) * 4 / (WIDTH + e->scale);
			x = 0;
			y = 0;
			check_julia_set(e, col, row, x, y, c_re, c_im, 0, 50);
			col++;
		}
		col = 0;
		row++;
	}
}