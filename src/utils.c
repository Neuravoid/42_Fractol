/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ualkan <ualkan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:49:31 by ualkan            #+#    #+#             */
/*   Updated: 2025/03/20 14:28:21 by ualkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scale(t_map coordinate)
{
	return ((coordinate.new_max - coordinate.new_min)
		* (coordinate.unscaled_num - coordinate.old_min)
		/ (coordinate.old_max - coordinate.old_min) + coordinate.new_min);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i + 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	i = 0;
	if (len_s1 != len_s2 || len_s1 == 0 || len_s2 == 0)
		return (1);
	while ((s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

double	atodbl(char *s)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	sign = +1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign = -sign;
	while (*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - 48);
	if ('.' == *s)
		++s;
	while (*s)
	{
		pow /= 10;
		fractional_part = fractional_part + (*s++ - 48) * pow;
	}
	return ((integer_part + fractional_part) * sign);
}

void	show_help(void)
{
	write(1, RED "ERROR: Invalid usage!\n" RESET "\n", 32);
	write(1, GREEN "\nUsage: ./fractol [fractal_name]\n" RESET "\n", 39);
	write(1, YELLOW "\nAvailable fractals:\n" RESET "\n", 28);
	write(1, BLUE "\n- mandelbrot, julia\n" RESET "\n", 28);
	write(1, RED "\nTry again!\n" RESET "\n", 23);
	exit(EXIT_FAILURE);
}
