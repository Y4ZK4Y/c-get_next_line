/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/14 13:29:03 by ykarimi       #+#    #+#                 */
/*   Updated: 2023/12/18 14:25:36 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		fd;
	int i = 10;

	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening the file.");
		return (1);
	}
	line = get_next_line(fd);
	while (i-- > 0 && line != NULL)
	{
		printf("%s\n", line);
		//free(line);
	}
	close(fd);
	return (0);
}
