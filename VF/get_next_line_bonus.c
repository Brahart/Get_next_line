/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:26:29 by asinsard          #+#    #+#             */
/*   Updated: 2024/12/04 19:20:46 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_bzero(char *str, int i)
{
	while (str[i])
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

char	*ft_readline(char *buffer, int fd)
{
	char	*storage;
	int		i;

	i = 1;
	storage = ft_strdup("");
	while (!ft_isnewline(storage) && i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if ((buffer[0] == '\0' && i == 0) || (i == -1))
			return (ft_bzero(buffer, 0), free(storage), NULL);
		buffer[i] = '\0';
		storage = ft_strjoin(storage, buffer);
		if ((storage && ft_isnewline(storage)) || (storage[1] == '\0' && i > 1))
			break ;
	}
	buffer = ft_memmove(buffer, storage);
	return (storage);
}

char	*ft_readline2(char *buffer, int fd)
{
	char	*storage;
	int		i;

	i = 1;
	storage = ft_strdup(buffer);
	while (!ft_isnewline(storage) && i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if ((buffer[0] == '\0' && i == 0) || (i == -1))
			return (ft_bzero(buffer, 0), free(storage), NULL);
		if (i < BUFFER_SIZE)
			buffer = ft_bzero(buffer, i);
		storage = ft_strjoin(storage, buffer);
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
		return (NULL);
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
	static char	buffer[FD_MAX][BUFFER_SIZE + 1] = {0};
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd][0])
		line = ft_readline(buffer[fd], fd);
	else
		line = ft_readline2(buffer[fd], fd);
	if (!line || line[0] == '\0')
		return (free(line), NULL);
	line = ft_setline(line);
	return (line);
}

/* int	main(void)
{
	int		fd;
	char	*line;

	
	fd = open("txt.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	// line = get_next_line(fd);
	// printf("%s", line);
	// free(line);
	close(fd);
	return (0);
} */