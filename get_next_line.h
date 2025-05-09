/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:55:23 by mefische          #+#    #+#             */
/*   Updated: 2025/05/09 16:52:57 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

# include <unistd.h>
# include <fcntl.h> //open
# include <stdlib.h> //malloc
# include <stdio.h> //printf
# include <limits.h> //sizemax

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char const *s2); //para juntar buffer a stash
size_t	ft_strlen(const char *s);
char	*ft_strcdup(char *s, char c);
char	*ft_substr(char *s, unsigned int start, size_t len);
 
#endif