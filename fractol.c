#include "fractol.h"

/* Julia and Mandelbrot
 *
 * windows has to close with ESC and on X
 * infinite zoom
 *
 *
 *
 *
 *
 *
 * 
 *  ./fractol mandelbrot
 *  ./ fractol julia <real> <i>
 */


void	color_screen(t_mlx *data, int color)
{
	int	x;
	int	y;
	
	x = 0;
	y = 0;

	while (x < SIZE_X)
	{
		while (y < SIZE_Y)
		{
			mlx_pixel_put(data->connect, data->win, x, y, color);
			y++;
		}
		y = 0;
		x++;
	}
}

int	rgb_encoder(int red, int green, int blue)
{
	return (0 | red << 16 | green << 8 | blue);
}

int	rgb(int keysym, t_mlx *data)
{
	if (XK_r == keysym)
		color_screen(data, rgb_encoder(255, 0, 0));
	else if (XK_g == keysym)
		color_screen(data, rgb_encoder(0, 255, 0));
	else if (XK_b == keysym)
		color_screen(data, rgb_encoder(0, 0, 255));
	return (0);
}

int	main(int ac, char **av)
{
	if (2 == ac && !ft_strncmp(av[1], "mandelbrot", 10))
		write(1, "mandelbrot", 10);
	else if (2 == ac && !ft_strncmp(av[1], "julia", 5))
		write(1, "julia", 5);
	//if the prompt is correct, start the app 
	else
		ft_putstr_fd(ERROR_MESSAGE, 1);

	t_mlx	data;

	data_init(&data);


	
	mlx_key_hook(data.win, rgb, &data);
	mlx_loop(data.connect);

	mlx_destroy_display(data.connect);
	free(data.connect);
	return (0);
}
