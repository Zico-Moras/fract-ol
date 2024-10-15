/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francima <francima@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 06:55:09 by francima          #+#    #+#             */
/*   Updated: 2024/06/19 08:19:33 by francima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dup;

	i = 0;
	dup = (char *)malloc(ft_strlen(s) + 1);
	if (!dup)
		return (0);
	while (i < ft_strlen(s) + 1)
	{
		dup[i] = s[i];
		i++;
	}
	return (dup);
}
