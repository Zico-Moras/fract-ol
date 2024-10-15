/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francima <francima@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 08:13:53 by francima          #+#    #+#             */
/*   Updated: 2024/06/18 09:43:05 by francima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_isspace(int c)
{
	unsigned char	d;

	d = (unsigned char)c;
	if ((d >= 9 && d <= 13) || d == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	char	*string;
	int		i;
	int		numero;
	int		sinal;

	i = 0;
	numero = 0;
	sinal = 1;
	string = (char *)nptr;
	while (ft_isspace(*(string + i)))
		i++;
	if (*(string + i) == '-' || *(string + i) == '+')
	{
		if (*(string + i) == '-')
			sinal = -1;
		i++;
	}
	while (ft_isdigit(*(string + i)))
	{
		numero *= 10;
		numero += *(string + i) - 48;
		i++;
	}
	return (numero * sinal);
}
