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

//DEFINES

# define  SIZE_X 1920
# define  SIZE_Y 1920

//STRUCTS
typedef struct s_mlx {
	void	*connect;
	void	*win;
} t_mlx;

#endif
