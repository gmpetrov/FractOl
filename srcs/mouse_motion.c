/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_motion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 11:00:36 by gmp               #+#    #+#             */
/*   Updated: 2015/03/14 11:11:40 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

int				mouse_motion(int x, int y, t_env *e)
{
	// (void)e;
	// ft_putnbr(x);
	// ft_putchar('\n');
	// ft_putnbr(y);
	// ft_putchar('\n');
	e->mousex = (double)x / 1000;
	e->mousey = (double)y / 1000;
	expose_hook(e);
	return (0);
}
