/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:52:10 by hadufer           #+#    #+#             */
/*   Updated: 2021/10/22 14:23:17 by hadufer          ###   ########.fr       */
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

	// FIRST READ TO TEST FD
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
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
	if (status != 0)
	{
		tmp2 = buf;
		buf = ft_strjoin(buf, tmp);
		free(tmp2);
		free(tmp);
		tmp = NULL;
	}
	if (status == 0 && !ft_strchr(buf, '\n'))
	{
		free(tmp);
		tmp = ft_strndup(buf, ft_strlen(buf));
		free(buf);
		buf = NULL;
		return (tmp);
	}
	free(tmp);
	tmp = ft_strndup(buf, (ft_strlen(buf) - ft_strlen(ft_strchr(buf, '\n') + 1)));
	tmp2 = buf;
	buf = ft_strndup(ft_strchr(buf, '\n') + 1, ft_strlen(ft_strchr(buf, '\n') + 1));
	free(tmp2);
	return (tmp);
}
