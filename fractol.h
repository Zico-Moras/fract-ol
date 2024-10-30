/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francima <francima@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:56:08 by francima          #+#    #+#             */
/*   Updated: 2024/09/25 19:01:26 by francima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
//INCLUDES

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>

//DEFINES

# define SIZE_X 1280
# define SIZE_Y 720
# define ERROR_MESSAGE "please enter maldelbrot or julia with the correct input"

#define BLACK         0x000000  // Black
#define WHITE         0xFFFFFF  // White
#define NEON_GREEN   0x39FF14  // Neon Green
#define NEON_PINK    0xFF6EC7  // Neon Pink
#define NEON_BLUE    0x1B03A3  // Neon Blue
#define NEON_YELLOW  0xE5FF00  // Neon Yellow
#define NEON_ORANGE  0xFF5F00  // Neon Orange
#define NEON_PURPLE  0xA500E0  // Neon Purple
#define CYAN         0x00FFFF   // Cyan
#define MAGENTA      0xFF00FF   // Magenta
#define LIME         0x00FF00   // Lime
#define VIOLET       0x8A2BE2   // Violet
#define ELECTRIC_BLUE 0x7DF9FF  // Electric Blue
#define HOT_PINK     0xFF69B4   // Hot Pink
#define TURQUOISE    0x40E0D0   // Turquoise
#define BRIGHT_RED    0xFF0000   // Bright Red
#define BRIGHT_YELLOW 0xFFFF00   // Bright Yellow
#define BRIGHT_CYAN   0x00FFFF   // Bright Cyan

//STRUCTS
typedef struct s_complex {
	double	x;
	double	y;
} t_complex;

typedef struct s_img {
	void	*img_ptr;
	char	*pixel_ptr;
	int	bits_per_pixel;
	int	line_size;
	int	endian;

} t_img;
typedef struct s_mlx {
	//mlx
	char	*name;
	void	*connect;
	void	*win;
	//img
	t_img	img;

	//hooks
	double	hypotenuse;
	int	iterations;
	double	shift_x;
	double	shift_y;
	double	zoom;
} t_mlx;

//functions
//
//mlx_funcs
void	data_init(t_mlx *data);
void	data_exit(t_mlx *data);
int	rgb_encoder(int red, int green, int blue);
void	events_init(t_mlx *data);
//
double map_pixel(double unscaled_num, double new_min, double new_max, double old_max);
void	my_pixel_put(int x, int y, t_mlx *data, int color);
void	fractal_render(t_mlx *data);
//math
t_complex	square_complex(t_complex z);
t_complex	sum_complex(t_complex z, t_complex c);
//events hooks
int	key_handler(int keysym, t_mlx *data);
int	print_key(int keysym, t_mlx *data);
int	mouse_handler(int keysym, int x, int y, t_mlx *data);








#endif
