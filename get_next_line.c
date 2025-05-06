/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:55:25 by mefische          #+#    #+#             */
/*   Updated: 2025/05/06 17:51:19 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	*str;
	char		*line;
	int			size;
	int			i;
	int			len;

	i = 0;
	len = 0;
	str = malloc ((BUFFER_SIZE + 1) * sizeof (char));
	size = read(fd, str, BUFFER_SIZE);
	if (read(fd, str, BUFFER_SIZE) == 0)
		return (0);
/* if (read(fd, str, BUFFER_SIZE) < 0)
	return (-1); */
	//read until \n
	line = malloc((size + 1) * sizeof (char));
	while (str[i])
	{
		line[i] = str[i];
		if (str[i] == '\n')
			break;
		i++;
	}
	free(str); //tenho que fazer?
	//printf("String: %s\n\n", str);
	len = ft_strlen(str) - ft_strlen(line); //if line < str
	str = ft_substr(str, ++i, len);
	//printf("i: %d\n", i);
	//printf("Len: %d\n", len);
	//printf("String2: %s\n\n", str);
	return (line);
}

int	main()
{
	int	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	while (fd < 5) 
	{
		printf("%s", get_next_line(fd));
		printf("\n\n");
		fd++;
	}
	get_next_line(fd);
	close(fd);
	if (close(fd) == -1)
		return(1);
	return (0);
}