/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 18:00:30 by gmp               #+#    #+#             */
/*   Updated: 2015/02/26 12:02:28 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void 	key_p(void)
{
	t_env	*e;

	e = getEnv();
	e->scale += 100;
	// if ((WIDTH * e->scale) %  e->lim == e->lim)
		// e->lim++;
	expose_hook(e);
	ft_putstr("P\n");	
}

void 	key_m(void)
{
	t_env	*e;

	e = getEnv();
	if (e->scale == 0)
		return ;
	e->scale -= 1;
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