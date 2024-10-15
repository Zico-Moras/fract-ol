/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francima <francima@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 07:10:46 by francima          #+#    #+#             */
/*   Updated: 2024/06/22 07:19:53 by francima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temps;
	int		i;

	i = ft_strlen(s);
	temps = (char *)s;
	while (i != -1)
	{
		if (*(temps + i) == (char)c)
			return (temps + i);
		i--;
	}
	return (0);
}
