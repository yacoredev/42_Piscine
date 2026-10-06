/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 19:06:14 by yabaadi           #+#    #+#             */
/*   Updated: 2026/08/02 19:06:16 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*read_file(char *filename)
{
	int		fd;
	char	*buf;
	int		bytes;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	buf = malloc(MAX_FILE);
	if (!buf)
	{
		close(fd);
		return (NULL);
	}
	bytes = read(fd, buf, MAX_FILE - 1);
	close(fd);
	if (bytes == -1)
	{
		free(buf);
		return (NULL);
	}
	buf[bytes] = '\0';
	return (buf);
}
