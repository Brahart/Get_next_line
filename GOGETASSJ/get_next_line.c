/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrahamsinsard <abrahamsinsard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:46:39 by asinsard          #+#    #+#             */
/*   Updated: 2024/12/03 00:24:13 by abrahamsins      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_readline(char *storage, int fd)
{
	int		i;
	char	*buffer;

	i = 1;
	while (ft_isnewline(storage) && i != 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		i = read(fd, buffer, BUFFER_SIZE);
		if ((!storage && i == 0) || i == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i] = 0;
		storage = ft_strjoin(storage, buffer);
	}
	return (storage);
}

char	*ft_setline(char *storage)
{
	int		i;
	char	*str;

	if (!storage)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = -1;
	while (storage[++i] && storage[i] != '\n')
	{
		str[i] = storage[i];
	}
	if (storage[i] == '\n')
	{
		str[i] = '\n';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_clean(char *storage, char *line)
{
	char	*tmp;
	int		i;
	int		j;

	i = ft_strlen(line);
	j = 0;
	if (!storage[i])
	{
		free(storage);
		return (NULL);
	}
	while (storage[i++])
		j++;
	tmp = malloc(sizeof(char) * (j + 1));
	if (!tmp)
		return (NULL);
	i = ft_strlen(line);
	j = 0;
	while (storage[i])
		tmp[j++] = storage[i++];
	tmp[j] = '\0';
	free (storage);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = ft_readline(storage, fd);
	if (!tmp)
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	storage = tmp;
	line = ft_setline(storage);
	storage = ft_clean(storage, line);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;
// 	char	*line2;
// 	char	*line3;
// 	// char	*line4;
// 	// char	*line5;
// 	// char	*line6;
// 	fd = open("txt.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	line2 = get_next_line(fd);
// 	line3 = get_next_line(fd);
// 	// line4 = get_next_line(fd);
// 	// line5 = get_next_line(fd);
// 	// line6 = get_next_line(fd);
// 	close(fd);
// 	printf("%s%s%s", line, line2, line3);
// 	free(line);
// 	free(line2);
// 	free(line3);
// 	return (0);
// }
