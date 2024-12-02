/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:46:39 by asinsard          #+#    #+#             */
/*   Updated: 2024/12/02 20:38:25 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_readline(int fd, char *storage)
{
	int		i;
	char	buffer[BUFFER_SIZE + 1];

	i = read(fd, buffer, BUFFER_SIZE);
	if (i == -1)
		return (NULL);
	while (ft_numnewline(buffer))
	{
		storage = ft_strjoin(storage, buffer);
	}
	storage = ft_strjoin(storage, buffer);
	return (storage);
}

char	*ft_setline(char *line)
{
	int		i;

	i = ft_numnewline(line);
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	line[i + 1] = '\0';
	return (line);
}

char	*ft_clean(char *storage)
{
	char	*tmp;
	int		i;

	i = ft_numnewline(storage);
	tmp = ft_move(storage, &storage[i], BUFFER_SIZE - i);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	storage[BUFFER_SIZE + 1];
	char 		*line;
	
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	line = ft_readline(fd, storage);
	line = ft_setline(line);
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
