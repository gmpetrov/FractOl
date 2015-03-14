/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 16:41:54 by gpetrov           #+#    #+#             */
/*   Updated: 2015/03/14 11:49:29 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

int		key_map(int keycode)
{
	if (65307 == keycode)
		return (0);
	else if (65362 == keycode)
		return (1);
	else if (65364 == keycode)
		return (2);
	else if (65363 == keycode)
		return (3);
	else if (65361 == keycode)
		return (4);
	else if (112 == keycode)
		return (5);
	else if (59 == keycode)
		return (6);
	else if (49 == keycode)
		return (7);
	else if (50 == keycode)
		return (8);
	else if (105 == keycode)
		return (9);
	else if (51 == keycode)
		return (10);
	return (-1);
}
