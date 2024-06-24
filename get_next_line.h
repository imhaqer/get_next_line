/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahamdan <hahamdan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:15:31 by hahamdan          #+#    #+#             */
/*   Updated: 2024/06/21 16:34:14 by hahamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#define BUFFER_SIZE 4

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
// # include <string.h>
# include  <fcntl.h>


char    *get_next_line(int fd);
char	*ft_strchr(char const *str, int c);

char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *c);
void	ft_bzero(void *str, size_t len);
void	*ft_calloc(size_t count, size_t size);

#endif