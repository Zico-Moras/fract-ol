#include "fractol.h"

void	data_init(t_mlx *data)
{
	data->connect = mlx_init();
	data->win = mlx_new_window(data->connect, SIZE_X, SIZE_Y, "fract-ol");
	data->img.img_ptr = mlx_new_image(data->connect, SIZE_X, SIZE_Y);
	data->img.pixel_ptr = mlx_get_data_addr(data->img.img_ptr, &data->img.bits_per_pixel, &data->img.line_size, &data->img.endian);
}

void my_pixel_put(int x, int y, t_mlx *data, int color)
{
    int offset;

    // Calculate the correct memory offset
    offset = (y * data->img.line_size) + x * (data->img.bits_per_pixel / 8);

    // Set the pixel color at the calculated offset
    *((unsigned int*)(data->img.pixel_ptr + offset)) = color;
}

int	rgb_encoder(int red, int green, int blue)
{
	return (0 | red << 16 | green << 8 | blue);
}

