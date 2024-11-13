/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francima <francima@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:16:54 by francima          #+#    #+#             */
/*   Updated: 2024/11/13 16:53:11 by francima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	mandel_vs_julia(t_complex *z, t_complex *c, t_mlx *data)
{
	if (!ft_strcmp(data->name, "julia"))
	{
		c->x = data->julia_x;
		c->y = data->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

/*
 * 
 *           |________1280________|
 *           | 			  |
 *           |			  |
 *     720   | 			  |
 *           | 			  |
 *           | 			  |
 *           |____________________|
 *
 *
 *           Z(n + 1) = Z(n)^2 + c
 *
 *           Z(0) = 0
 *           Z(1) = 0 + c
 *
 */
double	map_pixel(double unscaled_num, double new_min,
		double new_max, double old_max)
{
	return ((new_max - new_min) * unscaled_num / old_max + new_min);
}

void	my_pixel_put(int x, int y, t_mlx *data, int color)
{
	int	offset;

	offset = (y * data->img.line_size) + x * (data->img.bits_per_pixel / 8);
	*((unsigned int *)(data->img.pixel_ptr + offset)) = color;
}

static void	handle_pixel(t_mlx *data, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = (map_pixel(x, -2, 2, SIZE_X) * data->zoom)
		+ data->shift_x;
	z.y = (map_pixel(y, 2, -2, SIZE_Y) * data->zoom) - data->shift_y;
	mandel_vs_julia(&z, &c, data);
	while (++i < data->iterations)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x) * (z.x) + (z.y) * (z.y) > data->hypotenuse)
		{
			color = map_pixel(i, BLACK, WHITE, data->iterations);
			my_pixel_put(x, y, data, color);
			return ;
		}
		my_pixel_put(x, y, data, NEON_PURPLE);
	}
	data->last_x = c.x;
	data->last_y = c.y;
}

void	fractal_render(t_mlx *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < SIZE_Y)
	{
		x = -1;
		while (++x < SIZE_X)
		{
			handle_pixel(data, x, y);
		}
	}
	mlx_put_image_to_window(data->connect, data->win, data->img.img_ptr, 0, 0);
}
