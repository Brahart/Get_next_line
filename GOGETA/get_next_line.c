/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrahamsinsard <abrahamsinsard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:26:29 by asinsard          #+#    #+#             */
/*   Updated: 2024/12/02 23:56:17 by abrahamsins      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_readline(char *storage, int fd)
{
	int		i;
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	i = 1;
	while (i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1 || i == 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i] = 0;
		storage = ft_strjoin(storage, buffer);
		if (buffer && ft_isnewline(storage))
			break ;
	}
	free (buffer);
	return (storage);
}

char	*ft_setline(char *line)
{
	int		i;
	char	*str;

	if (!line)
		return (NULL);
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
	return (str);
}

char	*ft_clean(char *storage)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	tmp = malloc(sizeof(char) * ((ft_strlen(storage) - i) + 1));
	if (!tmp)
		return (NULL);
	while (storage[i])
	{
		i++;
		tmp[j] = storage[i];
		j++;
	}
	tmp[j] = '\0';
	free (storage);
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*storage;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = ft_readline(storage, fd);
	if (!storage || storage[0] == '\0')
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