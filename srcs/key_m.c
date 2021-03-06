/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_m.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 12:54:56 by gpetrov           #+#    #+#             */
/*   Updated: 2015/03/12 13:15:21 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void		key_m(void)
{
	t_env	*e;

	e = get_env();
	if (e->scale == 0)
		return ;
	e->scale -= 100;
	expose_hook(e);
	ft_putstr("P\n");
}
