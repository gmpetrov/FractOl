/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_arrow_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 13:17:09 by gpetrov           #+#    #+#             */
/*   Updated: 2015/03/12 13:17:26 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void		key_arrow_up(void)
{
	t_env	*e;

	e = get_env();
	e->origin_y -= 10;
	expose_hook(e);
	ft_putstr("UP\n");
}