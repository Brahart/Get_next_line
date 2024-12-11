/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:26:29 by asinsard          #+#    #+#             */
/*   Updated: 2024/12/11 20:20:35 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

char	*ft_bzero(char *str, int i)
{
	while (str[i])
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

char	*ft_read_buf_is_empty(char *buffer, int fd)
{
	char	*storage;
	int		read_size;

	read_size = 1;
	storage = ft_strdup(buffer);
	if (!storage)
		return (NULL);
	while (!ft_isnewline(storage) && read_size != 0)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if ((buffer[0] == '\0' && read_size == 0) || (read_size == -1))
			return (ft_bzero(buffer, 0), free(storage), NULL);
		buffer[read_size] = '\0';
		storage = ft_strjoin(storage, buffer);
		if (!storage)
			return (free(storage), NULL);
		if ((storage && ft_isnewline(storage))
			|| (storage[1] == '\0' && read_size > 1))
			break ;
	}
	ft_memmove(buffer, storage);
	return (storage);
}

char	*ft_read_buf_is_full(char *buffer, int fd)
{
	char	*storage;
	int		read_size;

	read_size = 1;
	storage = ft_strdup(buffer);
	if (!storage)
		return (NULL);
	while (!ft_isnewline(storage) && read_size != 0)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if ((buffer[0] == '\0' && read_size == 0) || (read_size == -1))
			return (ft_bzero(buffer, 0), free(storage), NULL);
		if (read_size < BUFFER_SIZE)
			buffer = ft_bzero(buffer, read_size);
		storage = ft_strjoin(storage, buffer);
		if (!storage)
			return (free(storage), NULL);
		if ((storage && ft_isnewline(storage)) || (storage[1] == '\0'))
			break ;
	}
	ft_memmove(buffer, storage);
	return (storage);
}

char	*ft_setline(char *line)
{
	int		i;
	char	*res;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	res = malloc(sizeof(char) * (i + 2));
	if (!res)
		return (free(line), NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		res[i] = line[i];
		i++;
	}
	if ((line[i] && line[i] == '\n'))
	{
		res[i] = '\n';
		i++;
	}
	res[i] = '\0';
	free(line);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = {0};
	char		*line;
	static int	fd_verif = -1;

	if (fd != fd_verif)
		buffer[0] = 0;
	fd_verif = fd;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[0])
		line = ft_read_buf_is_empty(buffer, fd);
	else
		line = ft_read_buf_is_full(buffer, fd);
	if (!line || line[0] == '\0')
		return (free(line), NULL);
	line = ft_setline(line);
	return (line);
}
/* #include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	char	*line;
	int		fd;
	int		i;

	i = 1;
	fd = open("txt.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("line %i: %s", i, line);
	i++;
	free(line);
	while(line)
	{
		line = get_next_line(fd);
		printf("line %i: %s", i, line);
		free(line);
		i++;
	}
	free(line);
	close(fd);
	return(0);
} */