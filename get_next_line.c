/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ykarimi <ykarimi@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/14 13:27:37 by ykarimi       #+#    #+#                 */
/*   Updated: 2023/12/18 14:58:19 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_lines(char *str, char **remaining_buffer)
{
	char	*line;
	char	*nl_position;

	nl_position = ft_strchr(str, '\n');
	if (nl_position)
	{
		*nl_position = '\0';
		*remaining_buffer = ft_strdup(nl_position + 1);
		line = ft_strdup(str);
	}
	else
	{
		*remaining_buffer = NULL;
		line = ft_strdup(str);
	}
	free(str);
	return (line);
}

int	read_from_fd(int fd, char **buffer)
{
	int		bytes_down;
	char	thing[BUFFER_SIZE + 1];

	bytes_down = read(fd, thing, BUFFER_SIZE);
	if (bytes_down == -1)
	{
		return (-1);
	}
	thing[bytes_down] = '\0';
	*buffer = ft_strjoin(*buffer, thing);
	return (bytes_down);
}

// char	*get_next_line(int fd)
// {
// 	static char	*remaining_buffer;
// 	char		*buffer;
// 	int			bytes;

// 	//remaining_buffer = NULL;
// 	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	while (1)
// 	{
// 		if (remaining_buffer)
// 		{
// 			buffer = ft_strjoin(buffer, remaining_buffer);
// 			free(remaining_buffer);
// 			remaining_buffer = NULL;
// 		}
// 		bytes = read_from_fd(fd, &buffer);
// 		if (bytes == -1 || bytes == 0)
// 		{
// 			free(buffer);
// 			if (bytes == -1)
// 				return (NULL);
// 			return (NULL);
// 	}
// 	if (ft_strchr(buffer, '\n'))
// 		return (extract_lines(buffer, &remaining_buffer));
// 	}
// }


