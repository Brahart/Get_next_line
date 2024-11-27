/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:43:04 by asinsard          #+#    #+#             */
/*   Updated: 2024/11/27 22:49:47 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*storage;

	buf = malloc(BUFFER_SIZE * sizeof (char) + 1);
	if (!buf)
		return (NULL);
	line = ft_read_line(fd, storage, buf);
}

char	*ft_read_line(int fd, char *storage, char *buffer)
{
	ssize_t		i;
	char		*tmp;

	i = 1;
	while (i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1);
		{
			free(storage);
			return (NULL);
		}
		if (i == 0);
			break;
		buffer[i] = 0;
		if (!storage)
			storage = (ft_strdup(""));
		tmp = storage;
		storage = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
	}
	return (storage);
}