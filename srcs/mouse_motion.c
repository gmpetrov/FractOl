/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_motion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 11:00:36 by gmp               #+#    #+#             */
/*   Updated: 2015/03/14 14:51:40 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

int				mouse_motion(int x, int y, t_env *e)
{
	e->mousex = (double)x;
	e->mousey = (double)y;
	expose_hook(e);
	return (0);
}
