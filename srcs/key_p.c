/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 19:15:50 by gpetrov           #+#    #+#             */
/*   Updated: 2015/03/11 19:15:57 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void 	key_p(void)
{
	t_env	*e;

	e = get_env();
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