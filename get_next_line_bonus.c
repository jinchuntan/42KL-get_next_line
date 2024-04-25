/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jintan <jintan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 22:23:46 by jintan            #+#    #+#             */
/*   Updated: 2023/05/09 16:21:13 by jintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Declaring the library header */
#include "get_next_line_bonus.h"

/*
Purpose:
To read text from a file descriptor and append it to an existing string.

Input:
fd: An integer file descriptor fd that represents the file or stream to read 
from.
str: A pointer to a null-terminated string str that contains the existing text

Output:
str: A pointer to a newly allocated string that contains the existing text 
appended with the text read from the file descriptor, 
or NULL if the read operation failed.

Explanation:
1) The function first allocates memory for a buffer of size 
BUFFER_SIZE + 1 using the malloc() function.
2) The function then reads text from the file descriptor fd into the buffer 
using the read() function. If the read operation fails, the function returns 
NULL.
3) The function then null-terminates the buffer by setting the character 
after the last byte read to '\0'.
4) The function then appends the text in the buffer to the existing text 
str using the ft_strjoin() function, which concatenates two strings and 
returns a newly allocated string containing the concatenated result.
5) The function repeats steps 2-4 until either the end of file has been 
reached or a newline character is found in the text read from the file 
descriptor.
6) Finally, the function frees the memory allocated for the buffer and 
returns a pointer to the newly allocated string that contains the 
existing text appended with the text read from the file descriptor.

*/
char	*ft_read_str(int fd, char *str)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
	{
		return (NULL);
	}
	read_bytes = 1;
	while (!ft_strchr(str, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

/*
Purpose:
Read text from a file descriptor and extract the single line of text from
the read text

Input:
fd: An integer file descriptor which represents the file or stream to
read from

Output:
line: Pointer to the newly allocated string that contain a single line of
text

Explanation:
1) The function first checks if the input file descriptor fd is negative 
or the BUFFER_SIZE macro is less than or equal to zero. 
If either of these conditions is true, the function returns NULL.
2) The function then reads text from the file descriptor fd and 
stores it in a static array of strings str at the index corresponding to fd. 
The ft_read_str function is used to read text from the file 
descriptor fd and append it to the existing text in str[fd] if there is any. 
If the read operation fails or the end of file has been reached, 
str[fd] is set to NULL and the function returns NULL.
3) The function then extracts a single line of text from str[fd] using the 
ft_get_line function. 
If str[fd] is empty or contains no newline character, ft_get_line returns NULL. 
Otherwise, it returns a pointer to a newly allocated string that contains 
the line of text, 
including the newline character at the end of the line.
4) The function then removes the extracted line of text from str[fd] 
using the ft_new_str function. 
The ft_new_str function creates a new string that contains the remaining 
text in str[fd]
after the extracted line. The remaining text is stored in str[fd] again.
5) Finally, the function returns the pointer to the newly allocated 
string containing the extracted line of text.

*/
char	*get_next_line(int fd)
{
	char		*line;
	static char	*str[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (0);
	}
	str[fd] = ft_read_str(fd, str[fd]);
	if (str[fd] == NULL)
	{
		return (NULL);
	}
	line = ft_get_line(str[fd]);
	str[fd] = ft_new_str(str[fd]);
	return (line);
}
