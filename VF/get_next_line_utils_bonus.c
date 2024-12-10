/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:30:54 by asinsard          #+#    #+#             */
/*   Updated: 2024/12/05 15:23:40 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_strdup(char *s)
{
	char	*str;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	int		malloc_size;

	i = 0;
	j = 0;
	malloc_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(sizeof(char) * (malloc_size));
	if (!str)
		return (free(s1), NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_memmove(char *buffer, char *storage)
{
	char	*tmp_storage;
	char	*tmp_buffer;
	int		i;
	int		j;

	tmp_storage = storage;
	tmp_buffer = buffer;
	i = 0;
	j = 0;
	while (tmp_storage[i] && tmp_storage[i] != '\n')
		i++;
	if (tmp_storage[i] == '\n')
		i += 1;
	while (tmp_storage[i])
	{
		tmp_buffer[j] = tmp_storage[i];
		j++;
		i++;
	}
	while (j < BUFFER_SIZE + 1)
	{
		tmp_buffer[j] = '\0';
		j++;
	}
	return (tmp_buffer);
}
