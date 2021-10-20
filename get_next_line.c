/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:52:10 by hadufer           #+#    #+#             */
/*   Updated: 2021/10/20 18:46:17 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd)
{
	static char	*buf;
	char		*tmp;
	char		*tmp2;
	int			status;

	tmp = malloc(sizeof(char) * (BUFFER_SIZE));
	*tmp = 0;
	tmp2 = NULL;
	if (!tmp)
		return (NULL);
	status = read(fd, tmp, BUFFER_SIZE);
	if (status == -1)
	{
		free(tmp);
		return (NULL);
	}
	while (!ft_strchr(tmp, '\n') && status > 0)
	{
		if (*tmp == '\n')
			break ;
		if (buf)
		{
			tmp2 = buf;
			free(buf);
		}
		buf = ft_strjoin(tmp2, tmp);
		status = read(fd, tmp, BUFFER_SIZE);
	}
	tmp2 = buf;
	buf = ft_strjoin(buf, tmp);
	free(tmp2);
	tmp2 = buf;
	// A revoir
	buf = ft_strndup(ft_strchr(buf, '\n'), ft_strlen(buf) - ft_strlen(ft_strchr(buf, '\n')) / sizeof(char));
	tmp = ft_strndup(buf, ft_strlen(buf) + (ft_strlen(buf) - (buf - ft_strchr(buf, '\n')) / sizeof(char)));
	free(tmp2);
	return (tmp);
}
