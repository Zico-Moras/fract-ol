#include "fractol.h"

t_complex	sum_complex(t_complex z, t_complex c)
{
	t_complex	result;
	result.x = z.x + c.x;
	result.y = z.y + c.y;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;
	result.x = pow(z.x, 2) - pow(z.y, 2);
	result.y = 2 * z.x * z.y;
	return (result);
}

