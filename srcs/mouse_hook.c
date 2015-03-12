/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 18:22:53 by gpetrov           #+#    #+#             */
/*   Updated: 2015/03/12 13:24:07 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

int		mouse_hook(int button, int x, int y, t_env *e)
{
	e->mousex = (double)x / 1000;
	e->mousey = (double)y / 1000;
	expose_hook(e);
	return (0);
}
