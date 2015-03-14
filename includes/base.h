/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 10:28:21 by gmp               #+#    #+#             */
/*   Updated: 2015/03/14 11:48:02 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
# define BASE_H
# define WIDTH 800
# define HEIGTH 600
# define MAX_ITER_JULIA 50
# define MAX_ITER_MEDELBROT 100
# define MAX_ITER_SIERPINSKI 9
# include "libft.h"
# include </usr/X11/include/X11/X.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h>

/*
**	STRUCTURES
*/

typedef	struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef	struct	s_point
{
	int			x;
	int			y;
	int			color;
}				t_point;

typedef	struct	s_dpnt
{
	int			col;
	int			row;
	double		x;
	double		y;
	double		c_re;
	double		c_im;
}				t_dpnt;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
	int			scale;
	int			origin_x;
	int			origin_y;
	int			fractal;
	int			lim;
	int			infinity_loop;
	double		mousex;
	double		mousey;
	void		(*tab[42])();
}				t_env;

/*
** 	PROTOTYPES
*/

void			check_params(t_env *e, int ac, char **av);
int				expose_hook(t_env *e);
int				key_hook(int keycode, t_env *e);
int				mouse_hook(int button, int x, int y, t_env *e);
void			init_ptr_tab(t_env *e);
t_env			*get_env();
int				key_map(int keycode);
int				img_pixel_put(int x, int y, int color);
void			draw_line_mlx(int x1, int y1, int x2, int y2);
void			draw_gradient(void);
void			ft_usage(void);
int				mouse_motion(int x, int y, t_env *e);

/*
**	FRACTALS
*/

void			sierpinski(t_point a, t_point b, \
	int orientation, int num_iterations);
void			sierpinski_error(int x1, int y1, int x2, \
	int y2, int orientation, int num_iterations);
void			mendelbrot(t_env *e);
void			julia(t_env *e);
void			check_set(t_dpnt point, double x, double y, int iteration);
void			check_julia_set(t_env *e, t_dpnt point, int iteration);
void			clear_img(void);

/*
**	KEY FUNCTION
*/

void			key_escape(void);
void			key_arrow_up(void);
void			key_arrow_down(void);
void			key_arrow_right(void);
void			key_arrow_left(void);
void			key_p(void);
void			key_m(void);
void			key_i(void);
void			key_1(void);
void			key_2(void);
void			key_3(void);

/*
**	END PROTOTYPES
*/

#endif
