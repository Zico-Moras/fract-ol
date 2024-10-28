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
# include <unistd.h>
# include <math.h>

//DEFINES

# define SIZE_X 1280
# define SIZE_Y 720
# define ERROR_MESSAGE "please enter maldelbrot or julia with the correct input"
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
} t_mlx;

//functions
//
//mlx_funcs
void	data_init(t_mlx *data);
int	rgb_encoder(int red, int green, int blue);
void	my_pixel_put(int x, int y, t_mlx *data, int color);
void	data_exit(t_mlx *data);
static void	malloc_error();




#endif
