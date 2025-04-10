/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maker_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ualkan <ualkan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:42:47 by ualkan            #+#    #+#             */
/*   Updated: 2025/03/22 08:20:29 by ualkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	make_mandelbrot(t_fractal *fract, t_complex *c)
{
	double		real_temp;
	t_complex	z;
	int			iter;

	iter = 0;
	z.real = 0;
	z.i = 0;
	while ((z.real * z.real + z.i * z.i) < fract->escape
		&& iter < fract->iterations)
	{
		real_temp = z.real * z.real - z.i * z.i + c->real;
		z.i = 2 * z.real * z.i + c->i;
		z.real = real_temp;
		iter++;
	}
	return (iter);
}

int	make_julia(t_fractal *fract, t_complex *z)
{
	double		real_temp;
	t_complex	c;
	int			iter;

	iter = 0;
	c.real = fract->julia_x;
	c.i = fract->julia_y;
	while ((z->real * z->real + z->i * z->i) < fract->escape
		&& iter < fract->iterations)
	{
		real_temp = z->real * z->real - z->i * z->i + c.real;
		z->i = 2 * z->real * z->i + c.i;
		z->real = real_temp;
		iter++;
	}
	return (iter);
}

int	make_burning_ship(t_fractal *fract, t_complex *c)
{
	double		real_temp;
	t_complex	z;
	int			iter;

	iter = 0;
	z.real = 0;
	z.i = 0;
	while ((z.real * z.real + z.i * z.i) < fract->escape
		&& iter < fract->iterations)
	{
		real_temp = z.real * z.real - z.i * z.i + c->real;
		z.i = fabs(2 * z.real * z.i) + c->i;
		z.real = fabs(real_temp);
		iter++;
	}
	return (iter);
}

int	make_tricorn(t_fractal *fract, t_complex *c)
{
	double		real_temp;
	t_complex	z;
	int			iter;

	iter = 0;
	z.real = 0;
	z.i = 0;
	while ((z.real * z.real + z.i * z.i) < fract->escape
		&& iter < fract->iterations)
	{
		real_temp = z.real * z.real - z.i * z.i + c->real;
		z.i = -2 * z.real * z.i + c->i;
		z.real = real_temp;
		iter++;
	}
	return (iter);
}

int	make_celtic_mandelbar(t_fractal *fract, t_complex *c)
{
	double		real_temp;
	t_complex	z;
	int			iter;

	iter = 0;
	z.real = 0;
	z.i = 0;
	while ((z.real * z.real + z.i * z.i) < fract->escape
		&& iter < fract->iterations)
	{
		real_temp = fabs(z.real * z.real - z.i * z.i);
		z.i = -2 * z.real * z.i + c->i;
		z.real = real_temp + c->real;
		iter++;
	}
	return (iter);
}
