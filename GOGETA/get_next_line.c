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

char	*ft_readline(char *buffer, int fd, int i)
{
	int		j;
	char	*storage;

	storage = ft_strdup("");
	j = 0;
	while (buffer[j] != '\n')
	{
		j = 0;
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(storage);
			return (NULL);
		}
		while (j < i)
		{
			if (!is_newline(buffer[j]))
				j++;
			else
				break ;
		}
		storage = ft_strjoin(storage, buffer);
	}
	return (storage);
}

char	*ft_setline(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
		i++;
	line[i + 1] = 0;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*storage;
	int			i;

	i = 0;
	storage = ft_readline(buffer, fd, i);
	line = storage;
	line = ft_setline(line);
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