/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jintan <jintan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 22:09:28 by jintan            #+#    #+#             */
/*   Updated: 2023/05/01 22:09:28 by jintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Defining the preprocessor directive */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/* Libraries that are allowed to be used */
# include <stdlib.h>
# include <unistd.h>

/* Defining the buffer size (Default) */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

/* Declared Function in get_next_line_utils.c */
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strrchr(char *str, int c);
char	*ft_strdup(const char *str);
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	*get_next_line(int fd);

#endif