/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 12:53:44 by gmp               #+#    #+#             */
/*   Updated: 2015/02/26 23:24:01 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/base.h"

void	initPtrTab(t_env *e)
{
	e->tab[0] = &key_escape;
	e->tab[1] = &key_arrow_up;
	e->tab[2] = &key_arrow_down;
	e->tab[3] = &key_arrow_right;
	e->tab[4] = &key_arrow_left;
	e->tab[5] = &key_p;
	e->tab[6] = &key_m;
	e->tab[7] = &key_1;
	e->tab[8] = &key_2;
	e->tab[9] = &key_i;
	e->tab[10] = &key_3;
}

int 	keyMap(int keycode){
	if (65307 == keycode)
		return 0;
	else if (65362 == keycode)
		return 1;
	else if (65364 == keycode)
		return 2;
	else if (65363 == keycode)
		return 3;
	else if (65361 == keycode)
		return 4;
	else if (112 == keycode)
		return 5;
	else if (59 == keycode)
		return 6;
	else if (49 == keycode)
		return 7;
	else if (50 == keycode)
		return 8;
	else if (105 == keycode)
		return 9;
	else if (51 == keycode)
		return 10;
	return -1;
}

t_env	*getEnv()
{
	static t_env	*e = NULL;
	if (e == NULL){
		e = (t_env *)malloc(sizeof(t_env));
		e->mlx = mlx_init();
		e->win = mlx_new_window(e->mlx, 800, 600, "Fract'Ol");
		e->img = mlx_new_image(e->mlx, 800, 600);
		e->data = mlx_get_data_addr(e->img, &e->bpp, &e->size_line, &e->endian);
		e->scale = 0;
		e->origin_x = 250;
		e->origin_y = 130;
		e->fractal = 1;
		e->lim = 9;
		e->infinity_loop = 0;
		initPtrTab(e);
	}
	return e;
}