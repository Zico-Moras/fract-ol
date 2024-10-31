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
	data->iterations = 42;
	data->shift_x = 0.0;
	data->shift_y = 0.0;
	data->zoom = 1;
	events_init(data);


}

int	data_exit(t_mlx *data)
{
	mlx_destroy_image(data->connect, data->img.img_ptr);
	mlx_destroy_window(data->connect, data->win);
	mlx_destroy_display(data->connect);
	free(data->connect);
	exit(EXIT_SUCCESS);
}


void	events_init(t_mlx *data)
{
	mlx_hook(data->win, KeyPress, KeyPressMask, key_handler, data);
	mlx_hook(data->win, KeyRelease, KeyReleaseMask, shift_down, data);
	//mlx_hook(data->win, KeyPress, KeyPressMask, print_key, data);
	mlx_hook(data->win, ButtonPress, ButtonPressMask, mouse_handler, data);
	mlx_hook(data->win, DestroyNotify, StructureNotifyMask, data_exit, data);
	//mlx_hook(data->win, ButtonPress, (1L<<0), close);
	//mlx_hook(data->win, ButtonPress, (1L<<0), close);


}
