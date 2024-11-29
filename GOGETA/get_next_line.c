/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:26:29 by asinsard          #+#    #+#             */
/*   Updated: 2024/11/28 22:28:52 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_newline(char c)
{
	if (c == '\n')
		return (1);
	return (0);
}

// read the line until we found a \n
char	*ft_readline(char *storage, int fd)
{
	int		i;
	char	*buffer;
	if (!storage)
		storage = ft_strdup("");
	//maybe malloc buffer
	i = 1;
	while (i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(storage);
			free(buffer);
			return (NULL);
		}
		buffer[i] = 0;
		storage = ft_strjoin(storage, buffer);
		if (ft_strchr(storage, '\n'));
			break;
	}
	free (buffer)
	return (storage);
}

char	*ft_setline(char *line)
{
	int	i;
	char	*str;

	i = 0;
	while (line[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	while (line[i] && line[i] != '\n')
	{
		str[i] == line[i];
		i++;
	}
	if ((line[i] && line[i] == '\n')
		str[i + 1] == '\n';
	str[i + 2] = 0;
	return (str);
}

// make a function that clear storage before the \n
// set a tmp malloc it and copy the char after the \n and end the tmp by a \0
// return tmp

char	*get_next_line(int fd)
{
	char		*line;
	static char	*storage;

	line = ft_readline(storage, fd);
	if (!storage)
		return (NULL);
	line = ft_setline(storage);
	storage = ft_clean(storage);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;
	char	*line2;
	char	*line3;
	/* char	*line4;
	char	*line5;
	char	*line6; */
	
	fd = open("txt.txt", O_RDONLY);
	line = get_next_line(fd);
	line2 = get_next_line(fd);
	line3 = get_next_line(fd);
/* 	line4 = get_next_line(fd);
	line5 = get_next_line(fd);
	line6 = get_next_line(fd); */
	close(fd);
	printf("%s%s%s", line, line2, line3);
	free(line);
	free(line2);
	free(line3);
	return (0);
}
