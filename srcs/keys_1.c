/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 18:00:30 by gmp               #+#    #+#             */
/*   Updated: 2015/02/26 13:46:27 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void 	key_p(void)
{
	t_env	*e;

	e = getEnv();
	if (e->scale >= 1000)
		e->scale = 400;
	e->scale += 10;
	// ft_putstr("scale = ");
	// ft_putnbr(e->scale);
	// ft_putstr("\n");

	// if ((WIDTH * e->scale) %  e->lim == e->lim)
		// e->lim++;
	expose_hook(e);
	ft_putstr("P\n");	
}

void 	key_i(void)
{
	t_env 	*e;

	ft_putstr("YOLO\n");
	e = getEnv();
	if (e->infinity_loop == 0)
		e->infinity_loop = 1;
	else
		e->infinity_loop = 0;
}

void 	key_m(void)
{
	t_env	*e;

	e = getEnv();
	if (e->scale == 0)
		return ;
	e->scale -= 100;
	expose_hook(e);
	ft_putstr("P\n");	
}

void 	key_1(void)
{
	t_env	*e;

	e = getEnv();
	e->fractal = 1;
	expose_hook(e);
	ft_putstr("P\n");	
}

void 	key_2(void)
{
	t_env	*e;

	e = getEnv();
	e->fractal = 9;
	expose_hook(e);
	ft_putstr("P\n");	
}