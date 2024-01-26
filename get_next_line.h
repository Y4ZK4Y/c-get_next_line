/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: yasamankarimi <yasamankarimi@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/08 15:26:54 by yasamankari   #+#    #+#                 */
/*   Updated: 2024/01/26 13:58:28 by ykarimi       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*read_from_fd(int fd, char *read_chunk);
char	*get_line_from_buffer(char *remaining_buffer);
char	*remove_returned_line(char *remaining_buffer, int *flag);
size_t	ft_strlen(const char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*allocate_memory(int i);
void	copy_characters(char *remaining_buffer, char *extracted_line);

#endif