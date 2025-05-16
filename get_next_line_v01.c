/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_v01.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:46:48 by mefische          #+#    #+#             */
/*   Updated: 2025/05/16 16:44:14 by mefische         ###   ########.fr       */
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
	*buffer = 0; //preciso inicializar o buffer
	while(!ft_strchr(buffer, '\n') && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (NULL);
		buffer[bytes] = '\0';
		stash = ft_strjoin(stash, buffer); //preciso criar temp ou dou free na funcao?
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
	while(stash[len] && stash[len] != '\n') //como vou lidar com o \0 no final?
		len++;
	if (stash[len] == '\n')
		len++;
	line = malloc ((len + 1) * sizeof (char)); //PRECISO DAR FREE DA LINE
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
	int		len;

	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	len = ft_strlen(line);
	if (!stash[len]) // nada depois da linha
	{
		free(stash);
		return (NULL);
	}
	new_stash = ft_strdup(stash, line); //copy after /n to new stash, tem MALLOC
	free (stash);
	stash = NULL;
	return (new_stash);
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

int	main()
{
	int		fd;
	char	*line;
	
	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error: Could not open text.txt\n");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}