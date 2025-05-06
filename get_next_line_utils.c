/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:55:29 by mefische          #+#    #+#             */
/*   Updated: 2025/05/06 17:34:19 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	l;

	l = 0;
	while (s[l])
	{
		l++;
	}
	return (l);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	i = 0;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > (ft_strlen(s + start)))
		len = ft_strlen(s + start);
	sub = ft_calloc(len + 1, sizeof(char));
	if (!sub)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	return (sub);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;

/* 	if (nmemb != 0 && size > SIZE_MAX / nmemb)
		return (NULL); */
	mem = malloc(nmemb * size);
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, nmemb * size);
	return (mem);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;
	int		l;

	i = 0;
	l = ft_strlen(s);
	str = malloc ((l + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (i < l)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*s2;

	i = 0;
	s2 = s;
	while (i < n)
	{
		s2[i] = '\0';
		i++;
	}
}