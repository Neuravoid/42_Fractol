/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maker2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ualkan <ualkan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:45:59 by ualkan            #+#    #+#             */
/*   Updated: 2025/03/22 08:20:01 by ualkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static	double	box_fold(double z)
{
	if (z > 1)
		z = 2 - z;
	else if (z < -1)
		z = -2 - z;
	return (z);
}

static double	ball_fold(double r, double m)
{
	if (m < r)
		m = m / (r * r);
	else if (m < 1)
		m = 1 / (m * m);
	return (m);
}

static int	make_mandelbox(t_fractal *fract, t_complex *c)
{
	double		outlier;
	t_complex	z;
	int			iter;

	iter = 0;
	outlier = 0;
	z.real = c->real;
	z.i = c->i;
	while ((outlier < fract->escape) && (iter < fract->iterations))
	{
		z.real = FIXED_RADIUS * box_fold(z.real);
		z.i = FIXED_RADIUS * box_fold(z.i);
		outlier = sqrt(z.real * z.real + z.i * z.i);
		z.real = z.real * SCALE * ball_fold(MINIMUM_RADIUS, outlier) + c->real;
		z.i = z.i * SCALE * ball_fold(MINIMUM_RADIUS, outlier) + c->i;
		iter++;
	}
	return (iter);
}

int	make_fractal(t_fractal *fract, t_complex *c)
{
	int		iter;
	char	*name;

	name = fract->name;
	iter = 0;
	if (!ft_strcmp(name, "mandelbrot"))
		iter = make_mandelbrot(fract, c);
	else if (!ft_strcmp(name, "julia"))
		iter = make_julia(fract, c);
	else if (!ft_strcmp(name, "burningship"))
		iter = make_burning_ship(fract, c);
	else if (!ft_strcmp(name, "tricorn"))
		iter = make_tricorn(fract, c);
	else if (!ft_strcmp(name, "celtic"))
		iter = make_celtic_mandelbar(fract, c);
	else if (!ft_strcmp(name, "mandelbox"))
		iter = make_mandelbox(fract, c);
	return (iter);
}
