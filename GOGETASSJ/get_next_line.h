/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrahamsinsard <abrahamsinsard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:43:50 by asinsard          #+#    #+#             */
/*   Updated: 2024/12/03 00:21:58 by abrahamsins      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 50
#endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_clean(char *storage, char *line);
char	*ft_setline(char *storage);
char	*ft_readline(char *storage, int fd);
int		ft_strlen(char *str);
char	*ft_isnewline(char *s);
char	*ft_move(char *dest, char *src, int len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_joinfree(char *storage, char *buffer);
int		ft_numnewline(char *str);

#endif
