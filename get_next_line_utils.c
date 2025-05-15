/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:55:29 by mefische          #+#    #+#             */
/*   Updated: 2025/05/13 12:27:36 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Calculates length of string
size_t	ft_strlen(const char *s)
{
    size_t len;

	len = 0;
    while (s && s[len])
		len++;
    return len;
}

// Locates first occurrence of character in string
char	*ft_strchr(const char *s, int c)
{
    if (!s)
		return NULL;
    while (*s) {
        if (*s == (char)c)
            return (1);
        s++;
    }
    return (NULL);
}

// Creates duplicate of string
char *ft_strdup(const char *s)
{
    char *dup;
    size_t len;
    size_t i;

    if (!s) return NULL;
    
    len = ft_strlen(s);
    dup = malloc(len + 1);
    if (!dup) return NULL;
    
    i = 0;
    while (s[i]) {
        dup[i] = s[i];
        i++;
    }
    dup[i] = '\0';
    return dup;
}

// Concatenates two strings
char *ft_strjoin(char *s1, char *s2)
{
    char *join;
    size_t len1;
    size_t len2;
    size_t i;

    if (!s1 && !s2)
		return NULL;
    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    join = malloc(len1 + len2 + 1); //malloc entao tenho que dar free depois
    if (!join)
		return NULL;
    i = 0;
    while (s1 && *s1)
        join[i++] = *s1++;
    while (s2 && *s2)
        join[i++] = *s2++;
    join[i] = '\0';
    return (join);
}

// Extracts substring from string
char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *sub;
    size_t i;
    size_t str_len;

    if (!s) return NULL;
    
    str_len = ft_strlen(s);
    if (start >= str_len)
        return ft_strdup("");
    
    if (len > str_len - start)
        len = str_len - start;
    
    sub = malloc(len + 1);
    if (!sub) return NULL;
    
    i = 0;
    while (i < len && s[start + i]) {
        sub[i] = s[start + i];
        i++;
    }
    sub[i] = '\0';
    return sub;
}