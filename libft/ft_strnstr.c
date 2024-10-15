/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francima <francima@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 06:53:15 by francima          #+#    #+#             */
/*   Updated: 2024/06/22 06:53:16 by francima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	n;
	size_t	n2;

	n = 0;
	n2 = 0;
	if (little[0] == 0)
		return ((char *)big);
	while (big[n] && n < len)
	{
		while (big[n + n2] == little[n2] && big[n + n2] && n + n2 < len)
			n2++;
		if (little[n2] == 0)
			return ((char *)big + n);
		n2 = 0;
		n++;
	}
	return (0);
}
