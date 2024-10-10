/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francima <francima@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:51:17 by francima          #+#    #+#             */
/*   Updated: 2024/05/14 12:44:04 by francima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*temp1;
	unsigned char	*temp2;

	temp1 = (unsigned char *)src;
	temp2 = (unsigned char *)dest;
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	if (dest > src)
	{
		temp2 += n - 1;
		temp1 += n - 1;
		while (n)
		{
			*temp2-- = *temp1--;
			n--;
		}
	}
	return (dest);
}
