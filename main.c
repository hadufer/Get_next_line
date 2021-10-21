/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:52:05 by hadufer           #+#    #+#             */
/*   Updated: 2021/10/21 17:56:13 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

int	main()
{
	int	fd = 12;
	char	*test = NULL;

	fd = open("gnlTester/files/alternate_line_nl_no_nl", O_RDONLY);
	test = get_next_line(fd);
	while ( test )
	{
		write(1, test, ft_strlen(test));
		// write(1, "|\n", 2);
		test = get_next_line(fd);
	}
}
