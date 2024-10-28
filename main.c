#include <stdio.h>


double scale(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
	return ((new_max - new_min) * unscaled_num / old_max + new_min);
}

int	main()
{
	for (int i = 0; i < 1280; ++i)
	{
	printf("%d - >%f\n", i, scale((double)i, -2, +2, 0, 1279));
	}
}
