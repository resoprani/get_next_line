/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbrito-s <rbrito-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:14:38 by rbrito-s          #+#    #+#             */
/*   Updated: 2024/02/20 21:24:18 by rbrito-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*obtain_remaning_string(char *buffer)
{
	int		i;
	int		j;
	char	*str_return;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\0')
		return (free(buffer), NULL);
	str_return = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (!str_return)
		return (free(buffer), NULL);
	i++;
	j = 0;
	while (buffer[i] != '\0')
	{
		str_return[j] = buffer[i];
		i++;
		j++;
	}
	str_return[j] = '\0';
	free(buffer);
	return (str_return);
}

char	*extract_string(char *buffer)
{
	int		i;
	char	*str_return;

	i = 0;
	if (buffer[i] == '\0')
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	str_return = ft_calloc(i + 2, sizeof(char));
	if (!str_return)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		str_return[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		str_return[i++] = '\n';
	return (str_return);
}

char	*join_buffer(char *buffer, char *new_buffer)
{
	char	*str_return;

	str_return = ft_strjoin(buffer, new_buffer);
	free(buffer);
	return (str_return);
}

char	*increase_buffer(char *buffer, int fd)
{
	char	*new_buffer;
	int		bytes_already_read;

	new_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!new_buffer)
		return (NULL);
	bytes_already_read = 1;
	while (bytes_already_read > 0)
	{
		bytes_already_read = read(fd, new_buffer, BUFFER_SIZE);
		if (bytes_already_read < 0)
		{
			free(buffer);
			free(new_buffer);
			return (NULL);
		}
		new_buffer[bytes_already_read] = '\0';
		buffer = join_buffer(buffer, new_buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(new_buffer);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*str_return;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_calloc(1, sizeof(char));
	if (!ft_strchr(buffer, '\n'))
		buffer = increase_buffer(buffer, fd);
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	str_return = extract_string(buffer);
	buffer = obtain_remaning_string(buffer);
	return (str_return);
}
