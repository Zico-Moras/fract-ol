#include "fractol.h"

static void	malloc_error()
{
	perror("Problem with malloc:");
	exit(EXIT_FAILURE);

}
void	data_init(t_mlx *data)
{
	data->connect = mlx_init();
	if (NULL == data->connect)
	{
		mlx_destroy_display(data->connect);
		free(data->connect);
		malloc_error();

	}
	data->win = mlx_new_window(data->connect, SIZE_X, SIZE_Y, data->name);
	if (NULL == data->win)
	{
		mlx_destroy_display(data->connect);
		free(data->connect);
		malloc_error();
	}
	data->img.img_ptr = mlx_new_image(data->connect, SIZE_X, SIZE_Y);
	if (NULL == data->img.img_ptr)
	{
		mlx_destroy_window(data->connect, data->win);
		mlx_destroy_display(data->connect);
		free(data->connect);
		malloc_error();
	}
	data->img.pixel_ptr = mlx_get_data_addr(data->img.img_ptr, &data->img.bits_per_pixel, &data->img.line_size, &data->img.endian);
	if (NULL == data->img.pixel_ptr)
	{
		mlx_destroy_image(data->connect, &data->img);
		mlx_destroy_window(data->connect, data->win);
		mlx_destroy_display(data->connect);
		free(data->connect);
		malloc_error();
	}
	data->hypotenuse = 4;
	data->iterations = 100;


}

void	data_exit(t_mlx *data)
{
	mlx_destroy_image(data->connect, data->img.img_ptr);
	mlx_destroy_window(data->connect, data->win);
	mlx_destroy_display(data->connect);
	free(data->connect);
}


int	rgb_encoder(int red, int green, int blue)
{
	return (0 | red << 16 | green << 8 | blue);
}

