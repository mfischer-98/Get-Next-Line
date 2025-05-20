/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:55:29 by mefische          #+#    #+#             */
/*   Updated: 2025/05/19 13:23:16 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
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

// Duplico a stash e passo ate o \n para a line
char	*ft_strndup(char *s, size_t line_len) //adicionei line para ver len
{
	char	*dup;
	size_t	len;
	size_t	i;

	if (!s)
		return (NULL);
	len = ft_strlen(s) - line_len;
	dup = malloc (len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	len = ft_strlen(line);
	while (s[len + i])
	{
		dup[i] = s[len + i];
		i++;
	}
	dup[i] = '\0';
	free(s);
	s = NULL;
	return (dup);
}

// Juntar o buffer a stash: STASH, BUFFER
char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	size_t	i;
	size_t	j;

	i = 0;
	join = malloc(ft_strlen(s2) + ft_strlen(s1) + 1);
	if (!join)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
		join[i++] = s2[j++];
	join[i] = '\0';
	free(s1);
	s1 = NULL;
	return (join);
}
