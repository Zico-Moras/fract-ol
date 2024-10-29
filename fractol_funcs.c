#include "fractol.h"



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

double map_pixel(double unscaled_num, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * unscaled_num / old_max + new_min);
}


void my_pixel_put(int x, int y, t_mlx *data, int color)
{
    int offset;

    // Calculate the correct memory offset
    offset = (y * data->img.line_size) + x * (data->img.bits_per_pixel / 8);

    // Set the pixel color at the calculated offset
    *((unsigned int*)(data->img.pixel_ptr + offset)) = color;
}

static void	handle_pixel(t_mlx *data, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int	i;
	int	color;


	z.x = 0;
	z.y = 0;
	i = -1;

	c.x = map_pixel(x, -2.666666, +2.666666, SIZE_X);
	c.y = map_pixel(y, +1.5, -1.5, SIZE_Y);

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
