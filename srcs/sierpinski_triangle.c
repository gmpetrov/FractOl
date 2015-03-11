/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski_triangle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 21:25:17 by gmp               #+#    #+#             */
/*   Updated: 2015/03/11 16:54:34 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"
#include <stdio.h>


void 	sierpinski(t_env *e, int x1, int y1, int x2, int y2, int orientation, int num_iterations)
{
	int	l;
	int h;
	int x3;
	int y3;

	if(num_iterations == 0)
		return;
	if (y1 != y2)
		return ;
	l = abs(x2 - x1);
	// if (l < 20)
	// 	return ;
	x3 = l / 2;
	h = sqrt((l * l) - (x3 * x3));
	y3 = (orientation == 0 ? y1 - h : y1 + h);
	x3 = x1 + x3;
	// printf("C( %d, %d )\n", x3, y3);
	draw_line_mlx(x2, y2, x1, y1);
	draw_line_mlx(x3, y3, x2, y2);
	draw_line_mlx(x3, y3, x1, y1);

	sierpinski(e, x1, y1, (l / 2) + x1, y2, 0, num_iterations-1);
	sierpinski(e, x1 + (l / 2), y1, x2, y1, 0, num_iterations-1);
	sierpinski(e, x1 + (l / 4), y1 - (h/2), x2 - (l / 4), y1 - (h/2), 0, num_iterations-1);
}


void 	sierpinski_error(t_env *e, int x1, int y1, int x2, int y2, int orientation, int num_iterations)
{
	int	l;
	int h;
	int x3;
	int y3;

	if(num_iterations == 0)
		return;;
	if (y1 != y2)
		return ;
	l = abs(x2 - x1);
	x3 = l / 2;
	h = sqrt((l * l) - (x3 * x3));
	y3 = (orientation == 0 ? y1 - h : y1 + h);
	x3 = x1 + x3;
	printf("C( %d, %d )\n", x3, y3);
	draw_line_mlx(x2, y2, x1, y1);
	draw_line_mlx(x3, y3, x2, y2);
	draw_line_mlx(x3, y3, x1, y1);
	sierpinski_error(e, (x1 + (l/4)), y3 + (h/2), (x1 + (l - (l/4))), y3 + (h/2), 1, num_iterations-1);

	sierpinski_error(e, x1, y1, (l / 2) + x1, y2, 0, num_iterations-1);
	sierpinski_error(e, x1 + (l / 2), y1, x2, y1, 0, num_iterations-1);
	sierpinski_error(e, x1 + (l / 4), y1 - (h/2), x2 - (l / 4), y1 - (h/2), 0, num_iterations-1);
}
