/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordan <jordan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 11:50:18 by jordan            #+#    #+#             */
/*   Updated: 2026/10/27 18:38:50 by jordan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Libere buffer et keep, puis remet keep a NULL. */
static char	*gnl_cleanup(char **keep, char *buffer)
{
	free(buffer);
	free(*keep);
	*keep = NULL;
	return (NULL);
}

/* Lit jusqu'au '\n' ou EOF et ajoute les donnees lues a keep. */
static int	gnl_read(int fd, char **keep, char *buffer)
{
	ssize_t	bytes_read;
	char	*tmp;

	while (ft_found_n(*keep) == -1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (-1);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		tmp = ft_join(*keep, buffer);
		if (tmp == NULL)
			return (-1);
		free(*keep);
		*keep = tmp;
	}
	return (0);
}

/* Extrait la ligne et conserve le reste dans keep si necessaire. */
static char	*gnl_extract(char **keep)
{
	char	*line;
	char	*tmp;

	if ((*keep)[0] == '\0')
		return (gnl_cleanup(keep, NULL));
	line = extract_line(*keep);
	if (line == NULL)
		return (gnl_cleanup(keep, NULL));
	if (ft_found_n(*keep) == -1
		|| (*keep)[ft_found_n(*keep) + 1] == '\0')
	{
		gnl_cleanup(keep, NULL);
		return (line);
	}
	tmp = extract_rest(*keep, ft_found_n(*keep));
	if (tmp == NULL)
	{
		free(line);
		return (gnl_cleanup(keep, NULL));
	}
	free(*keep);
	*keep = tmp;
	return (line);
}

/* Lit et retourne la prochaine ligne, ou NULL si necessaire. */
char	*get_next_line(int fd)
{
	static char	*keep;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	if (keep == NULL)
	{
		keep = malloc(1);
		if (keep == NULL)
			return (gnl_cleanup(&keep, buffer));
		keep[0] = '\0';
	}
	if (gnl_read(fd, &keep, buffer) == -1)
		return (gnl_cleanup(&keep, buffer));
	free(buffer);
	return (gnl_extract(&keep));
}
