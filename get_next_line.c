/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jintan <jintan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 22:08:57 by jintan            #+#    #+#             */
/*   Updated: 2023/05/09 16:19:52 by jintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Declaring the library header */
#include "get_next_line.h"

/*
Reminder that the static declaration just means that the function is only
visible within the scope of this source file.
Also note that when a string is 'NULL', the pointer is not pointing to a 
valid memory location. (Could happen if the string is not properly 
allocated)

Purpose: 
Iterates through a string of characters, searching for the first occurence of
the newline character

Input:
str: A pointer to the string

Output:
1) If the newline character has been found, return the index of the newline 
character in the string
2) If not (meaning no newline character is found), return -1
*/
static int	ft_find_newline(char *str)
{
	unsigned int	i;

	i = 0;
	if (str == NULL)
	{
		return (-1);
	}
	while (str[i] != '\n' && str[i] != '\0')
	{
		i++;
	}
	if (str[i] == '\0')
	{
		return (-1);
	}
	return (i);
}

/*
Purpose: 
Create a new line from the given buffer up to the newline character.

Input: 
buffer: A pointer to the character buffer containing the original string.
index: The index of the newline character ('\n') in the buffer.

Output: 
A pointer to the newly allocated character string containing the line.

Explanation:
1) The function allocates memory for a new character string with the length 
of 'index' + 2 (for the newline character and the null-terminator).
2) It then copies characters from the input buffer to the newly created line, 
stopping at the newline character.
3) The newline character and null-terminator are added to the end of the new 
line.
4) The pointer to the new line is returned.
*/
static	char	*ft_create_line_from_buffer(char *buffer, int index)
{
	char	*line;
	int		i;

	line = (char *)malloc((index + 2) * sizeof(char));
	if (line == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\n';
	line[i + 1] = '\0';
	return (line);
}

/*
Purpose: 
To calculate a line of text from a given buffer of characters.

Input:
static_buffer: A pointer to a static buffer of characters (presumably
containing one or more lines of text)

Output:
line: A pointer to the newly allocated string that contains a single
line of text from the input buffer (up to and including the first newline 
character), or NULL if the input buffer is empty or does not contain a
newline character

Explanation:
1) The function first checks if the input buffer is empty. 
If it is, the function returns NULL.
2) The function then calls a helper function, ft_find_newline, 
to find the index of the first newline character in the input buffer. 
3) If there is no newline character, or if the newline character is at the 
end of the buffer, 
4) The function copies the entire buffer to a new string using ft_strdup and
returns it.
5) If there is a newline character at a position other than the end of 
the buffer,
the function calls another helper function, ft_create_line_from_buffer, 
to copy the characters in the input buffer up to and including the 
newline character to a new string and returns it.
*/

static	char	*ft_calculate_line(char *static_buffer)
{
	char	*line;
	int		index;

	if (ft_strlen(static_buffer) <= 0)
	{
		return (NULL);
	}
	index = ft_find_newline(static_buffer);
	if (index == -1 || index == ((int)ft_strlen(static_buffer) - 1))
	{
		line = ft_strdup(static_buffer);
		return (line);
	}
	line = ft_create_line_from_buffer(static_buffer, index);
	return (line);
}

/*
Purpose: 
To create a new buffer of characters by removing the first 
line from the input buffer.

Input:
remaining_buffer: A pointer to a static buffer of characters 
(presumably containing one or more lines of text)

Output:
A pointer to a newly allocated string that contains the remaining 
lines of text from the input buffer (after the first newline 
character), or NULL if the input buffer is
empty or contain only one line of text

Explanation:
1) The function first checks if the input buffer is NULL. 
If it is, the function returns NULL.
2) If the input buffer is not NULL, the function calculates the 
length of the buffer 
using the ft_strlen() function and assigns it to the variable buffer_length.
3) The function then calls a helper function, ft_find_newline, 
to find the index of the 
first newline character in the input buffer. If there is no newline character, 
or if the newline character is at the end of the buffer, 
the function frees the input buffer using the free() function and returns NULL.
4) If there is a newline character at a position other than the end 
of the buffer, 
the function calls another helper function, ft_substr, 
to create a new buffer that contains the characters in the input buffer 
after the first line (i.e., after the newline character).
5) The function returns the newly allocated buffer.

*/
static	char	*ft_calculate_buffer(char	*remaining_buffer)
{
	int				newline_index;
	unsigned int	buffer_length;

	if (remaining_buffer == NULL)
	{
		return (NULL);
	}
	buffer_length = ft_strlen(remaining_buffer);
	newline_index = ft_find_newline(remaining_buffer);
	if (newline_index == -1 || ((buffer_length - newline_index) == 1))
	{
		free(remaining_buffer);
		return (NULL);
	}
	remaining_buffer = ft_substr(remaining_buffer, (newline_index + 1), \
			(buffer_length - newline_index - 1));
	return (remaining_buffer);
}

/*
Purpose: 
Read text from a file descriptor and returns a single line of text from the
file each time it is called

Input:
fd: file descriptor (An integer file descriptors) representing the file to 
read

Output:
line: A pointer to the newly allocated string that contains a single line
of text from the inpuit file or NULL if the end of file has been reached
or an error occurs

Explanation:
1) The function first checks if the BUFFER_SIZE is greater than 0 and the 
   file descriptor is valid (i.e., greater than or equal to 0). 
2) If either of these conditions is false, the function returns NULL.
3) The function then allocates memory for a buffer of size (BUFFER_SIZE + 1) 
   using the malloc() function. The "+1" is to account for the null-terminator 
   at the end of the string.
4) If the allocation of memory fails, the function returns NULL.
5) The function then enters a loop to read the file one BUFFER_SIZE chunk 
	at a time 
   until it reaches the end of the file or a newline character is found in 
   the buffer.
6) Within the loop, the read() function is used to read BUFFER_SIZE bytes 
	from the 
   file descriptor into the buffer. If read() returns a value less than or 
   equal to 0, 
   the loop is broken.
7) The function then adds a null-terminator to the end of the buffer and 
	joins the 
   contents of the buffer with the static buffer using ft_strjoin(). 
8) The function ft_find_newline() is used to check if a newline character is 
   present in the combined buffer.
9) Once a newline character is found, the function calculates a line of text 
   from the static buffer and returns a pointer to the newly allocated string. 
10) The static buffer is updated using ft_calculate_buffer() to remove the 
	line of text that has already been returned.
11) The function frees the buffer memory using free() and returns a pointer to 
    the newly allocated string.
*/
char	*get_next_line(int fd)
{
	char		*read_buffer;
	char		*line;
	int			bytes_read;
	static char	*static_buffer;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	read_buffer = malloc(BUFFER_SIZE + 1);
	if (!read_buffer)
		return (NULL);
	bytes_read = 1;
	while (ft_find_newline(static_buffer) == -1)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		read_buffer[bytes_read] = '\0';
		static_buffer = ft_strjoin(static_buffer, read_buffer);
	}
	free(read_buffer);
	if (bytes_read == -1)
		return (NULL);
	line = ft_calculate_line(static_buffer);
	static_buffer = ft_calculate_buffer(static_buffer);
	return (line);
}
