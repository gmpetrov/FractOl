/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 18:23:23 by gpetrov           #+#    #+#             */
/*   Updated: 2015/03/11 18:36:23 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void	clear_img(void)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < HEIGTH)
	{
		while (x < WIDTH)
		{
			img_pixel_put(x, y, 0x000000);
			x++;
		}
		x = 0;
		y++;
	}
}
