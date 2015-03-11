/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 18:20:08 by gpetrov           #+#    #+#             */
/*   Updated: 2015/03/11 19:13:23 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

int		key_hook(int keycode, t_env *e)
{
	if (ft_isprint(keycode) == 1)
		ft_putnbr(keycode);
	else
		ft_putnbr(keycode);
	ft_putchar('\n');
	if (key_map(keycode) != -1)
		e->tab[key_map(keycode)]();
	return (0);
}
