/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francima <francima@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 07:10:07 by francima          #+#    #+#             */
/*   Updated: 2024/06/22 07:17:09 by francima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	itoalen(int n)
{
	int	len;

	len = 0;
	if (n < 1)
	{
		if (n < 0)
			n *= -1;
		len++;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*itoa;
	int		len;
	int		sinal;
	long	nbr;

	nbr = (long)n;
	sinal = 0;
	len = itoalen(n);
	if (nbr < 0)
	{
		sinal = -1;
		nbr *= -1;
	}
	itoa = malloc(len + 1);
	if (!itoa)
		return (NULL);
	itoa[len] = 0;
	while (len--)
	{
		*(itoa + len) = nbr % 10 + '0';
		nbr /= 10;
	}
	if (sinal < 0)
		*(itoa) = '-';
	return (itoa);
}
