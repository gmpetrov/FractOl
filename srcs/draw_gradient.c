/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_gradient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 18:21:24 by gpetrov           #+#    #+#             */
/*   Updated: 2015/03/11 18:37:47 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void			draw_gradient(void)
{
	t_point		point;
	t_color		color;

	point.x = -1;
	point.y = -1;
	color.r = 0xFF;
	color.g = 0x00;
	color.b = 0x42;
	point.color = 0xFF0000;
	while (++point.y < HEIGTH)
	{
		while (++point.x < WIDTH)
			img_pixel_put(point.x, point.y, point.color);
		if (point.y % 2 == 0)
		{
			if (color.r < 0xFF)
				color.r++;
			if (color.g < 0xFF)
				color.g++;
			if (color.b < 0xFF)
				color.b++;
		}
		point.color = (color.b) + (color.g << 8) + (color.r << 16);
		point.x = -1;
	}
}
