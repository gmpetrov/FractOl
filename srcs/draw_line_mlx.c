/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_mlx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 19:04:25 by gmp               #+#    #+#             */
/*   Updated: 2015/02/25 23:09:03 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void 	case1(t_env *e, int x1, int y1, int x2, int y2);
void 	case2(t_env *e, int x1, int y1, int x2, int y2);
void 	case3(t_env *e, int x1, int y1, int x2, int y2);

void 	draw_line_mlx(t_env *e, int x1, int y1, int x2, int y2)
{
	int 	dx;
	int 	dy;

	dx = x2 - x1;
	dy = y2 - y1;
	if (dx > 0 && dy <= 0){
		ft_putstr("case 1\n");
		case1(e, x1, y1, x2, y2);
	}
	else if (dx > 0 && dy > 0){
		ft_putstr("case 2\n");
		case2(e, x1, y1, x2, y2);
	}
	else if (dx < 0 && dy < 0){
		ft_putstr("case 3\n");
		case2(e, x2, y2, x1, y1);
	}
	else if (dx < 0 && dy >= 0){
		ft_putstr("case 4\n");
		case1(e, x2, y2, x1, y1);
	}
	else if (dx == 0 && dy != 0){
		ft_putstr("case 5\n");
		case3(e, x1, y1, x2, y2);
	}
}

void 	case1(t_env *e, int x1, int y1, int x2, int y2)
{
	int 	y;
	int 	x;
	int 	dx;
	int 	dy;

	x = x1;
	dx = x2 - x1;
	dy = y2 - y1;
	while (x < x2)
	{
		y = ((dy/(double)dx) * (x - x1)) + y1;
		img_pixel_put(e, x, y, 0xeeeeee);
		x++;
	}
}

void 	case2(t_env *e, int x1, int y1, int x2, int y2)
{
	int 	y;
	int 	x;
	int 	dx;
	int 	dy;

	x = x1;
	dx = x2 - x1;
	dy = y2 - y1;
	while (x < x2)
	{
		y = ((dy/(double)dx) * (x - x1)) + y1;
		img_pixel_put(e, x, y, 0xeeeeee);
		x++;
	}	
}

void 	case3(t_env *e, int x1, int y1, int x2, int y2)
{
	int 	y;

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
		img_pixel_put(e, x1, y, 0xeeeeee);
		y++;
	}
}