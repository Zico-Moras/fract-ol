/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francima <francima@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 10:39:18 by francima          #+#    #+#             */
/*   Updated: 2024/06/23 10:46:41 by francima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	wordscounter(char const *s, char c)
{
	int		flag;
	size_t	counter;

	counter = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			counter++;
			flag = 1;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (counter);
}

static size_t	strlen_c(const char *s, char c)
{
	size_t	i;	

	i = 0;
	while (*(s + i) && *(s + i) != c)
		i++;
	return (i);
}

static void	free_mem(char **ss, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
		free(ss[i++]);
	free(ss);
}

char	**ft_split(char const *s, char c)
{
	char	**ss;
	int		i;
	size_t	j;

	j = 0;
	i = 0;
	ss = malloc(sizeof(char *) * (wordscounter(s, c) + 1));
	if (!ss)
		return (NULL);
	while (*(s + i))
	{
		if (*(s + i) == c)
			i++;
		else if (*(s + i) != c)
		{
			ss[j] = ft_substr(s, i, strlen_c(s + i, c));
			if (!ss[j])
				return (free_mem(ss, j), NULL);
			j++;
			i += strlen_c(s + i, c);
		}
	}
	ss[j] = 0;
	return (ss);
}
