/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 18:00:30 by gmp               #+#    #+#             */
/*   Updated: 2015/03/11 19:16:01 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void 	key_i(void)
{
	t_env 	*e;

	ft_putstr("YOLO\n");
	e = get_env();
	if (e->infinity_loop == 0)
		e->infinity_loop = 1;
	else
		e->infinity_loop = 0;
}

void 	key_m(void)
{
	t_env	*e;

	e = get_env();
	if (e->scale == 0)
		return ;
	e->scale -= 100;
	expose_hook(e);
	ft_putstr("P\n");	
}

void 	key_1(void)
{
	t_env	*e;

	e = get_env();
	e->fractal = 1;
	expose_hook(e);
	ft_putstr("P\n");	
}

void 	key_2(void)
{
	t_env	*e;

	e = get_env();
	e->fractal = 2;
	expose_hook(e);
	ft_putstr("P\n");	
}

void 	key_3(void)
{
	t_env	*e;

	e = get_env();
	e->fractal = 3;
	expose_hook(e);
}