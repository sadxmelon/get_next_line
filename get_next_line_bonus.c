/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalghfel <aalghfel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:57:14 by aalghfel          #+#    #+#             */
/*   Updated: 2023/01/18 14:58:26 by aalghfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*buffer[12288];
	char		*result;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buffer[fd], 0) < 0)
		return (0);
	buffer[fd] = ft_read(fd, buffer[fd]);
	if (!ft_strchr(buffer[fd], '\n'))
		result = ft_strdup(buffer[fd]);
	else
		result = ft_substr(buffer[fd], 0,
				ft_strchr(buffer[fd], '\n') - buffer[fd] + 1);
	if (!*result)
	{
		free(result);
		free(buffer[fd]);
		buffer[fd] = 0;
		return (0);
	}
	temp = buffer[fd];
	buffer[fd] = ft_substr(buffer[fd], ft_strlen(result),
			ft_strlen(buffer[fd]) - ft_strlen(result));
	free(temp);
	return (result);
}
