/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordan <jordan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 09:55:33 by jordan            #+#    #+#             */
/*   Updated: 2026/10/25 11:19:10 by jordan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*extract_rest(char *keep, int i);
char	*extract_line(char *keep);
int		ft_lenstr(char *s);
char	*ft_join(char *keep, char *buffer);
int		ft_found_n(char *s);

#endif
