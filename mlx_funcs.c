#include "fractol.h"

void	data_init(t_mlx *data)
{
	data->connect = mlx_init();
	data->win = mlx_new_window(data->connect, SIZE_X, SIZE_Y, "fract-ol");
	data->img.img_ptr = mlx_new_image(data->connect, SIZE_X, SIZE_Y);
}
