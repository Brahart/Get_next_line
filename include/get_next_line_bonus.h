/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:43:50 by asinsard          #+#    #+#             */
/*   Updated: 2025/03/25 23:59:03 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# define BUFFER_SIZE 100
# define FD_MAX 1024

char	*ft_bzero(char *str, int i);
void	ft_memmove(char *buffer, char *storage);
char	*ft_strjoin_and_free(char *s1, char *s2);
char	*ft_strdup(char *line);
char	*ft_isnewline(char *s);
int		ft_strlen(char *str);
char	*copy_and_backspace(char *line, char *str, int i);

#endif
