/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mendelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 13:54:47 by gmp               #+#    #+#             */
/*   Updated: 2015/02/26 21:05:56 by gmp              ###   ########.fr       */
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

			row = 0;
			col = 0;
		int max = 50;
		while (row < HEIGTH) {
		    while (col < WIDTH) {
		        double c_re = (col - (WIDTH + 500 + e->scale)/2.0) * (4) / (WIDTH + e->scale);
		        // printf("c_re = %f\n", c_re);
		        double c_im = (row - HEIGTH/2.0) * 4 / (WIDTH + e->scale);
		        double x = 0, y = 0;
		        int iteration = 0;
		        check_set(e, col, row, x, y, c_re, c_im, iteration, max);
		        col++;
		    }
		    col = 0;
		    row ++;
		}
}

// void 	mendelbrot(t_env *e, int x11, int y11, int x22, int y22, int num_iteration)
// {
// 			(void)x11;
// 			(void)y11;
// 			(void)x22;
// 			(void)y22;
// 			(void)num_iteration;

// 		int color[] = { 0x006699, 0xCC99FF, 0xFF99CC, 0xFF9999, 0xFFFF99};

// 		int max = 40;
// 		for (int row = 0; row < HEIGTH; row++) {
// 		    for (int col = 0; col < WIDTH; col++) {
// 		        double c_re = (col - WIDTH/2.0)*4.0/WIDTH;
// 		        double c_im = (row - HEIGTH/2.0)*4.0/WIDTH;
// 		        double x = 0, y = 0;
// 		        int iteration = 0;
// 		        while (x*x+y*y <= 4 && iteration < max) {
// 		            double x_new = x*x - y*y + c_re;
// 		            y = 2*x*y + c_im;
// 		            x = x_new;
// 		            iteration++;
// 		        }
// 		        if (iteration >= max)
// 					img_pixel_put(e,col,row, 0xeeeeee);
// 				else
// 					img_pixel_put(e,col,row, color[iteration % 10]);
// 		    }
// 	}
// }
