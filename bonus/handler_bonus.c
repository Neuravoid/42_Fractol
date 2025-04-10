/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ualkan <ualkan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:46:35 by ualkan            #+#    #+#             */
/*   Updated: 2025/03/21 23:13:03 by ualkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	close_handler(t_fractal *fractal)
{
	if (fractal == NULL)
		return (-1);
	if (fractal->img.img_ptr)
	{
		mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
		fractal->img.img_ptr = NULL;
	}
	if (fractal->mlx_window)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		fractal->mlx_window = NULL;
	}
	if (fractal->mlx_connection)
	{
		mlx_loop_end(fractal->mlx_connection);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		fractal->mlx_connection = NULL;
	}
	exit(EXIT_SUCCESS);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
	{
		close_handler(fractal);
		return (0);
	}
	if (keysym == XK_Left || keysym == 97)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == XK_Right || keysym == 100)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == XK_Up || keysym == 119)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == XK_Down || keysym == 115)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == XK_4)
		fractal->iterations += 10;
	else if (keysym == XK_minus)
		fractal->iterations -= 10;
	else if (keysym == 114)
		fractal->zoom = 1;
	else if (keysym == XK_c)
		fractal->color_mode = (fractal->color_mode % 5) + 1;
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	double	zoom_factor;

	(void) x;
	(void) y;
	if (button == 4)
		zoom_factor = 0.95;
	else if (button == 5)
		zoom_factor = 1.05;
	else
		return (0);
	fractal->zoom *= zoom_factor;
	fractal_render(fractal);
	return (0);
}
