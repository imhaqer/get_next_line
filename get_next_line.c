/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahamdan <hahamdan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:18:20 by hahamdan          #+#    #+#             */
/*   Updated: 2024/06/24 16:05:25 by hahamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_append(char *file_content, char *buffer)
{
	char	*temp;
	temp = ft_strjoin(file_content, buffer);
	free(file_content);
	return (temp);
}

char	*remaining_buffer(char *buffer)
{
	char	*line;
	int	    i;
	int	    j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
    if (!buffer[i])
	{
		//free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
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
	int	    i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
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
	char	*buffer;
	int     byteRead;

	if (!file_content)
		file_content = ft_calloc(1, sizeof(char));
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byteRead = 1;
	while (byteRead > 0)
	{
		byteRead = read(fd, buffer, BUFFER_SIZE);
		if (byteRead == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byteRead] = '\0';
		file_content = ft_append(file_content, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (file_content);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_line(fd, buffer);
    if (!buffer)
        return (NULL);
	line = ft_line(buffer);
	buffer = remaining_buffer(buffer);
	return (line);
}

