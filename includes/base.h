/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 10:28:21 by gmp               #+#    #+#             */
/*   Updated: 2015/03/11 18:30:16 by gpetrov          ###   ########.fr       */
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

/*
**	STRUCTURES
*/

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct		s_point
{
	int				x;
	int				y;
	int 			color;
}					t_point;

typedef struct 		s_env
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
	int		scale;
	int		origin_x;
	int		origin_y;
	int		fractal;
	int		lim;
	int		infinity_loop;
	double	mousex;
	double	mousey;
	void	(*tab[42])();
}					t_env;

/*
** 	PROTOTYPES
*/

void	check_params(t_env *e, int ac, char **av);
int		expose_hook(t_env *e);
int		key_hook(int keycode, t_env *e);
int		mouse_hook(int button,int x,int y, t_env *e);
// int 	loop_hook(t_env *e);
void	init_ptr_tab(t_env *e);
t_env	*get_env();
int		key_map(int keycode);
int		img_pixel_put(int x, int y, int color);
void	draw_line_mlx(int x1, int y1, int x2, int y2);
void	draw_gradient(void);

/*
**	FRACTALS
*/

void 	sierpinski(t_env *e, int x1, int y1, int x2, int y2, int orientation, int num_iterations);
void 	sierpinski_error(t_env *e, int x1, int y1, int x2, int y2, int orientation, int num_iterations);
void 	mendelbrot(t_env *e);
void 	julia(t_env *e);
void 	check_set(t_env *e, int col, int row, double x, double y, double c_re, double c_im, int iteration, int max);
void 	check_julia_set(t_env *e, int col, int row, double x, double y, double c_re, double c_im, int iteration, int max);
void 	clear_img(void);


/*
**	KEY FUNCTION
*/

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
void 	key_3(void);

/*
**	END PROTOTYPES
*/

#endif