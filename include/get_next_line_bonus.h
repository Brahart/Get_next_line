/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:43:50 by asinsard          #+#    #+#             */
/*   Updated: 2024/12/11 19:25:17 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_setline(char *line);
char	*ft_read_buf_is_full(char *buffer, int fd);
char	*ft_read_buf_is_empty(char *buffer, int fd);
char	*ft_bzero(char *str, int i);
void	ft_memmove(char *buffer, char *storage);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *line);
char	*ft_isnewline(char *s);
int		ft_strlen(char *str);

#endif
