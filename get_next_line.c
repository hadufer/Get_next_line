/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:52:10 by hadufer           #+#    #+#             */
/*   Updated: 2021/10/22 15:14:04 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

static int	check_fd_malloc(char **tmp, char **tmp2, int *status, int *fd)
{
	*tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	*tmp2 = NULL;
	if (!*tmp)
		return (0);
	*status = read(*fd, *tmp, BUFFER_SIZE);
	if (*status == -1)
	{
		free(*tmp);
		return (0);
	}
	return (-1);
}

static int	status_handler(char **tmp, char **tmp2, char **buf, int *status)
{
	if (*status != 0)
	{
		*tmp2 = *buf;
		*buf = ft_strjoin(*buf, *tmp);
		free(*tmp2);
		free(*tmp);
		*tmp = NULL;
	}
	if (*status == 0 && !ft_strchr(*buf, '\n'))
	{
		free(*tmp);
		*tmp = ft_strndup(*buf, ft_strlen(*buf));
		free(*buf);
		*buf = NULL;
		return (0);
	}
	return (-1);
}

static char	*general_handler(char **tmp, char **tmp2, char **buf, int *status)
{
	(void)status;
	free(*tmp);
	*tmp = ft_strndup(*buf,
			(ft_strlen(*buf) - ft_strlen(ft_strchr(*buf, '\n') + 1)));
	*tmp2 = *buf;
	*buf = ft_strndup(ft_strchr(*buf, '\n') + 1,
			ft_strlen(ft_strchr(*buf, '\n') + 1));
	free(*tmp2);
	return (*tmp);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*tmp;
	char		*tmp2;
	int			status;

	if (!check_fd_malloc(&tmp, &tmp2, &status, &fd))
		return (NULL);
	while (!ft_strchr(tmp, '\n') && status > 0)
	{
		if (buf)
		{
			tmp2 = buf;
			buf = ft_strjoin(tmp2, tmp);
			free(tmp2);
		}
		else
			buf = ft_strjoin(tmp2, tmp);
		status = read(fd, tmp, BUFFER_SIZE);
		tmp[status] = 0;
	}
	if (!status_handler(&tmp, &tmp2, &buf, &status))
		return (tmp);
	return (general_handler(&tmp, &tmp2, &buf, &status));
}
