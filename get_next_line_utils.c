/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:52:14 by hadufer           #+#    #+#             */
/*   Updated: 2021/10/22 15:12:58 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t memb)
{
	void	*ret;
	size_t	i;

	i = 0;
	ret = malloc(sizeof(memb) * nmemb);
	if (!ret)
		return (NULL);
	while (i < (memb * nmemb))
	{
		*(unsigned char *)(ret + i) = (unsigned char)0;
		i++;
	}
	return (ret);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s) + 1;
	while (i < len)
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	size_t	i;

	ret = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (s1 && *s1)
	{
		ret[i] = *s1;
		i++;
		s1++;
	}
	while (s2 && *s2)
	{
		ret[i] = *s2;
		i++;
		s2++;
	}
	ret[i] = 0;
	return (ret);
}

char	*ft_strndup(char	*str, size_t n)
{
	size_t	i;
	char	*ret;

	i = 0;
	if (!str || n == 0)
		return (NULL);
	ret = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (!ret)
		return (NULL);
	while (str[i] && i < n)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}
