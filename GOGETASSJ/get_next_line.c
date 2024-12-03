/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:26:29 by asinsard          #+#    #+#             */
/*   Updated: 2024/12/03 21:39:11 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_joinfree(char *storage, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(storage, buffer);
	free(storage);
	return (tmp);
}

char	*ft_readline(char *buffer, int fd)
{
	char	*storage;
	int		i;
	
	if (!buffer[0])
		i = read(fd, buffer, BUFFER_SIZE);
	else
		i = 1;
	storage = ft_strdup("");
	while (i > 0)
	{
		if (buffer[0] == '\0' && i == 0)
			return (free(storage), NULL);
		if (buffer[0] && i > 0)
			buffer[i] = '\0';
		storage = ft_joinfree(storage, buffer);
		if ((storage && ft_isnewline(storage)) || (storage[1] == '\0' && i > 1))
		{
			buffer = ft_memmove(buffer, storage);
			break ;
		}
		i = read(fd, buffer, BUFFER_SIZE);
	}
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
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &buffer, 0) < 0)
		return (NULL);
	line = ft_readline(buffer, fd);
	if (!line || line[0] == '\0')
		return (free(line), NULL);
	line = ft_setline(line);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;
	char	*line2;
	char	*line3;
	// char	*line4;
	// char	*line5;
	// char	*line6;
	
	fd = open("txt.txt", O_RDONLY);
	line = get_next_line(fd);
	line2 = get_next_line(fd);
	line3 = get_next_line(fd);
	// line4 = get_next_line(fd);
	// line5 = get_next_line(fd);
	// line6 = get_next_line(fd);
	close(fd);
	printf("%s%s%s", line, line2, line3);
	free(line);
	free(line2);
	free(line3);
	return (0);
}