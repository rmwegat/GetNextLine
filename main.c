/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:27:22 by rwegat            #+#    #+#             */
/*   Updated: 2023/12/06 15:24:36 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdarg.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("/Users/rwegat/repository/Projects/GetNextLine/test_file.text", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	line = get_next_line(fd);
	printf("Line: %s\n", line);
	free(line);
	close(fd);
	return (0);
}
