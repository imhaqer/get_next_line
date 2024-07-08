/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahamdan <hahamdan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:18:20 by hahamdan          #+#    #+#             */
/*   Updated: 2024/07/06 20:09:15 by hahamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_append(char *file_content, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(file_content, buffer);
	// if (!temp)
	// 	return NULL;
	free(file_content);
	return (temp);
}

char	*remaining_buffer(char *buffer)
{
	char	*line;
	int	i;
	int	j;

	i = 0;
	// if (!buffer)
	// 	return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
    if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	// if (!line)
	// {
	// 	free (buffer);
	// 	return (NULL);
	// }
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int	i;

	i = 0;
	if (!buffer[i] || !buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*read_line(int fd, char *file_content)
{
	int		byte_read;
	char	*buffer;

	if (!file_content)
		file_content = ft_calloc(1, sizeof(char));
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_read] = '\0';
		file_content = ft_append(file_content, buffer);
		if (strchr(buffer, '\n'))
			break;
	}
	free(buffer);
	return (file_content);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		{
			free (buffer);
			buffer = NULL;
			return (NULL);
		}
	buffer = read_line(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = remaining_buffer(buffer);
	return (line);
}

