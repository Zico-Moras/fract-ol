#include <stdio.h>

double map_pixel(double unscaled_num, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * unscaled_num / old_max + new_min);
}


int	main()
{

	printf("%f\n",(map_pixel(0, -2.666666, +2.666666, 1280) * 1) + (map_pixel(800, -2.666666, +2.666666, 1280)) );
	printf("%f\n",(map_pixel(0, -2.666666, +2.666666, 1280) * 1));
	printf("%f\n",(map_pixel(0, -2.666666, +2.666666, 1280) * 1) + (map_pixel(800, -2.666666, +2.666666, 1280)));
	printf("%f\n",(map_pixel(1280, -2.666666, +2.666666, 1280) * 1));
	printf("%f\n",(map_pixel(800, -2.666666, +2.666666, 1280) * 1));

}
