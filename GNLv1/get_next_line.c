/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:43:04 by asinsard          #+#    #+#             */
/*   Updated: 2024/11/28 16:43:38 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *storage, char *buffer)
{
	ssize_t		i;
	char		*tmp;

	i = 1;
	while (i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(storage);
			return (NULL);
		}
		if (i == 0)
			break ;
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

char	*ft_set_line(char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == 0)
		return (NULL);
	tmp = ft_substr(str, i + 1, (size_t)ft_strlen(str) - i);
	if (!tmp)
		return (NULL);
	str[i + 1] = '\0';
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*storage;

	buffer = malloc(BUFFER_SIZE * sizeof (char) + 1);
	if (!buffer)
		return (NULL);
	line = ft_read_line(fd, storage, buffer);
	storage = ft_set_line(line);
	return (line);
}

/* int	main(void)
{
	int		fd;
	char	*line;
	char	*line2;
	char	*line3;
	char	*line4;
	char	*line5;
	char	*line6;
	char	*line7;
	char	*line8;
	char	*line9;
	char	*line10;
	char	*line11;
	
	fd = open("txt.txt", O_RDONLY);
	line = get_next_line(fd);
	line2 = get_next_line(fd);
	line3 = get_next_line(fd);
	line4 = get_next_line(fd);
	line5 = get_next_line(fd);
	line6 = get_next_line(fd);
	line7 = get_next_line(fd);
	line8 = get_next_line(fd);
	line9 = get_next_line(fd);
	line10 = get_next_line(fd);
	line11 = get_next_line(fd);
	close(fd);
	printf("%s%s%s%s%s%s%s%s%s%s%s", line, line2, line3, line4, line5, line6, line7, line8, line9, line10, line11);
	return (0);
} */