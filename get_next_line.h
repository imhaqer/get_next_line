/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahamdan <hahamdan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:15:31 by hahamdan          #+#    #+#             */
/*   Updated: 2024/06/21 15:44:45 by hahamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#define BUFFER_SIZE 42

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <strings.h>


char    *get_next_line(int fd);
char    *read_file(int fd, char *file_content);
char    *ft_append(char *buffer, char *stash);
char    *ft_line(char *buffer);
char    *left_line(char *buffer);


#endif