/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_v01.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:46:48 by mefische          #+#    #+#             */
/*   Updated: 2025/05/19 14:24:18 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *stash)
{
	char	*buffer;
	int		bytes;

	bytes = 1;
	buffer = malloc ((BUFFER_SIZE + 1) * sizeof (char));
	if (!buffer)
		return (NULL);
	*buffer = 0;
	while (!ft_strchr(buffer, '\n') && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			buffer = NULL;
			return (NULL);
		}
		buffer[bytes] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (!stash)
			return (NULL);
	}
	free(buffer);
	buffer = NULL;
	return (stash);
}

char	*get_line(char *stash)
{
	char	*line;
	int		len;
	int		i;

	line = NULL;
	len = 0;
	if (!stash || !*stash)
		return (NULL);
	while (stash[len] && stash[len] != '\n')
		len++;
	if (stash[len] == '\n')
		len++;
	line = malloc ((len + 1) * sizeof (char));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*update_stash(char *stash, char *line)
{
	char	*new_stash;

	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	new_stash = ft_strdup(stash, line);
	return(new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_line(fd, stash);
	if (!stash)
		return (NULL);
	line = get_line(stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = update_stash(stash, line);
	return (line);
}

/* int	main(void)
{
	int		fd1;
	char	*line;

	fd1 = open("text.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error: Could not open text.txt\n");
		return (1);
	}
	while ((line = get_next_line(fd1)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd1);
	return (0);
} */

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*line1;
	char	*line2;

	fd1 = open("text.txt", O_RDONLY);
	fd2 = open("text2.txt", O_RDONLY);
	if (fd1 == -1 || fd1 == -1)
	{
		printf("Error: Could not open file\n");
		return (1);
	}
	while ((line1 = get_next_line(fd1)) != NULL || (line2 = get_next_line(fd2)) != NULL)
	{
		printf("1: %s", line1);
		printf("2: %s", line2);
		free(line1);
		free(line2);
	}
	close(fd1);
	close(fd2);
	return (0);
}
