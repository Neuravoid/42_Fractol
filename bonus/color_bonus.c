/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ualkan <ualkan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 23:19:32 by ualkan            #+#    #+#             */
/*   Updated: 2025/03/21 23:23:57 by ualkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	convert_rgb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

int	hsl_to_rgb(double h)
{
	int	r;
	int	g;
	int	b;

	r = (int)(sin(h) * 127 + 128);
	g = (int)(sin(h + 2.0) * 127 + 128);
	b = (int)(sin(h + 4.0) * 127 + 128);
	return (convert_rgb(r, g, b));
}

int	get_color(int iter, int max_iter, int mode)
{
	double	t;
	double	hue;
	int		gray;
	int		inv;

	t = (double)iter / (double)max_iter;
	if (mode == 1)
		hue = t * 2 * M_PI;
	else if (mode == 2)
		hue = log(iter + 1) / log(max_iter) * 2 * M_PI;
	else if (mode == 3)
		hue = sin(t * 10.0) * 2 * M_PI;
	else if (mode == 4)
	{
		gray = (int)(t * 255);
		return (convert_rgb(gray, gray, gray));
	}
	else if (mode == 5)
	{
		inv = 255 - (int)(t * 255);
		return (convert_rgb(inv, inv / 2, inv));
	}
	else
		hue = t * 2 * M_PI;
	return (hsl_to_rgb(hue));
}
