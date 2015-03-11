/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 18:22:53 by gpetrov           #+#    #+#             */
/*   Updated: 2015/03/11 18:25:04 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

#include <stdio.h>

int 	mouse_hook(int button,int x,int y, t_env *e)
{
	(void)e;
	printf("button : %d, x : %d , y : %d\n", button, x, y);
	e->mousex = (double)x/1000;
	e->mousey = (double)y/1000;
	// printf("button : %d, x : %f , y : %f\n", button, e->mousex, e->mousey);
	expose_hook(e);
	return 0;
}
