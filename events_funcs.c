#include "fractol.h"

int	key_handler(int keysym, t_mlx *data)
{
	if (XK_Escape == keysym)
		data_exit(data);
	else if (XK_Left == keysym)
		data->shift_x += 0.5;
	else if (XK_Right== keysym)
		data->shift_x -= 0.5;
	else if (XK_Up == keysym)
		data->shift_y -= 0.5;
	else if (XK_Down == keysym)
		data->shift_y += 0.5;
	else if (61 == keysym)
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
	if (Button5 == keysym) 
		data->zoom = 0.95;
	if (Button4 == keysym) 
		data->zoom = 1.05;

	fractal_render(data);
	return (0);
}

int	print_key(int keysym, t_mlx *data)
{
	printf("%d\n", keysym);
	data->win = data->win;
	return (0);
}
