/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_arrow_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 13:18:16 by gpetrov           #+#    #+#             */
/*   Updated: 2015/03/12 13:18:32 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void		key_arrow_right(void)
{
	t_env	*e;

	e = get_env();
	e->origin_x += 10;
	expose_hook(e);
	ft_putstr("RIGHT\n");
}
