/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 09:53:56 by gmp               #+#    #+#             */
/*   Updated: 2015/03/11 16:46:11 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void	key_escape(void)
{
	ft_putstr("escape\n");
	exit(0);
}

void 	ft_usage(void)
{
	ft_putstr("[USAGE] - ./fractol <arg>\n");
	ft_putstr("Arguments :\n");
	ft_putstr("1 : Sierpiński Triangle\n");
	ft_putstr("2 : Mendelbrot set\n");
	ft_putstr("3 : Mendelbrot set\n");
	ft_putstr("9 : Sierpiński Triangle with error\n");
	exit(0);
}

void 	check_params(t_env *e, int ac, char **av)
{
	if (ac != 2)
		ft_usage();
	if (ft_strlen(av[1]) == 1 && ft_isdigit(av[1][0]))
	{
		if (ft_atoi(av[1]) == 1)
			e->fractal = 1;
		else if (ft_atoi(av[1]) == 2)
			e->fractal = 2;
		else if (ft_atoi(av[1]) == 3)
			e->fractal = 3;
		else if (ft_atoi(av[1]) == 9)
			e->fractal = 9;
		else
			ft_usage();
	}
	else
		ft_usage();
}

int     main(int ac, char **av){
	t_env		*e;

	e = get_env();
	check_params(e, ac, av);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_loop(e->mlx);
    return (0);
}
