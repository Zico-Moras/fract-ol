/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francima <francima@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 06:34:25 by francima          #+#    #+#             */
/*   Updated: 2024/06/22 06:34:27 by francima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	inicio;
	size_t	fim;
	char	*trimmed;

	inicio = 0;
	fim = ft_strlen(s1) - 1;
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	if (!s1 || !set)
		return (0);
	while (*(s1 + inicio) && ft_strchr(set, *(s1 + inicio)))
		inicio++;
	while (fim > 0 && ft_strchr(set, *(s1 + fim)))
		fim--;
	if (fim < inicio)
		return (ft_strdup(""));
	trimmed = (char *)malloc(fim - inicio + 2);
	if (!trimmed)
		return (0);
	ft_strlcpy(trimmed, s1 + inicio, fim - inicio + 2);
	return (trimmed);
}
