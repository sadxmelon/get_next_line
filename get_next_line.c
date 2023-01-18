/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalghfel <aalghfel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:17:18 by aalghfel          #+#    #+#             */
/*   Updated: 2023/01/18 11:23:08 by aalghfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*initialize(char **buffer)
{
	char	*minibee;

	if (!(*buffer))
	{
		*buffer = malloc(1);
		**buffer = '\0';
	}
	if (!(*buffer))
		return (0);
	minibee = malloc(BUFFER_SIZE + 1);
	if (!minibee)
	{
		free(buffer);
		return (0);
	}
	return (minibee);
}

char	*ft_read(int fd, char *buffer)
{
	char	*minibee;
	char	*temp;
	int		num;

	minibee = initialize(&buffer);
	if (!minibee)
		return (0);
	while (1)
	{
		num = read(fd, minibee, BUFFER_SIZE);
		minibee[num] = 0;
		temp = buffer;
		buffer = ft_strjoin(buffer, minibee);
		free(temp);
		if (ft_strchr(minibee, '\n') || num < BUFFER_SIZE)
			break ;
	}
	free(minibee);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*result;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buffer, 0) < 0)
		return (0);
	buffer = ft_read(fd, buffer);
	if (!ft_strchr(buffer, '\n'))
		result = ft_strdup(buffer);
	else
		result = ft_substr(buffer, 0, ft_strchr(buffer, '\n') - buffer + 1);
	if (!*result)
	{
		free(result);
		free(buffer);
		buffer = 0;
		return (0);
	}
	temp = buffer;
	buffer = ft_substr(buffer, ft_strlen(result),
			ft_strlen(buffer) - ft_strlen(result));
	free(temp);
	return (result);
}
