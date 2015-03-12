/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 18:19:04 by gpetrov           #+#    #+#             */
/*   Updated: 2015/03/11 19:11:54 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

int			expose_hook(t_env *e)
{
	int		num_iterations;

	clear_img();
	draw_gradient();
	num_iterations = e->lim;
	if (e->fractal == 1)
		sierpinski(e, 200 - e->scale, 400, \
			WIDTH - 200 + e->scale, 400, 0, num_iterations);
	else if (e->fractal == 2)
		mendelbrot(e);
	else if (e->fractal == 3)
		julia(e);
	else if (e->fractal == 9)
		sierpinski_error(e, 200 - e->scale, 400, \
			WIDTH - 200 + e->scale, 400, 0, num_iterations);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}