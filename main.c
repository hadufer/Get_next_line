/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:52:05 by hadufer           #+#    #+#             */
/*   Updated: 2021/10/20 18:17:25 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

int	main()
{
	int	fd = 12;
	char	*tmp = NULL;

	fd = open("gnlTester/files/42_with_nl", O_RDONLY);
	tmp = get_next_line(fd);
	while ( tmp )
	{
		printf("%s|\n", tmp);
		tmp = get_next_line(fd);
	}
}
