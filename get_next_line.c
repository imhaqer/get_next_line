/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahamdan <hahamdan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:18:20 by hahamdan          #+#    #+#             */
/*   Updated: 2024/07/17 15:50:23 by hahamdan         ###   ########.fr       */
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

static char	*extract_line(char *stash)
{
	char	*line;
	int		i;

	if (!stash || stash[0] == '\0')
		return (NULL);
	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
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

static char	*remaining_stash(char *stash)
{
	char	*line;
	size_t	i;
	size_t	j;

	if (!stash)
		return (NULL);
	if (stash[0] == '\0')
		return (ft_free(&stash)); 

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = (char *)malloc((ft_strlen(stash) - i + 1) * sizeof(char));
	if (!line)
		return (ft_free(&stash));
	j = 0;
	while (stash[i] != '\0')
		line[j++] = stash[i++];
	line[i] = '\0';
	if (line[0] == '\0')
		ft_free(&line);
	ft_free(&stash);
	return (line);
}


static int	read_line(int fd, char **file_content, char **buffer)
{
	char	*temp;
	int		bytes_read;

	bytes_read = 1;
	while (!ft_strchr(*file_content, '\n') && (bytes_read != 0))
	{
		bytes_read = read(fd, *buffer, BUFFER_SIZE);
		if (bytes_read == -1)
				return (-1);
		(*buffer)[bytes_read] = '\0';
		temp = ft_strjoin(*file_content, *buffer);
		if (!temp)
			return (-1);
		ft_free(file_content);
		*file_content = temp;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*file_content;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (ft_free(&file_content));
	if (read_line(fd, &file_content, &buffer) == -1)
	{
		ft_free(&buffer);
		return (ft_free(&file_content));
	}
	ft_free(&buffer);
	line = extract_line(file_content);
	if (!line)
		return (ft_free(&file_content));
	file_content = remaining_stash(file_content);
	return (line);
}


