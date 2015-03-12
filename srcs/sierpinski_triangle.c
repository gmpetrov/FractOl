/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski_triangle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 21:25:17 by gmp               #+#    #+#             */
/*   Updated: 2015/03/12 17:09:27 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

static void	sierpinski_norme(t_point *point, t_point *point2, t_point a, t_point b)
{
	point->x = a.x;
	point->y = a.y;
	point2->x = b.x;
	point2->y = b.y;
}

static void	sierpinski_norme2(t_point point, t_point point2, t_point point3)
{
	draw_line_mlx(point2.x, point2.y, point.x, point.y);
	draw_line_mlx(point3.x, point3.y, point2.x, point2.y);
	draw_line_mlx(point3.x, point3.y, point.x, point.y);
}

static void	sierpinski_norme3(t_point *a, t_point point, int l, int h)
{
	a->x = point.x + (l / 4);
	a->y = point.y - (h / 2);
}

static void	sierpinski_norme4(t_point *point3, int l, int *h)
{
	point3->x = l / 2;
	*h = sqrt((l * l) - (point3->x * point3->x));
}

void		sierpinski(t_point a, t_point b, int orientation, int num_iterations)
{
	int		l;
	int		h;
	t_point point;
	t_point	point2;
	t_point	point3;

	sierpinski_norme(&point, &point2, a, b);
	if (num_iterations == 0)
		return;
	if (point.y != point2.y)
		return ;
	l = abs(point2.x - point.x);
	sierpinski_norme4(&point3, l, &h);
	point3.y = (orientation == 0 ? point.y - h : point.y + h);
	point3.x = point.x + point3.x;
	sierpinski_norme2(point, point2, point3);
	b.x = (l / 2) + point.x;
	sierpinski(a, b, 0, num_iterations - 1);
	a.x = point.x + (l / 2);
	b.x = point2.x;
	sierpinski(a, b, 0, num_iterations - 1);
	sierpinski_norme3(&a, point, l, h);
	b.x = point2.x - (l / 4);
	b.y = point.y - (h / 2);
	sierpinski(a, b, 0, num_iterations - 1);
}
