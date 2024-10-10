/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francima <francima@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 06:42:08 by francima          #+#    #+#             */
/*   Updated: 2024/06/22 06:42:10 by francima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*fs;
	size_t	i;

	i = 0;
	fs = malloc(ft_strlen(s) + 1);
	if (!fs)
		return (NULL);
	*(fs + ft_strlen(s)) = 0;
	while (i < ft_strlen(s))
	{
		fs[i] = (*f)(i, s[i]);
		i++;
	}
	return (fs);
}
