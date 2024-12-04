/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:30:54 by asinsard          #+#    #+#             */
/*   Updated: 2024/12/03 19:11:02 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
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
	return (str);
}

char	*ft_memmove(char *buffer, char *storage)
{
	char	*tmp1;
	char	*tmp2;
	int		i;
	int		j;

	tmp1 = storage;
	tmp2 = buffer;
	i = 0;
	j = 0;
	while (tmp1[i] && tmp1[i] != '\n')
		i++;
	i += 1;
	while (tmp1[i])
	{
		tmp2[j] = tmp1[i];
		j++;
		i++;
	}
	while (j <= BUFFER_SIZE + 1)
	{
		tmp2[j] = '\0';
		j++;
	}
	return (buffer);
}