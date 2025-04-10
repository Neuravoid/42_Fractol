/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ualkan <ualkan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:59:34 by ualkan            #+#    #+#             */
/*   Updated: 2025/03/20 13:12:10 by ualkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	is_valid_number(char *s)
{
	int		i;
	int		dot_count;

	if (!s || !s[0])
		return (0);
	i = 0;
	dot_count = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i] || s[i] == '.' || s[ft_strlen(s) - 1] == '.')
		return (0);
	while (s[i])
	{
		if (s[i] == '.')
			dot_count++;
		else if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
		if (dot_count > 1)
			return (0);
		i++;
	}
	return (1);
}

static int	letter_checker(char *s1, char *s2)
{
	if (!is_valid_number(s1) || !is_valid_number(s2))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (ac == 2 && (!ft_strcmp(av[1], "mandelbrot")))
	{
		fractal.name = av[1];
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else if (ac == 4 && !ft_strcmp(av[1], "julia")
		&& !letter_checker(av[2], av[3]))
	{
		fractal.name = av[1];
		fractal.julia_x = atodbl(av[2]);
		fractal.julia_y = atodbl(av[3]);
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
		show_help();
}
