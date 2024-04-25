/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jintan <jintan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 22:09:14 by jintan            #+#    #+#             */
/*   Updated: 2023/05/09 16:24:22 by jintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Declaring the library header */
#include "get_next_line.h"

/* Notes, most of the functions here are obtained from LIBFT */

/*
Purpose: 
Counting the length of the string

Input:
str: A pointer to a string

Output:
i: The counter (length of the string)
*/

size_t	ft_strlen(const char *str)
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

char	*ft_strjoin(char const *s1, char const *s2)
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
Just to create a new string that is a duplicate of the input string

Input:
str: The pointer to the string

Output:
dup_str : returns the duplicated string

Explanation:
The function first determines the length of the input string using 
the ft_strlen() function and assigns it to the variable len.
The function then allocates memory for a new string of size (len + 1) 
using the malloc() function. The "+1" is to account for the 
null-terminator at the end of the string.
If the allocation of memory fails, the function returns NULL.
If the allocation succeeds, the function then copies the contents of 
the input string to the new string character by character using 
a while loop. The loop iterates until it reaches the null-terminator 
at the end of the input string.
Finally, the function adds a null-terminator to the end of the new 
string and returns a pointer to the newly allocated string.
*/

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*dup_str;

	len = ft_strlen(str);
	dup_str = malloc((len + 1) * sizeof(char));
	if (dup_str == NULL)
	{
		free(dup_str);
		return (NULL);
	}
	len = 0;
	while (str[len])
	{
		dup_str[len] = str[len];
		len++;
	}
	dup_str[len] = '\0';
	return (dup_str);
}

/*
Function: 
Allocates with malloc(3) and returns a substring from the string 's'.
The substring begins at index 'start' and is of maximum size 'len'.

Input:
s: The string from which to create the substring.
start: The start index of the substring in the string 's'.
len: The maximum length of the substring

Output:
The substring (pointer to the newly allocated string that containes the 
extracted substring)
NULL if the allocation fails

Explanation:
1) The first if statement checks whether the string given is NULL or not
2) The next if statement checks whether the starting parameter is greater
or equal to the length of the string 's'. If it is, the function will
return a new empty string created by calling the ft_strdup function
3) The next if statement checks if the 'len' parameter is greater than
the remaining length of the string 's' after the 'start' index.
If it is, the variable is set to the remaining length
4) The next if statement hecks if the memory allocation of the substring 
pointer has been done successfully.
5) We will then copy the len characters from the s string, starting at
index 'start' into the substr_pt string. (memcpy)
6) End the string with the null terminator and return the newly created
string
*/

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	j;
	char	*result;
	size_t	str_length;

	j = 0;
	str_length = ft_strlen((char *)str);
	if (str == NULL)
		return (NULL);
	if (len == 0 || start >= str_length || len > (str_length - start))
		return (NULL);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (result == NULL)
	{
		free(result);
		return (NULL);
	}
	while (j < len)
	{
		result[j] = str[start];
		start++;
		j++;
	}
	result[j] = '\0';
	free((char *)str);
	return (result);
}
