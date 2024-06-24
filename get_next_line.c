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


char    *ft_append(char *buffer, char *stash)
{
    char *temp;

    temp = ft_strjoin(buffer, stash);
    free(buffer);
    return (temp);
}
char    *left_line(char *buffer)  // the same buffer
{
    char *left;
    int i = 0; 
    int j = 0;

    while(buffer[i] && buffer[i] != '\n')
        i++;
    
    if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
    
    left = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
    i++; // skipping '\n'
    while(buffer[i])
    {
        left[j++] = buffer[i++];
    }
    free(buffer);
    return (left);
}
char *ft_line(char *buffer)
{
    char *line;
    
    int i = 0;
    if (!buffer)
        return NULL;
    while(buffer[i] && buffer[i] != '\n')
        i++;
    
    line = ft_calloc(i + 2, sizeof(char));

    i = 0;
    while (buffer[i] && buffer[i] != '\n')
    {
        line[i] = buffer[i];
        i++;
    }
    if (buffer[i] && buffer[i] == '\n')
    {
        line[i++] = '\n';
    }
    return (line);
}

char    *read_file(int fd, char *file_content)
{
    char *buffer;
    int bytesRead;

    if (!file_content)
        file_content = ft_calloc(1,1);
    
    buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    bytesRead = 1;
    while (bytesRead > 0)
    {
        bytesRead = read(fd, buffer, BUFFER_SIZE);
        if (bytesRead == -1)
        {
            free(buffer);
            return (NULL);
        }
        buffer[bytesRead] = '\0';
        file_content = ft_append(file_content, buffer);
        if (ft_strchr(buffer, '\n'))
            break ;
    }
    free (buffer);
    return (file_content);
}




char    *get_next_line(int fd)
{
    char *line;
    static char *buffer; 

    if( fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return NULL;

    buffer = read_file(fd, buffer);

    if (!buffer)
        // free(buffer);
        return NULL;
    line = ft_line(buffer);
    buffer = left_line(buffer);

    return (line);
}

