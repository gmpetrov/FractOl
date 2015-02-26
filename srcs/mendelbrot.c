/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mendelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 13:54:47 by gmp               #+#    #+#             */
/*   Updated: 2015/02/26 22:26:13 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"
#include <stdio.h>

void 	check_set(t_env *e, int col, int row, double x, double y, double c_re, double c_im, int iteration, int max)
{

	if (iteration >= max){
		img_pixel_put(e,col,row, 0xffffff);
		return;
	}

	if(x*x+y*y > 4){
		int color[] = { 0x006699, 0xCC99FF, 0xFF99CC, 0xFF9999, 0xFFFF99};
		img_pixel_put(e,col,row, color[iteration % 10]);
		return;
	}

	check_set(e, col, row, x*x - y*y + c_re, 2*x*y + c_im, c_re, c_im, iteration + 1, max);
}

void 	mendelbrot(t_env *e)
{
			int row;
			int col;
			double x;
			double y;
			double c_re;
			double c_im;

			row = 0;
			col = 0;
		int max = 100;
		while (row < HEIGTH) {
		    while (col < WIDTH) {
		        c_re = (col - (WIDTH + 500 + e->scale)/2.0) * (4) / (WIDTH + e->scale);
		        c_im = (row - HEIGTH/2.0) * 4 / (WIDTH + e->scale);
		        x = 0;
		        y = 0;
		        int iteration = 0;
		        check_set(e, col, row, x, y, c_re, c_im, iteration, max);
		        col++;
		    }
		    col = 0;
		    row ++;
		}
}
