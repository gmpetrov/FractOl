/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 18:19:04 by gpetrov           #+#    #+#             */
/*   Updated: 2015/03/12 17:14:04 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

int			expose_hook(t_env *e)
{
	int		num_iterations;
	t_point a;
	t_point	b;

	a.x = 200 - e->scale;
	a.y = 400;
	b.x = WIDTH - 200 + e->scale;
	b.y = 400;
	clear_img();
	draw_gradient();
	num_iterations = e->lim;
	if (e->fractal == 1)
		sierpinski(a, \
			b, 0, num_iterations);
	else if (e->fractal == 2)
		mendelbrot(e);
	else if (e->fractal == 3)
		julia(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}
