/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francima <francima@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 00:44:38 by francima          #+#    #+#             */
/*   Updated: 2024/07/30 00:45:58 by francima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putpointer(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		return (write(1, "(nil)", 5));
	}
	len += ft_putstr("0x");
	len += ft_puthex(n, "0123456789abcdef");
	return (len);
}
