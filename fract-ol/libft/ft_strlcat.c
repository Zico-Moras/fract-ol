/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francima <francima@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:53:04 by francima          #+#    #+#             */
/*   Updated: 2024/05/14 14:36:08 by francima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < size && *(dest + i))
		i++;
	if (i == size)
		return (size + ft_strlen(src));
	while (i + j < size - 1 && *(src + j))
	{
		*(dest + i + j) = *(src + j);
		j++;
	}
	dest[i + j] = 0;
	return (i + ft_strlen(src));
}
