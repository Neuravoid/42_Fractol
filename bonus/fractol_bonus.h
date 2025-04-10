/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ualkan <ualkan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:42:10 by ualkan            #+#    #+#             */
/*   Updated: 2025/03/22 08:15:43 by ualkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <X11/X.h>  
# include <X11/keysym.h>
# include <stdio.h>

# define WIDTH 800
# define HEIGHT 800
# define BLACK 0x000000
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define RESET "\033[0m"
# define SCALE 2
# define FIXED_RADIUS 1
# define MINIMUM_RADIUS 0.5

typedef struct s_map
{
	double	unscaled_num;
	double	new_min;
	double	new_max;
	double	old_min;
	double	old_max;
}			t_map;

typedef struct s_complex
{
	double	real;
	double	i;
}	t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_fractal
{
	void	*mlx_connection;
	void	*mlx_window;
	char	*name;
	t_img	img;
	int		escape;
	int		iterations;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
	int		color_mode;
}	t_fractal;

size_t		ft_strlen(char *str);
int			ft_strcmp(char *s1, char *s2);
double		atodbl(char *s);

void		show_help(void);

void		fractal_init(t_fractal *fractal);
double		scale(t_map coordinate);

int			make_fractal(t_fractal *fract, t_complex *c);
int			make_mandelbrot(t_fractal *fract, t_complex *c);
int			make_julia(t_fractal *fract, t_complex *c);
int			make_burning_ship(t_fractal *fract, t_complex *c);
int			make_tricorn(t_fractal *fract, t_complex *c);
int			make_celtic_mandelbar(t_fractal *fract, t_complex *c);

void		fractal_render(t_fractal *fractal);
int			get_color(int iter, int max_iter, int mode);

int			key_handler(int keysym, t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
int			close_handler(t_fractal *fractal);

#endif
