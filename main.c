#include <stdio.h>

double map_pixel(double unscaled_num, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * unscaled_num / old_max + new_min);
}

size_t	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
size_t	ft_string_isdigit(const char *s1)
{
	size_t	i;
	int	dot;

	dot = 0;
	i = 0;
	while (s1[i])
	{
		if (((s1[i] >= '0' && s1[i] <= '9') || (s1[i] == '.')) && dot <= 1)
		{
			if (s1[i] == '.')
			{
				if ((s1[i + 1] >= '0' && s1[i + 1] <= '9'))
					dot++;
				else
					return (1);
			}
			i++;
		}
		else
			return (1);
	}
	return (0);
}

double	ft_atodbl(char *s)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	sign = +1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign = -sign;
	while (*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - 48);
	if ('.' == *s)
		++s;
	while (*s)
	{
		pow /= 10;
		fractional_part = fractional_part + (*s++ - 48) * pow;
	}
	return ((integer_part + fractional_part) * sign);
}


int	main()
{
	printf("%f", ft_atodbl("0.4"));


}
