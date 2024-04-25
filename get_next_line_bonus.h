/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jintan <jintan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 22:24:01 by jintan            #+#    #+#             */
/*   Updated: 2023/05/09 16:31:13 by jintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Defining the preprocessor directive */
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

/* Libraries that are allowed to be used */
# include <stdlib.h>
# include <unistd.h>

/* Defining the buffer size (Default) */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

/* Declared Function in get_next_line_utils_bonus.c */
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
char	*ft_get_line(char *str);
char	*ft_new_str(char *str);
char	*ft_read_str(int fd, char *left_str);
char	*get_next_line(int fd);

/* Marks the end of a conditional block of code */
#endif
