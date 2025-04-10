/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maker.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ualkan <ualkan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:42:38 by ualkan            #+#    #+#             */
/*   Updated: 2025/03/22 08:19:25 by ualkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	make_mandelbrot(t_fractal *fract, t_complex *c)
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

static int	make_julia(t_fractal *fract, t_complex *z)
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
	return (iter);
}
