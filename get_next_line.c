/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: yasamankarimi <yasamankarimi@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/08 15:26:50 by yasamankari   #+#    #+#                 */
/*   Updated: 2024/01/14 15:36:39 by yasamankari   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*remove_returned_line(char *remaining_buffer)
{
	char	*updated_buffer;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (remaining_buffer[i] && remaining_buffer[i] != '\n')
		i++;
	if (!remaining_buffer[i])
	{
		free(remaining_buffer);
		return (NULL);
	}
	updated_buffer = (char *)malloc(sizeof(char) * \
							(ft_strlen(remaining_buffer) - i + 1));
	if (updated_buffer == NULL)
		return (NULL);
	i++;
	while (remaining_buffer[i])
		updated_buffer[j++] = remaining_buffer[i++];
	updated_buffer[j] = '\0';
	free(remaining_buffer);
	return (updated_buffer);
}

char	*get_line_from_buffer(char *remaining_buffer)
{
	char	*extracted_line;
	int		i;

	i = 0;
	if (!remaining_buffer[i])
		return (NULL);
	while (remaining_buffer[i] && remaining_buffer[i] != '\n')
		i++;
	extracted_line = (char *)malloc(sizeof(char) * (i + 2));
	if (extracted_line == NULL)
		return (NULL);
	i = 0;
	while (remaining_buffer[i] && remaining_buffer[i] != '\n')
	{
		extracted_line[i] = remaining_buffer[i];
		i++;
	}
	if (remaining_buffer[i] == '\n')
	{
		extracted_line[i] = remaining_buffer[i];
		i++;
	}
	extracted_line[i] = '\0';
	return (extracted_line);
}

char	*read_from_fd(int fd, char *read_chunk)
{
	char	*read_buffer;
	int		bytes_read;

	read_buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (read_buffer == NULL)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(read_chunk, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(read_buffer);
			return (NULL);
		}
		read_buffer[bytes_read] = '\0';
		read_chunk = ft_strjoin(read_chunk, read_buffer);
	}
	free(read_buffer);
	return (read_chunk);
}

char	*get_next_line(int fd)
{
	static char	*pending_data;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	pending_data = read_from_fd(fd, pending_data);
	if (pending_data == NULL)
		return (NULL);
	next_line = get_line_from_buffer(pending_data);
	pending_data = remove_returned_line(pending_data);
	return (next_line);
}
