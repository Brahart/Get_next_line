/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 20:32:10 by asinsard          #+#    #+#             */
/*   Updated: 2024/12/11 20:45:03 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// #include "include/get_next_line.h"
#include "include/get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*line;
	int		fd;
	int		i;

	i = 1;
	fd = open("src/get_next_line.c", O_RDONLY);
	line = get_next_line(fd);
	printf("\e[4;31mline %i:\e[0m\e[1;34m %s", i, line);
	i++;
	free(line);
	while(line)
	{
		line = get_next_line(fd);
		printf("\e[4;31mline %i:\e[0m\e[1;34m %s", i, line);
		free(line);
		i++;
	}
	free(line);
	close(fd);
	return(0);
}