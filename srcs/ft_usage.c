/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 13:20:01 by gpetrov           #+#    #+#             */
/*   Updated: 2015/03/12 17:14:09 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void	ft_usage(void)
{
	ft_putstr("[USAGE] - ./fractol <arg>\n");
	ft_putstr("Arguments :\n");
	ft_putstr("1 : Sierpinski Triangle\n");
	ft_putstr("2 : Mendelbrot set\n");
	ft_putstr("3 : Mendelbrot set\n");
	exit(0);
}
