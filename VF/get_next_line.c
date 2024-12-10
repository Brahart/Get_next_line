/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:26:29 by asinsard          #+#    #+#             */
/*   Updated: 2024/12/10 17:54:27 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	int		i;

	i = 1;
	storage = ft_strdup(buffer);
	if (!storage)
		return (NULL);
	while (!ft_isnewline(storage) && i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if ((buffer[0] == '\0' && i == 0) || (i == -1))
			return (ft_bzero(buffer, 0), free(storage), NULL);
		buffer[i] = '\0';
		storage = ft_strjoin(storage, buffer);
		if (!storage)
			return (NULL);
		if ((storage && ft_isnewline(storage)) || (storage[1] == '\0' && i > 1))
			break ;
	}
	buffer = ft_memmove(buffer, storage);
	return (storage);
}

char	*ft_read_buf_is_full(char *buffer, int fd)
{
	char	*storage;
	int		i;

	i = 1;
	storage = ft_strdup(buffer);
	if (!storage)
		return (NULL);
	while (!ft_isnewline(storage) && i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if ((buffer[0] == '\0' && i == 0) || (i == -1))
			return (ft_bzero(buffer, 0), free(storage), NULL);
		if (i < BUFFER_SIZE)
			buffer = ft_bzero(buffer, i);
		storage = ft_strjoin(storage, buffer);
		if (!storage)
			return (NULL);
		if ((storage && ft_isnewline(storage)) || (storage[1] == '\0'))
			break ;
	}
	buffer = ft_memmove(buffer, storage);
	return (storage);
}

char	*ft_setline(char *line)
{
	int		i;
	char	*str;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (free(line), NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		str[i] = line[i];
		i++;
	}
	if ((line[i] && line[i] == '\n'))
	{
		str[i] = '\n';
		i++;
	}
	str[i] = '\0';
	free(line);
	return (str);
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

#include <fcntl.h>
#include <stdio.h>


int main(void)
{
	int	fd = open("txt", O_RDONLY);
	char	*buffer;
	char	*buffer2;
	int fd2;

	buffer = get_next_line(fd);
	printf("%d", fd);
	printf("\n%s", buffer);
	free(buffer);
	fd2 = open("txt2", O_RDONLY);
	buffer2 = get_next_line(fd2);
	printf("%s", buffer2);
	printf("%d", fd2);
	free(buffer2);
	close (fd);
	close(fd2);
	return(0);
}