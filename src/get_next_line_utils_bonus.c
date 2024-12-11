/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:30:54 by asinsard          #+#    #+#             */
/*   Updated: 2024/12/11 20:20:26 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

char	*ft_isnewline(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (&s[i]);
		else
			i++;
	}
	return (NULL);
}

char	*ft_strdup(char *line)
{
	char	*res;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(line);
	res = malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = line[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (free(s1), NULL);
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	free(s1);
	return (res);
}

void	ft_memmove(char *buffer, char *storage)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
		i += 1;
	while (storage[i])
	{
		buffer[j] = storage[i];
		j++;
		i++;
	}
	ft_bzero(buffer, j);
}