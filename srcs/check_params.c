/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 13:20:46 by gpetrov           #+#    #+#             */
/*   Updated: 2015/03/12 13:21:01 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void		check_params(t_env *e, int ac, char **av)
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
