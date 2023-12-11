//#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#ifndef BUFFER_SIZE 
#define BUFFER_SIZE 42
#endif


char	*append_next_line(char	*big_buffer, char	*added_lines)
{
	char	*buffer;

	buffer = strjoin(big_buffer, added_lines);
	free(big_buffer);
	return (buffer);

}


static char	*get_one_line_at_a_time(char *big_buffer, int fd)
{
	char	*baby_buffer;
	int		bytes_down;
	static int	count = 1;

	bytes_down = 1;


	baby_buffer = (char *)calloc((BUFFER_SIZE + 1), sizeof(char));
	if (baby_buffer == NULL)
		return (NULL);

	while (bytes_down > 0)
	{
		bytes_down = read(fd, baby_buffer, BUFFER_SIZE);
		if (bytes_down == -1)
		{
			free(baby_buffer);
			return (NULL);
		}
		big_buffer = append_next_line(big_buffer, baby_buffer);
		if (strchr(big_buffer, '\n'))
			break;
	}
	free(baby_buffer);
	return (big_buffer);
}





char	*get_next_line(int fd)
{
	char	*line;
	static char	*big_buffer;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);

	if (!big_buffer)
		big_buffer = calloc(1, sizeof(char));

	if (!strchr(big_buffer, '\n'))
		big_buffer = get_one_line_at_a_time(big_buffer, fd);

	if (!big_buffer)
	{
		free(big_buffer);
		return (NULL);
	}

	line = extract_line(big_buffer);
	big_buffer = get_remaining(big_buffer);
	
	return (line);
}



int main(void)
{
	char *line;
	int	fd;
	int count;

	count = 0;
	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("ERROR opening the file");
		return (1);
	}
	while (1)
	{

		line = get_next_line(fd);
		if (line == NULL)
			break ;
		count++;
		//printf(" Line[%d]: %s\n", count, line);
		free(line);
		line = NULL;
	}
		close(fd);
		return (0);
}




/*
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#ifndef BUFFER_SIZE 
#define BUFFER_SIZE 50
#endif


int ends_with_newline(char *str) {
    if (str == NULL || *str == '\0') {
        // Handle null or empty string
        return 0;
    }

    // Find the end of the string
    while (*str != '\0') {
        str++;
    }

    // Check if the last character is a newline
    if (*(str - 1) == '\n') {
        return 1;
    } else {
        return 0;
    }
}


// void is_newl(char *buffer)
// {
//     while (*buffer && *buffer != '\0')
//     {
//         if (*buffer == '\n')
//         {
//             //printf("#");
//             //return (1);
//             *buffer = '\\';
//         }
//         //printf("%c", *buffer);
//         buffer++;
//     }
//     //return (0);
// }


char    *read_line(int fd, char *buffer)
{
    int		bytes_down;

    bytes_down = 0;

	bytes_down = read(fd, buffer, BUFFER_SIZE);
    // if (is_newl(big_buffer) == 1)
    //     printf("biq");
    // else if (is_newl(big_buffer) == 0)
    //     printf("booq");
    //WRONG

    if (bytes_down < 0)
    {
        //printf("read failed, returned -1\n");
        return NULL;
    }

    if (bytes_down == 0)
    {
        //printf("read sent out 0 ;end of file\n");
        return NULL;
    }
	buffer[bytes_down] = '\0';

    return (buffer);

}

char    *get_next_line(int fd)
{
    char	*line;
	static char buffer[BUFFER_SIZE + 1];
	char	*thing;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
    {
        //printf("fd false or sizeofbuffer 0 or neg\n");
		return (NULL);
    }
    //if (!strchr(buffer, '\n'))
	line = read_line(fd, buffer);
	thing = strchr(buffer, '\n');
	if (thing != NULL)
	{
		//*thing = '\0';
		printf("%s", thing);
	}
	
	return (line);
}

int main(void)
{
	char *line;
	int	fd;
	
	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
	{
		//printf("ERROR opening the file");
		return (1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		
		line = NULL;
	}
		close(fd);
		return (0);
}
*/