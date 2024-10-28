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
	if ((2 == ac && !ft_strncmp(av[1], "mandelbrot", 10)) || 
			(2 == ac && !ft_strncmp(av[1], "julia", 5)))
	{
		t_mlx	data;

		data_init(&data);
		data.name = av[1];
		mlx_loop(data.connect);

		data_exit(&data);
	}
	else
	{
		write(1, "wrong input", 11);
		exit(EXIT_FAILURE);
	}

}
