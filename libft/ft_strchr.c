/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francima <francima@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 07:08:21 by francima          #+#    #+#             */
/*   Updated: 2024/06/22 07:20:08 by francima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*temp_s;

	i = 0;
	temp_s = (char *)s;
	while (*(temp_s + i) != (char)c && *(temp_s + i))
		i++;
	if (*(temp_s + i) == (char)c)
		return (temp_s + i);
	return (0);
}
