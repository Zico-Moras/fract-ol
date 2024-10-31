#include "fractol.h"

int	shift_down(int	keysym, t_mlx * data)
{
	if (XK_Shift_L == keysym || XK_Shift_R == keysym)
		data->shift = 0;
	return (0);
}

int	key_handler(int keysym, t_mlx *data)
{
	if (XK_Shift_L == keysym || XK_Shift_R == keysym)
		data->shift = 1;
	if (XK_Escape == keysym)
		data_exit(data);
	else if (XK_Left == keysym)
		data->shift_x += data->last_x * 0.25;
	else if (XK_Right== keysym)
		data->shift_x -= data->last_x * 0.25;
	else if (XK_Up == keysym)
		data->shift_y -= data->last_y * 0.25;
	else if (XK_Down == keysym)
		data->shift_y += data->last_y * 0.25;
	else if ((61 == keysym && 1 == data->shift) || XK_plus == keysym)
		data->iterations += 10;
	else if (XK_minus == keysym)
		data->iterations -= 10;
	
	fractal_render(data);
	return (0);
}

int	mouse_handler(int keysym, int x, int y, t_mlx *data)
{
	x = 1;
	y = 1;
	if (Button5 == keysym && x) 
		data->zoom *= 0.95;
	if (Button4 == keysym && y) 
		data->zoom *= 1.05;

	fractal_render(data);
	return (0);
}

int	print_key(int keysym, t_mlx *data)
{
	printf("%d\n", keysym);
	data->win = data->win;
	return (0);
}
