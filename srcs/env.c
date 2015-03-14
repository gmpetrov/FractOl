/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 12:53:44 by gmp               #+#    #+#             */
/*   Updated: 2015/03/14 15:03:26 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/base.h"

t_env	*get_env(void)
{
	static t_env	*e = NULL;

	if (e == NULL)
	{
		e = (t_env *)malloc(sizeof(t_env));
		e->mlx = mlx_init();
		e->win = mlx_new_window(e->mlx, 800, 600, "Fract'Ol");
		e->img = mlx_new_image(e->mlx, 800, 600);
		e->data = mlx_get_data_addr(e->img, &e->bpp, \
			&e->size_line, &e->endian);
		e->scale = 0;
		e->origin_x = 250;
		e->origin_y = 130;
		e->fractal = 1;
		e->lim = 9;
		e->infinity_loop = 0;
		e->mousex = 0;
		e->mousey = 0;
		e->mouse_x = 500;
		e->mouse_y = HEIGTH / 2.0;
		init_ptr_tab(e);
	}
	return (e);
}
