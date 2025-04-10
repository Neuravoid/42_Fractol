/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ualkan <ualkan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:02:10 by ualkan            #+#    #+#             */
/*   Updated: 2025/03/22 08:24:51 by ualkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = img->pixels_ptr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

static	void	handle_pixel(t_fractal *fractal, int x, int y)
{
	t_complex	z;
	int			iter;
	int			color;
	double		iteration_val;

	z.real = (scale((t_map){x, -2, +2, 0, WIDTH})
			* fractal->zoom);
	z.i = (scale((t_map){y, +2, -2, 0, HEIGHT})
			* fractal->zoom);
	iter = make_fractal(fractal, &z);
	if (iter < fractal->iterations)
	{
		iteration_val = sqrt((double)iter * fractal->iterations);
		color = get_color(iteration_val, fractal->iterations);
		my_pixel_put(&fractal->img, x, y, color);
	}
	else
		my_pixel_put(&fractal->img, x, y, BLACK);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(fractal, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_connection,
		fractal->mlx_window,
		fractal->img.img_ptr,
		0, 0);
}
