/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francima <francima@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:07:47 by francima          #+#    #+#             */
/*   Updated: 2024/11/13 16:51:55 by francima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	main(int ac, char **av)
{
	t_mlx	data;

	if ((2 == ac && !ft_strcmp(av[1], "mandelbrot"))
		|| (4 == ac && !ft_strcmp(av[1], "julia")
			&& (ft_string_isdigit(av[2]) && av[2][0])
		&& (ft_string_isdigit(av[3]) && av[3][0])))
	{
		data.name = av[1];
		if (!ft_strcmp(av[1], "julia"))
		{
			data.julia_x = ft_atodbl(av[2]);
			data.julia_y = ft_atodbl(av[3]);
		}
		data_init(&data);
		events_init(&data);
		fractal_render(&data);
		mlx_loop(data.connect);
		data_exit(&data);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE_PART1, STDERR_FILENO);
		ft_putstr_fd(ERROR_MESSAGE_PART2, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
