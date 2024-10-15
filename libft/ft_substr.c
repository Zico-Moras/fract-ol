/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francima <francima@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 06:33:15 by francima          #+#    #+#             */
/*   Updated: 2024/06/22 06:43:13 by francima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	lensub;

	lensub = 0;
	if (!*s || start > ft_strlen(s))
		return (ft_strdup(""));
	while (lensub < len && *(s + start + lensub))
		lensub++;
	sub = (char *)malloc(lensub + 1);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, lensub + 1);
	return (sub);
}
