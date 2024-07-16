/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahamdan <hahamdan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:18:20 by hahamdan          #+#    #+#             */
/*   Updated: 2024/07/16 18:57:06 by hahamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free(char **str)
{
	if (*str)
		free(*str);
	*str = NULL;
	return (NULL);
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

static int	read_line(int fd, char **file_content, char **buffer)
{
	char	*temp;
	int		bytes_read;

	bytes_read = 1;
	while (!ft_strchr(*file_content, '\n') && (bytes_read > 0))
	{
		bytes_read = read(fd, *buffer, BUFFER_SIZE)
		if (buffer == -1)
				return (-1);
		(*buffer)[bytes_read] = '\0';
		temp = ft_strjoin(*file_content, *buffer);
		if (!temp)
			return (-1);
		ft_free(file_content);
		*stash = temp;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 )		
	{
		if (buffer)
		{
			free (buffer);
			buffer = NULL;	
		}
		return (NULL);
	}
	
	buffer = read_line(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	if (!line)
	{	
		free(buffer);
		buffer = NULL;	
		return NULL;
	}
	buffer = remaining_buffer(buffer);
	return (line);
}

