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
	if (2 == ac && !strncmp(av[1], "mandelbrot", 10))

	else if (2 == ac && !strncmp(av[1], "julia", 5))

	else
		write(1, "wrong input\n", 12);

}
