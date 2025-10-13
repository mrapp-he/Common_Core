/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:40:00 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/10/13 20:22:28 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

static void	set_resolution(int width, int heigth)
{
	if (width == 0 || heigth == 0)
		exit(input_error());
	db()->win_w = width;
	db()->win_h = heigth;
}

double	parse_complex(char *str)
{
	double	sgn;
	double	num;
	double	dec;

	num = 0.0;
	dec = 10.0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	sgn = (*str != '-') - (*str == '-');
	if (*str == '+' || *str == '-')
		str++;
	while ((*str >= '0' && *str <= '9') && (num <= DBL_MAX && num >= DBL_MIN))
		num = (num * 10) + (*str++ - '0');
	if (*str == '.')
		str++;
	while ((*str >= '0' && *str <= '9') && (num <= DBL_MAX && num >= DBL_MIN))
	{
		num += (*str++ - '0') / dec;
		dec *= 10.0;
	}
	if (num > DBL_MAX || num < DBL_MIN || *str != '\0')
		exit(input_error());
	return (num * sgn);
}

long	parse_input(char *str)
{
	long	num;

	num = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		exit(input_error());
	while ((*str >= '0' && *str <= '9') && (num <= LNG_MAX && num >= LNG_MIN))
		num = (num * 10) + (*str++ - '0');
	if (num > LNG_MAX || num < LNG_MIN || *str != '\0')
		exit(input_error());
	return (num);
}

void	parse_fractal(char *fractal)
{
	if (ft_strcmp(fractal, "mandelbrot") == 0)
	{
		db()->draw_fractal = &draw_mandelbrot;
		db()->type = 'm';
	}
	else if (ft_strcmp(fractal, "burning") == 0)
	{
		db()->draw_fractal = &draw_mandelbrot;
		db()->type = 'b';
	}
	else if (ft_strcmp(fractal, "julia") == 0)
	{
		db()->draw_fractal = &draw_julia;
		db()->type = 'j';
	}
	else
		exit(input_error());
}

void	parsing(int ac, char **av)
{
	t_data	*dt;

	dt = db();
	parse_fractal(av[1]);
	if (ac > 2)
		db()->max_iter = parse_input(av[2]);
	else
		dt->max_iter = MAX_ITER;
	if (ac > 3)
		set_resolution(parse_input(av[3]), parse_input(av[4]));
	else
		set_resolution(WIDTH, HEIGTH);
	if (ac > 5 && dt->type == 'j')
		db()->start = new_complex(parse_complex(av[5]), parse_complex(av[6]));
	else if (ac > 5 && dt->type != 'j')
		exit(input_error());
}
