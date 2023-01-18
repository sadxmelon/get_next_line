/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalghfel <aalghfel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:20:05 by aalghfel          #+#    #+#             */
/*   Updated: 2023/01/18 11:20:18 by aalghfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = 0;
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		return (&((char *)s)[i]);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	char	*sub;

	sub = malloc(len + 1);
	if (!sub)
		return (0);
	if (ft_strlen(s) <= start)
	{
		sub[0] = 0;
		return (sub);
	}
	j = 0;
	while (s[start] && j < len)
		sub[j++] = s[start++];
	sub[j] = 0;
	return (sub);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		size;
	char	*dup;

	size = ft_strlen(src);
	dup = malloc(size + 1);
	if (!dup)
		return (0);
	i = -1;
	while (src[++i])
		dup[i] = src[i];
	dup[i] = 0;
	return (dup);
}
