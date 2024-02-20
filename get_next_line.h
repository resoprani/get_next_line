/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbrito-s <rbrito-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:15:03 by rbrito-s          #+#    #+#             */
/*   Updated: 2024/02/17 23:49:24 by rbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

char	*get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strchr(const char *str, int letter);
char	*increase_buffer(char *buffer, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *str);
char	*extract_string(char *buffer);
char	*obtain_remaning_string(char *buffer);

#endif