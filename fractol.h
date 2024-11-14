/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nviana-p <nviana-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:56:08 by francima          #+#    #+#             */
/*   Updated: 2024/11/14 01:46:23 by nviana-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
// INCLUDES

# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// DEFINES

# define SIZE_X 800
# define SIZE_Y 800
# define ERROR_MESSAGE_PART1 "Please enter \n\t\"./fractol mandelbrot\" or \n\t"
# define ERROR_MESSAGE_PART2 "\"./fractol julia <value_1> <value_2>\"\n"
# define BLACK 0x000000         // Black
# define WHITE 0xFFFFFF         // White
# define NEON_GREEN 0x39FF14    // Neon Green
# define NEON_PINK 0xFF6EC7     // Neon Pink
# define NEON_BLUE 0x1B03A3     // Neon Blue
# define NEON_YELLOW 0xE5FF00   // Neon Yellow
# define NEON_ORANGE 0xFF5F00   // Neon Orange
# define NEON_PURPLE 0xA500E0   // Neon Purple
# define CYAN 0x00FFFF          // Cyan
# define MAGENTA 0xFF00FF       // Magenta
# define LIME 0x00FF00          // Lime
# define VIOLET 0x8A2BE2        // Violet
# define ELECTRIC_BLUE 0x7DF9FF // Electric Blue
# define HOT_PINK 0xFF69B4      // Hot Pink
# define TURQUOISE 0x40E0D0     // Turquoise
# define BRIGHT_RED 0xFF0000    // Bright Red
# define BRIGHT_YELLOW 0xFFFF00 // Bright Yellow
# define BRIGHT_CYAN 0x00FFFF   // Bright Cyan

// STRUCTS
typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixel_ptr;
	int		bits_per_pixel;
	int		line_size;
	int		endian;

}			t_img;
typedef struct s_mlx
{
	// mlx
	char	*name;
	void	*connect;
	void	*win;
	// img
	t_img	img;

	// hooks
	double	hypotenuse;
	int		iterations;
	double	last_x;
	double	last_y;
	double	shift_x;
	double	shift_y;
	double	zoom;
	int		shift;
	double	julia_x;
	double	julia_y;
}			t_mlx;

// functions
//
// mlx_funcs
void		data_init(t_mlx *data);
void		data_init2(t_mlx *data);
int			data_exit(t_mlx *data);
void		events_init(t_mlx *data);
//
double		map_pixel(double unscaled_num, double new_min, double new_max,
				double old_max);
void		my_pixel_put(int x, int y, t_mlx *data, int color);
void		fractal_render(t_mlx *data);
// math
t_complex	square_complex(t_complex z);
t_complex	sum_complex(t_complex z, t_complex c);
double		ft_atodbl(char *s);
// events hooks
int			key_handler(int keysym, t_mlx *data);
int			mouse_handler(int keysym, int x, int y, t_mlx *data);
int			shift_down(int keysym, t_mlx *data);
// strings
size_t		ft_string_isdigit(const char *s1);
size_t		ft_strcmp(const char *s1, const char *s2);
double		ft_atodbl(char *s);
void		ft_putstr_fd(char *s, int fd);
size_t		ft_strlen(char *str);
#endif
