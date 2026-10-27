/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordan <jordan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 00:00:00 by ton_login         #+#    #+#             */
/*   Updated: 2026/10/25 11:49:39 by jordan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_rest(char *keep, int i)
{
	int		j;
	char	*rest;

	i++;
	j = i;
	if (keep[i] == '\0')
		return (NULL);
	while (keep[i] != '\0')
		i++;
	rest = malloc((i - j + 1) * sizeof(char));
	if (rest == NULL)
		return (NULL);
	i = 0;
	while (keep[j] != '\0')
	{
		rest[i] = keep[j];
		j++;
		i++;
	}
	rest[i] = '\0';
	return (rest);
}

char	*extract_line(char *keep)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (keep[i] != '\n' && keep[i] != '\0')
		i++;
	if (keep[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = keep[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

int	ft_lenstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_join(char *keep, char *buffer)
{
	int		i;
	int		j;
	int		result;
	char	*dest;

	i = 0;
	j = 0;
	result = ft_lenstr(keep) + ft_lenstr(buffer);
	dest = malloc((result + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (keep[i] != '\0')
	{
		dest[i] = keep[i];
		i++;
	}
	while (buffer[j] != '\0')
	{
		dest[i] = buffer[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_found_n(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (-1);
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] == '\0')
		return (-1);
	return (i);
}
