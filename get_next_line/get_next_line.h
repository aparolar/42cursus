/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:02:54 by aparolar          #+#    #+#             */
/*   Updated: 2021/05/05 17:09:40 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int		get_next_line(int fd, char **line);
char	*ft_bzero(const char *s, size_t n);
char	*ft_memcpy(char *s1, const char *s2, size_t n);
char	*ft_strcat(const char *s1, const char *s2);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t count, size_t size);

#endif