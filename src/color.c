/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ualkan <ualkan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 23:22:51 by ualkan            #+#    #+#             */
/*   Updated: 2025/03/21 23:22:36 by ualkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	convert_rgb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

static int	hsl_to_rgb(double h)
{
	int	r;
	int	g;
	int	b;

	r = (int)(sin(h) * 127 + 128);
	g = (int)(sin(h + 2.0) * 127 + 128);
	b = (int)(sin(h + 4.0) * 127 + 128);
	return (convert_rgb(r, g, b));
}

int	get_color(int iter, int max_iter)
{
	double	t;
	double	hue;

	t = (double)iter / (double)max_iter;
	hue = sin(t * 10.0) * 2 * M_PI;
	return (hsl_to_rgb(hue));
}
