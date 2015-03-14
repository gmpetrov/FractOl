/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 18:22:53 by gpetrov           #+#    #+#             */
/*   Updated: 2015/03/14 11:47:11 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

int		mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == 4)
	{
		if (e->scale >= 1000)
			e->scale = 400;
		e->scale += 10;
	}
	else if (button == 5)
	{
		if (e->scale == 0)
			return (0);
		e->scale -= 100;
	}
	e->mousex = (double)x / 1000;
	e->mousey = (double)y / 1000;
	expose_hook(e);
	return (0);
}
