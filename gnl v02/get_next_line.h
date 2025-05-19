/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:55:23 by mefische          #+#    #+#             */
/*   Updated: 2025/05/19 13:19:36 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>//open
# include <stdlib.h>//malloc
# include <stdio.h>//printf

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

// Main function
char	*get_next_line(int fd);

// Utility functions
size_t	ft_strlen(const char *s);
int		ft_strchr(const char *s, int c);
char	*ft_strdup(char *s, char *line);
char	*ft_strjoin(char *s1, char *s2);

#endif