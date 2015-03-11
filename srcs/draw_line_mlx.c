/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_mlx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 19:04:25 by gmp               #+#    #+#             */
/*   Updated: 2015/03/11 18:14:27 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

static void		case1(int x1, int y1, int x2, int y2)
{
	int		y;
	int		x;
	int		dx;
	int		dy;

	x = x1;
	dx = x2 - x1;
	dy = y2 - y1;
	while (x < x2)
	{
		y = ((dy / (double)dx) * (x - x1)) + y1;
		img_pixel_put(x, y, 0xeeeeee);
		x++;
	}
}

static void		case2(int x1, int y1, int x2, int y2)
{
	int		y;
	int		x;
	int		dx;
	int		dy;

	x = x1;
	dx = x2 - x1;
	dy = y2 - y1;
	while (x < x2)
	{
		y = ((dy / (double)dx) * (x - x1)) + y1;
		img_pixel_put(x, y, 0xeeeeee);
		x++;
	}
}

static void		case3(int x1, int y1, int x2, int y2)
{
	int			y;

	(void)x2;
	if (y1 < y2)
		y = y1;
	else
	{
		y = y2;
		y2 = y1;
	}
	while (y < y2)
	{
		img_pixel_put(x1, y, 0xeeeeee);
		y++;
	}
}

void			draw_line_mlx(int x1, int y1, int x2, int y2)
{
	int			dx;
	int			dy;

	dx = x2 - x1;
	dy = y2 - y1;
	if (dx > 0 && dy <= 0)
		case1(x1, y1, x2, y2);
	else if (dx > 0 && dy > 0)
		case2(x1, y1, x2, y2);
	else if (dx < 0 && dy < 0)
		case2(x2, y2, x1, y1);
	else if (dx < 0 && dy >= 0)
		case1(x2, y2, x1, y1);
	else if (dx == 0 && dy != 0)
		case3(x1, y1, x2, y2);
}
