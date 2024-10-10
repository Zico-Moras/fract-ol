/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francima <francima@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 07:12:22 by francima          #+#    #+#             */
/*   Updated: 2024/06/22 07:12:48 by francima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;

	join = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join)
		return (NULL);
	ft_memmove(join, s1, ft_strlen(s1));
	ft_memmove(join + ft_strlen(s1), s2, ft_strlen(s2));
	*(join + ft_strlen(s1) + ft_strlen(s2)) = 0;
	return (join);
}
