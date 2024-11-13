/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francima <francima@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:23:35 by francima          #+#    #+#             */
/*   Updated: 2024/11/13 16:23:36 by francima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	shift_down(int keysym, t_mlx *data)
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
	else if (XK_Right == keysym)
		data->shift_x -= data->last_x * 0.25;
	else if (XK_Up == keysym)
		data->shift_y += data->last_y * 0.25;
	else if (XK_Down == keysym)
		data->shift_y -= data->last_y * 0.25;
	else if ((61 == keysym && 1 == data->shift) || XK_plus == keysym)
		data->iterations += 10;
	else if (XK_minus == keysym)
		data->iterations -= 10;
	fractal_render(data);
	return (0);
}

int	mouse_handler(int keysym, int x, int y, t_mlx *data)
{
	double	mouse_re;
	double	mouse_im;
	double	zoom_factor;

	mouse_re = map_pixel(x, -2.666666, +2.666666, SIZE_X)
		* data->zoom + data->shift_x;
	mouse_im = map_pixel(y, -1.5, +1.5, SIZE_Y)
		* data->zoom + data->shift_y;
	if (Button5 == keysym)
		zoom_factor = 0.95;
	else if (Button4 == keysym)
		zoom_factor = 1.05;
	else
		return (0);
	data->shift_x = mouse_re + (data->shift_x - mouse_re) * zoom_factor;
	data->shift_y = mouse_im + (data->shift_y - mouse_im) * zoom_factor;
	data->zoom *= zoom_factor;
	fractal_render(data);
	return (0);
}

int	print_key(int keysym, t_mlx *data)
{
	printf("%d\n", keysym);
	data->win = data->win;
	return (0);
}
