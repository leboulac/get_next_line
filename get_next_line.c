/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordan <jordan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 11:50:18 by jordan            #+#    #+#             */
/*   Updated: 2026/10/29 13:58:48 by jordan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include "get_next_line.h"

static char	*gnl_free(char *keep, char *buffer)
{
	free(keep);
	free(buffer);
	return (NULL);
}

static char	*gnl_read(int fd, char *keep)
{
	char	*buffer;
	char	*tmp;
	ssize_t	bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (gnl_free(keep, NULL));
	while (ft_found_n(keep) == -1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (gnl_free(keep, buffer));
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		tmp = ft_join(keep, buffer);
		if (tmp == NULL)
			return (gnl_free(keep, buffer));
		free(keep);
		keep = tmp;
	}
	free(buffer);
	return (keep);
}

static char	*gnl_rest(char *keep)
{
	char	*rest;
	int		i;

	i = ft_found_n(keep);
	if (i == -1)
	{
		free(keep);
		return (NULL);
	}
	if (keep[i + 1] == '\0')
	{
		free(keep);
		return (NULL);
	}
	rest = extract_rest(keep, i);
	free(keep);
	return (rest);
}

static char	*gnl_prepare(int fd, char *keep)
{
	if (keep == NULL)
	{
		keep = malloc(1);
		if (keep == NULL)
			return (NULL);
		keep[0] = '\0';
	}
	keep = gnl_read(fd, keep);
	if (keep == NULL)
		return (NULL);
	if (keep[0] == '\0')
	{
		free(keep);
		return (NULL);
	}
	return (keep);
}

char	*get_next_line(int fd)
{
	static char	*keep;
	char		*line;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	keep = gnl_prepare(fd, keep);
	if (keep == NULL)
		return (NULL);
	line = extract_line(keep);
	if (line == NULL)
		return (keep = gnl_free(keep, NULL));
	i = ft_found_n(keep);
	if (i == -1 || keep[i + 1] == '\0')
	{
		keep = gnl_free(keep, NULL);
		return (line);
	}
	keep = gnl_rest(keep);
	if (keep == NULL)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
