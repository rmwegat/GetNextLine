/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:27:22 by rwegat            #+#    #+#             */
/*   Updated: 2023/12/04 16:39:23 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdarg.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("/Users/rwegat/repository/GetNextLine/test_file.text", O_RDONLY);
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
