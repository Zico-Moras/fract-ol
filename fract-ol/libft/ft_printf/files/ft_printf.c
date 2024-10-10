/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francima <francima@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 19:04:44 by francima          #+#    #+#             */
/*   Updated: 2024/07/30 00:54:12 by francima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	conversions(const char *form, va_list args)
{
	if (*(form + 1) == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (*(form + 1) == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (*(form + 1) == 'd' || *(form + 1) == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (*(form + 1) == 'u')
		return (ft_putun(va_arg(args, unsigned int)));
	if (*(form + 1) == 'x')
		return (ft_puthex(va_arg(args, unsigned long), "0123456789abcdef"));
	if (*(form + 1) == 'X')
		return (ft_puthex(va_arg(args, unsigned long), "0123456789ABCDEF"));
	if (*(form + 1) == '%')
		return (write(1, "%", 1));
	if (*(form + 1) == 'p')
		return (ft_putpointer(va_arg(args, unsigned long)));
	return (0);
}

int	ft_printf(const char *form, ...)
{
	int		i;
	va_list	args;

	va_start(args, form);
	i = 0;
	while (*form)
	{
		if (*form == '%')
		{
			i += conversions(form, args);
			form += 2;
		}
		else
		{
			write(1, form, 1);
			i++;
			form++;
		}
	}
	va_end(args);
	return (i);
}
