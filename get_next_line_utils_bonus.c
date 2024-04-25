/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jintan <jintan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 22:24:16 by jintan            #+#    #+#             */
/*   Updated: 2023/05/09 16:29:23 by jintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Declaring the library header */
#include "get_next_line_bonus.h"

/* 
Notes, most of the functions here are obtained from LIBFT and a few 
function that I have created 
*/

/*
Purpose: 
Counting the length of the string

Input:
str: A pointer to a string

Output:
i: The counter (length of the string)
*/

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
	{
		return (0);
	}
	while (str[i])
	{
		i++;
	}
	return (i);
}

/*
Purpose:
Takes two pointer to the input string (s1 and s2) and concatenates them
to form a new string

Input:
s1: A pointer to the first string
s2: A pointer to the second string

Output:
str: The concatenated string

Explanation:
Basically just concatenate two strings together
*/

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	len1;
	size_t	len2;
	char	*str;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc((ft_strlen(s1)+ ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
	{
		free(str);
		return (NULL);
	}
	while (i++ < len1)
	{
		str[i - 1] = s1[i - 1];
	}
	i = 0;
	while (i++ < len2)
		str[i - 1 + len1] = s2[i - 1];
	str[i - 1 + len1] = '\0';
	free((char *)s1);
	return (str);
}

/*
Purpose: 
String Character
Used to search for the first occurrence of a specified character in a given
string.

Input:
Takes two arguments 
Characters are represented as integers, so the function can be called 
with a character literal as the second argument.
const char s: a pointer to the string to be searched
int c: the character to be searched for

Output:
Returns a pointer to the first occurence of the character 'c' in the string
's' or NULL if the character is not found

Explanation:
We iterate through each character in the string, compares each character to
the character,c and return a pointer to the current character if they match.
If no character c is found, return NULL (0)
*/

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		return (0);
	}
	if (c == '\0')
	{
		return ((char *)&s[ft_strlen(s)]);
	}
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	return (0);
}

/*
Purpose:
To extract a single line of text from a null-terminated string.

Input:
str: A pointer to a null-terminated string that contains one or 
more lines of text.

Output:
new_line: A pointer to a newly allocated string that contains a
single line of text from the input string, including the newline 
character at the end of the 
line, or NULL if the input string is empty.

Explanation:
1) The function first checks if the input string is empty. 
If it is, the function returns NULL.
2) The function then iterates through the input string character 
by character
until it encounters a newline character or the null-terminator at the 
end of the string. 
It keeps track of the number of characters it has processed in the 
variable index.
3) The function then allocates memory for a new string of size (index+2) 
using the malloc() function. 
The "+2" is to account for the newline character and the null-terminator at 
the end of the string.
4) If the allocation of memory fails, the function returns NULL.
5) The function then iterates through the input string character by 
character again, 
copying each character to the new string until it encounters a 
newline character 
or the null-terminator at the end of the string.
6) If the function encountered a newline character in the input string, 
it copies the newline character to the new string and increments the 
variable index.
7) Finally, the function adds a null-terminator to the end of the new 
string and returns a pointer to the newly allocated string.
*/

char	*ft_get_line(char *str)
{
	int		index;
	char	*new_line;

	index = 0;
	if (!str[index])
		return (NULL);
	while (str[index] && str[index] != '\n')
		index++;
	new_line = (char *)malloc(sizeof(char) * (index + 2));
	if (!new_line)
		return (NULL);
	index = 0;
	while (str[index] && str[index] != '\n')
	{
		new_line[index] = str[index];
		index++;
	}
	if (str[index] == '\n')
	{
		new_line[index] = str[index];
		index++;
	}
	new_line[index] = '\0';
	return (new_line);
}

/*
Purpose:
To create a new string by removing the first line from a null-terminated string.

Input:
ori_str: A pointer to a null-terminated string that contains one or more 
lines of text.

Output:
str: A pointer to a newly allocated string that contains the remaining 
lines of text from the input string (after the first newline character), 
or NULL if the input string is empty.

Explanation:
1) The function first iterates through the input string character by 
character until it encounters a newline character or the null-terminator 
at the end of the string. It keeps track of the number of characters 
it has processed in the variable i.
2) If the function did not encounter a newline character in the input string, 
it frees the memory allocated for the input string using the free() function 
and returns NULL.
3) If the function did encounter a newline character in the input string, 
it allocates memory for a new string of size (ft_strlen(ori_str) - i + 1) 
using the malloc() function. This new string will contain the remaining lines 
of text from the input string (after the first newline character), 
without the newline character itself.
4) If the allocation of memory fails, the function returns NULL.
5) The function then iterates through the input string character by character 
again, copying each character after the newline character to the new string.
6) Finally, the function adds a null-terminator to the end of the new string, 
frees the memory allocated for the original input string using the free() 
function, and returns a pointer to the newly allocated string.
*/

char	*ft_new_str(char *ori_str)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	while (ori_str[i] && ori_str[i] != '\n')
	{
		i++;
	}
	if (!ori_str[i])
	{
		free(ori_str);
		return (NULL);
	}
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(ori_str) - i + 1));
	if (new_str == NULL)
		return (NULL);
	i++;
	j = 0;
	while (ori_str[i])
		new_str[j++] = ori_str[i++];
	new_str[j] = '\0';
	free(ori_str);
	return (new_str);
}
