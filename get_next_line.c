/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahamdan <hahamdan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:18:20 by hahamdan          #+#    #+#             */
/*   Updated: 2024/06/21 15:06:10 by hahamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_append(char *buffer, char *stash)
{
    char *temp;

    temp = strjoin(buffer, stash);
    free(buffer);
    return (temp);
}

char *ft_line(char *buffer)
{
    char *line;
    
    int i = 0;
    while(buffer[i] && buffer[i] != '\n')
        i++;
    
    line = calloc(i + 2, sizeof(char));

    i = 0;
    while (buffer[i] && buffer[i] != '\n')
    {
        line[i] = buffer[i];
        i++;
    }
    if (buffer[i] == '\n')
    {
        line[i++] = '\n';
    }
    return (line);
}
char    *left_line(char *buffer)  // the same buffer
{
    char *left;
    int i = 0; 
    int j = 0;

    while(buffer[i] && buffer[i] != '\n')
        i++;
    
    left = calloc(strlen(buffer) - i + 1, sizeof(char));
    i++; // skipping '\n'
    while(buffer[i])
    {
        left[j] = buffer[i];
        j++;
        i++;
    }
    free(buffer);
    return (left);
}
char    *read_file(int fd, char *file_content)
{
    char *buffer;
    int bytesRead;

    
    buffer = calloc(BUFFER_SIZE + 1, sizeof(char));
    if (!buffer)
    return (NULL);

    while (bytesRead = (fd, buffer, BUFFER_SIZE))
    {
        // if (bytesRead == -1)
        // {
        //     free(buffer);
        //     return (NULL);
        // }
        buffer[bytesRead] = '\0';
        file_content = ft_append(buffer, file_content);
        if (ft_strchr(buffer, '\n'))
            break ;
    }
    free (buffer);
    return (file_content);
}




// char    *get_next_line(int fd);
// {
    
// }