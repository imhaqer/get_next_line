/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahamdan <hahamdan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:35:42 by hahamdan          #+#    #+#             */
/*   Updated: 2024/07/19 16:25:13 by hahamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	char	symb;
	int		i;

	if (!s)
		return (NULL);
	symb = c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == symb)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == symb)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin(char *stash, char *buffer)
{
	char	*res;
	int		i;
	int		j;
	size_t	len;

	if (!stash && !buffer)
		return (NULL);
	len = ft_strlen(stash) + ft_strlen(buffer);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (stash && stash[i] != 0)
	{
		res[i] = stash[i];
		i++;
	}
	j = 0;
	while (buffer && buffer[j] != 0)
		res[i++] = buffer[j++];
	res[len] = '\0';
	return (res);
}

size_t	until_nl(char *stash)
{
	size_t	i;

	if (!stash)
		return (0);
	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	return (i);
}
