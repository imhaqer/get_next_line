/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahamdan <hahamdan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:18:20 by hahamdan          #+#    #+#             */
/*   Updated: 2024/06/21 14:07:36 by hahamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *read_file(int fd, char *file_content) // static_var
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
        file_content = ft_free(file_content, buffer);
        if (ft_strchr(buffer, '\n'))
            break ;
    }
    free (buffer);
    return (file_content);
}




// char    *get_next_line(int fd);
// {
    
// }