/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 10:28:21 by gmp               #+#    #+#             */
/*   Updated: 2015/02/26 13:30:25 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
# define BASE_H

# define WIDTH 800
# define HEIGTH 600

# include "libft.h"
# include <mlx.h>
# include <math.h>
# include <fcntl.h>

/* STRUCTURES */

typedef struct 		s_env
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data;
	int 	bpp;
	int 	size_line;
	int 	endian;
	int 	scale;
	int 	origin_x;
	int 	origin_y;
	int 	fractal;
	int 	lim;
	int 	infinity_loop;
	void (*tab[42])();
}					t_env;

/* PROTOTYPES */

void 	check_params(t_env *e, int ac, char **av);
int 	expose_hook(t_env *e);
int 	key_hook(int keycode, t_env *e);
// int 	loop_hook(t_env *e);
void	initPtrTab(t_env *e);
t_env	*getEnv();
int 	keyMap(int keycode);
int 	img_pixel_put(t_env *e, int x, int y, int color);
void 	draw_line_mlx2(t_env *e, int x1, int y1, int x2, int y2, int z1 ,int z2);
void 	draw_line_mlx(t_env *e, int x1, int y1, int x2, int y2);
// void 	draw_triangle(t_env *e, int x1, int y1, int x2, int y2, int orientation, int num_iterations);

// void 	drawParallele(t_env *e);
// void 	drawIsometric(t_env *e);

void	drawGradient(t_env *e);

/* FRACTALS */

void 	sierpinski(t_env *e, int x1, int y1, int x2, int y2, int orientation, int num_iterations);
void 	sierpinski_error(t_env *e, int x1, int y1, int x2, int y2, int orientation, int num_iterations);


/* KEY FUNCTION */

void	key_escape(void);
void 	key_arrow_up(void);
void 	key_arrow_down(void);
void 	key_arrow_right(void);
void 	key_arrow_left(void);
void 	key_p(void);
void 	key_m(void);
void 	key_i(void);
void 	key_1(void);
void 	key_2(void);

/* END PROTOTYPES */

#endif