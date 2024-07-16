/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahamdan <hahamdan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:18:20 by hahamdan          #+#    #+#             */
/*   Updated: 2024/07/16 19:49:42 by hahamdan         ###   ########.fr       */
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

char	*remaining_stash(char *buffer)
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

static char	*extract_line(char *stash)
{
	char	*line;
	int		i;

	if (!stash || stash[0] == '\0')
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{	
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
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

char	*get_next_line(int fd);
{
	static char	*file_content;
	char		*buffer;
	char		line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (ft_free(&file_content));
	if (read_line(fd, &file_content, &buffer) == -1)
	{
		ft_free(&buffer);
		return (ft_free(&file_content));
	}
	ft_free(&buffer);
	line = extract_line(stash);
	if (!line)
		return (ft_free(&stash));
	file_content = remaining_stash(stash);
	return (line);
}


