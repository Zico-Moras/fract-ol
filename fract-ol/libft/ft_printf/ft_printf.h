/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francima <francima@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 19:00:52 by francima          #+#    #+#             */
/*   Updated: 2024/07/23 22:39:51 by francima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h> 
# include <stdarg.h>
# include "../libft.h"

int	ft_printf(const char *form, ...);
int	ft_putchar(int c);
int	ft_putstr(char *string);
int	ft_putnbr(int n);
int	ft_putun(unsigned int n);
int	ft_hexlen(long n);
int	ft_puthex(unsigned long n, char *base);
int	ft_putpointer(unsigned long n);

#endif
