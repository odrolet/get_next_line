/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldrolet <oldrolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:33:05 by oldrolet          #+#    #+#             */
/*   Updated: 2023/03/21 17:10:13 by oldrolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

char	*ft_freestash(char *stash)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	i++;
	rest = ft_calloc(sizeof(char), (ft_strlen(stash) - i) + 1);
	j = 0;
	while (stash[i])
		rest[j++] = stash[i++];
	rest[j] = '\0';
	if (i == 0)
		ft_free(rest);
	stash = ft_free(stash);
	return (rest);
}

char	*ft_get_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!*stash)
		return (NULL);
	while (stash[i] != '\n' && stash[i])
		i++;
	line = ft_calloc(sizeof(char), i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_read(int fd, char *stash)
{
	char	*buffer;
	int		nbytes;

	nbytes = 420;
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(stash, '\n') && nbytes != 0)
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes == 0)
			break ;
		if (nbytes == -1)
			return (free(stash), free(buffer), NULL);
		buffer[nbytes] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	ft_free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char		*stash[OPEN_MAX];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	line = NULL;
	stash[fd] = ft_read(fd, stash[fd]);
	if (!stash[fd])
		return (stash[fd] = ft_free(stash[fd]));
	line = ft_get_line(stash[fd]);
	stash[fd] = ft_freestash(stash[fd]);
	if (!stash[fd])
		stash[fd] = ft_free(stash[fd]);
	return (line);
}
