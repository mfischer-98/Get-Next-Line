/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:55:29 by mefische          #+#    #+#             */
/*   Updated: 2025/05/16 16:45:30 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Calculates length of string
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

// Alterei para devolver um inteiro e ficar mais facil
int	ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == (char)c)
			return (1);
		s++;
	}
	return (0);
}

// Creates duplicate of string
char *ft_strdup(char *s, char *line) //adicionei line para ver len
{
	char	*dup;
	size_t	len;
	size_t	i;

	if (!s) 
		return NULL;
	len = ft_strlen(s) - ft_strlen(line);
	dup = malloc (len + 1);
	if (!dup)
		return NULL;
	i = 0;
	len = ft_strlen(line);
	while (s[len + i])
	{
		dup[i] = s[len + i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

// Concatenates two strings
char *ft_strjoin(char *s1, char *s2)
{
	char	*join;
	size_t	len1;
	size_t	len2;
	size_t	i;

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
	if (s1)
	{
		free(s1);
		s1 = NULL;
	}
	return (join);
}
